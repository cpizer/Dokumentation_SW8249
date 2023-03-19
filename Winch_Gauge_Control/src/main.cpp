#include <Arduino.h>
#include <Servo.h>
//#include <RingBuf.h>

//#define SERIAL_OUTPUT

#define SPEED_GAUGE_PIN 6
#define SPEED_PULSE_PIN 2
#define RPM_GAUGE_PWM_PIN 5
#define RPM_GAUGE_DIR_PIN 4
#define RPM_PULSE_PIN 3

#define RPM_GAUGE_MAX_PWM 50L
#define RPM_PULSE_BUFFER_MAX 5UL
#define SPEED_PULSE_BUFFER_MAX 76
#define PULSE_WIDTH_TO_MEASURED_SPEED 6800
#define PULSE_WIDTH_TO_RPM 3000UL
#define SPEEDOMETER_UPDATE_INTERVAL 20L
#define SPEEDOMETER_SPEED_CHANGE_LIMIT 7

//speed gauge related variables
uint32_t last_speedometer_update = 0;
int last_servo_angle = 0;
uint8_t speed_gauge_min_angle = 143;
uint8_t speed_gauge_max_angle = 14;
uint32_t last_speed_calculation = 0;

double speed_to_display_f = 0.0;
double value_to_write_f = 0.0;

Servo speed_gauge_servo;
//RingBuf<uint32_t, SPEED_GAUGE_PULSES_BUFFER_SIZE> speed_gauge_pulses;
//uint32_t pop_buffer;

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
  pinMode(SPEED_GAUGE_PIN, OUTPUT);
  pinMode(RPM_GAUGE_DIR_PIN, OUTPUT);
  pinMode(RPM_GAUGE_PWM_PIN, OUTPUT);
  pinMode(RPM_PULSE_PIN, INPUT_PULLUP);
  pinMode(SPEED_PULSE_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(RPM_PULSE_PIN), rpm_pulse_isr, RISING);
  attachInterrupt(digitalPinToInterrupt(SPEED_PULSE_PIN), speed_pulse_isr, RISING);
  speed_gauge_servo.attach(SPEED_GAUGE_PIN);
  #ifdef SERIAL_OUTPUT
  Serial.begin(115200);
  #endif
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
    rpm_to_display = (RPM_PULSE_BUFFER_MAX * PULSE_WIDTH_TO_RPM / rpm_pulse_period);
    set_rpm_to_gauge(rpm_to_display);
    #ifdef SERIAL_OUTPUT
    Serial.print("RPM: ");
    Serial.println(rpm_to_display);
    #endif
  }
  if (last_rpm_pulse + 600 < millis()){
    set_rpm_to_gauge(0);
    #ifdef SERIAL_OUTPUT
    Serial.println("RPM: 0");
    #endif
  }
}
