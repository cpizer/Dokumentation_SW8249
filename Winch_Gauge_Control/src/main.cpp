#include <Arduino.h>
#include <Servo.h>
//#include <RingBuf.h>
//#include <PID_v1.h>

//#define SPEED_GAUGE_PULSE_INPUT_PIN 7
#define SPEED_GAUGE_CONTROLLER_PIN 6
#define SPEED_PULSE_PIN 2
#define SPEED_GAUGE_MIN_POTI_PIN A0
#define SPEED_GAUGE_MAX_POTI_PIN A1
#define RPM_GAUGE_PWM_PIN 5
#define RPM_GAUGE_DIR_PIN 4
#define RPM_PULSE_PIN 3

#define RPM_GAUGE_MAX_PWM 50L
#define RPM_PULSE_BUFFER_MAX 5UL

#define SPEED_PULSE_BUFFER_MAX 19
#define PULSE_WIDTH_TO_MEASURED_SPEED 1700

#define SPEED_GAUGE_PULSES_BUFFER_SIZE 10
#define PULSE_WIDTH_TO_SPEED 1873500L

#define PULSE_WITH_TO_RPM 3000UL

//#define CONTROLLER_UPDATE_INTERVAL 20L
#define SPEED_CALCULATION_INTERVAL 200L
#define SPEEDOMETER_UPDATE_INTERVAL 20L
#define SPEEDOMETER_SPEED_CHANGE_LIMIT 7
//#define SPEED_OUTPUT_INTERVAL 500L
//#define SPEED_GAUGE_PULSES_INTEGRATION_TIME 500L

//speed gauge related variables
//uint32_t last_controller_update = 0;
uint32_t last_speedometer_update = 0;
int last_servo_angle = 0;
uint8_t speed_gauge_min_angle = 143;
uint8_t speed_gauge_max_angle = 14;
uint32_t last_speed_calculation = 0;

//bool was_speed_gauge_pulse_pin_high = false;
//double speed_kph_displayed_f = 0.0;
double speed_to_display_f = 0.0;
double value_to_write_f = 0.0;

Servo speed_gauge_servo;
//RingBuf<uint32_t, SPEED_GAUGE_PULSES_BUFFER_SIZE> speed_gauge_pulses;
//uint32_t pop_buffer;
//                INPUT_MEASUREMENT       OUTPUT             TARGET_VALUE         kp   ki    kd
//PID speedGaugePID(&speed_kph_displayed_f, &value_to_write_f, &speed_to_display_f, 0.2, 0.55, 0.01, DIRECT);

//rev counter related variables
volatile uint8_t rpm_pulse_buffer = 0;
volatile bool rpm_pulse_buffer_limit_reached = false;
uint32_t last_rpm_pulse = 0;

uint32_t last_engine_pulse = 0;
volatile bool rpm_pulse_detected = false;
uint32_t rpm_to_display = 0;

//speed counter related variables
uint32_t last_speed_pulse = 0;

volatile uint8_t speed_pulse_buffer = 0;
volatile bool speed_pulse_buffer_limit_reached = false;

/*
void calibrate_esc(void){
  Serial.println("Calibrate ESC:");
  Serial.println("Write 150deg to ESC");
  speed_gauge_servo.write(180);
  delay(2500);
  Serial.println("Write 40deg to ESC");
  speed_gauge_servo.write(0);
  delay(2000);
}
*/

//Calculates the speed, which is currently displayed by the speed gauge, based on the pulses from the light barrier
/*
double calc_displayed_speed(RingBuf<uint32_t, SPEED_GAUGE_PULSES_BUFFER_SIZE> *pulses_buffer){
  uint32_t diff_buffer = 0;
  uint32_t no_values_considered = 0;
  uint32_t oldest_value = millis()>SPEED_GAUGE_PULSES_INTEGRATION_TIME?millis()-SPEED_GAUGE_PULSES_INTEGRATION_TIME:0; //Only relevant shortly after powering up the microcontroller
  for (int i = pulses_buffer->size()-1; i > 0; i--){
    uint32_t tmp_upper = (*pulses_buffer)[i];
    uint32_t tmp_lower = (*pulses_buffer)[i-1];
    if (tmp_lower > oldest_value){
      diff_buffer += tmp_upper - tmp_lower;
      no_values_considered++;
    }else{
      break;
    }
  }
  if (no_values_considered == 0){
    return 0;
  }else{
    uint32_t avg_pulse_width = (diff_buffer * 1000)/ no_values_considered;
    return (double) (PULSE_WIDTH_TO_SPEED / avg_pulse_width);
  }
}
*/

//Sets all output pins connected to the RPM-gauge that way, that the gauge displays the desired RPM
void set_rpm_to_gauge(uint32_t rpm_to_display){
  (rpm_to_display > 3000)?rpm_to_display=3000:0;
  if (rpm_to_display <= 1500){
    digitalWrite(RPM_GAUGE_DIR_PIN, LOW);
    int pwm_value = map(rpm_to_display, 0, 1500, RPM_GAUGE_MAX_PWM, 0);
    analogWrite(RPM_GAUGE_PWM_PIN, pwm_value);
  }else{
    digitalWrite(RPM_GAUGE_DIR_PIN, HIGH);
    int pwm_value = map(rpm_to_display, 1500, 3000, 255, 255-RPM_GAUGE_MAX_PWM);
    analogWrite(RPM_GAUGE_PWM_PIN, pwm_value);
  }
}

void set_speed_to_gauge(int speed_kph){
  if (last_speedometer_update + SPEEDOMETER_UPDATE_INTERVAL <= millis()){
    last_speedometer_update = millis();
    int desired_angle = map(speed_kph, 0, 150, speed_gauge_min_angle, speed_gauge_max_angle);
    //limit the servo's speed if required
    if (abs(desired_angle-last_servo_angle) > SPEEDOMETER_SPEED_CHANGE_LIMIT){
      if (desired_angle > last_servo_angle){
        last_servo_angle += SPEEDOMETER_SPEED_CHANGE_LIMIT;
      }else{
        last_servo_angle -= SPEEDOMETER_SPEED_CHANGE_LIMIT;
      }
    }else{
      last_servo_angle = desired_angle;
    }
    speed_gauge_servo.write(last_servo_angle);
  }
}

void rpm_pulse_isr(){
  rpm_pulse_detected = true;
  rpm_pulse_buffer++;
  if (rpm_pulse_buffer == RPM_PULSE_BUFFER_MAX){
    rpm_pulse_buffer = 0;
    rpm_pulse_buffer_limit_reached = true;
  }
}

void speed_pulse_isr(){
  speed_pulse_buffer++;
  if (speed_pulse_buffer == SPEED_PULSE_BUFFER_MAX){
    speed_pulse_buffer = 0;
    speed_pulse_buffer_limit_reached = true;
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(SPEED_GAUGE_CONTROLLER_PIN, OUTPUT);
  pinMode(SPEED_GAUGE_MIN_POTI_PIN, INPUT);
  pinMode(SPEED_GAUGE_MAX_POTI_PIN, INPUT);
  //pinMode(SPEED_GAUGE_PULSE_INPUT_PIN, INPUT);
  pinMode(RPM_GAUGE_DIR_PIN, OUTPUT);
  pinMode(RPM_GAUGE_PWM_PIN, OUTPUT);
  pinMode(RPM_PULSE_PIN, INPUT_PULLUP);
  pinMode(SPEED_PULSE_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(RPM_PULSE_PIN), rpm_pulse_isr, RISING);
  attachInterrupt(digitalPinToInterrupt(SPEED_PULSE_PIN), speed_pulse_isr, RISING);
  //speed_gauge_min_angle = map(analogRead(SPEED_GAUGE_MIN_POTI_PIN), 0, 1023, 0, 180);
  //speed_gauge_max_angle = map(analogRead(SPEED_GAUGE_MAX_POTI_PIN), 0, 1023, 0, 180);
  speed_gauge_servo.attach(SPEED_GAUGE_CONTROLLER_PIN);
  Serial.begin(115200);
  //turn the PID on
  //speedGaugePID.SetMode(AUTOMATIC);
  set_rpm_to_gauge(0);
  int i;
  for (i=0; i<50; i++){
    set_speed_to_gauge(0);
    delay(SPEEDOMETER_UPDATE_INTERVAL);
  }
  for(i=0; i<= 100; i++){
    set_rpm_to_gauge(30*i);
    set_speed_to_gauge(150);
    delay(SPEEDOMETER_UPDATE_INTERVAL);
  }
  delay(100);
  for(i=100; i>= 0; i--){
    set_rpm_to_gauge(30*i);
    set_speed_to_gauge(0);
    delay(SPEEDOMETER_UPDATE_INTERVAL);
  }
}

void loop() {
  //SPEED COUNTER RELATED CODE
  if (speed_pulse_buffer_limit_reached){
    uint32_t speed_pulse_period = millis() - last_speed_pulse;
    last_speed_pulse = millis();
    speed_pulse_buffer_limit_reached = false;
    speed_to_display_f = (double) (PULSE_WIDTH_TO_MEASURED_SPEED / speed_pulse_period);
  }
  if (last_speed_pulse + 300 < millis()){
    speed_to_display_f = 0.0;
  }
  set_speed_to_gauge((int) speed_to_display_f);

  //REV COUNTER RELATED CODE
  if (rpm_pulse_buffer_limit_reached){
    uint32_t rpm_pulse_period = millis() - last_rpm_pulse;
    last_rpm_pulse = millis();
    rpm_pulse_buffer_limit_reached = false;
    rpm_to_display = (RPM_PULSE_BUFFER_MAX * PULSE_WITH_TO_RPM / rpm_pulse_period);
    set_rpm_to_gauge(rpm_to_display);
    Serial.print("RPM: ");
    Serial.println(rpm_to_display);
  }
  if (last_rpm_pulse + 600 < millis()){
    set_rpm_to_gauge(0);
    Serial.println("RPM: 0");
  }

  /*
  if (rpm_pulse_detected){
    uint32_t engine_pulse_period = millis() - last_engine_pulse;
    last_engine_pulse = millis();
    rpm_pulse_detected = false;
    if (engine_pulse_period > 5){
      rpm_to_display = PULSE_WITH_TO_RPM / engine_pulse_period;
      set_rpm_to_gauge(rpm_to_display);
    }
    Serial.println(engine_pulse_period);
  }
  if (last_engine_pulse + 300 < millis()){
    set_rpm_to_gauge(0);
  }
  */
}
