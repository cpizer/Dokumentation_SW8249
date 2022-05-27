#include <Arduino.h>
#include <Servo.h>
#include <RingBuf.h>
#include <PID_v1.h>

#define SPEED_GAUGE_PULSE_INPUT_PIN 7
#define SPEED_GAUGE_CONTROLLER_PIN 6
#define SPEED_PULSE_PIN 2
#define RPM_GAUGE_PWM_PIN 5
#define RPM_GAUGE_DIR_PIN 4
#define RPM_PULSE_PIN 3
#define POTI_INPUT_PIN A0

#define RPM_GAUGE_MAX_PWM 50L

#define SPEED_PULSE_BUFFER_MAX 19
#define PULSE_WIDTH_TO_MEASURED_SPEED 1700

#define SPEED_GAUGE_PULSES_BUFFER_SIZE 10
#define PULSE_WIDTH_TO_SPEED 1873500L

#define PULSE_WITH_TO_RPM 30000L

#define CONTROLLER_UPDATE_INTERVAL 20L
#define SPEED_CALCULATION_INTERVAL 200L
#define SPEED_OUTPUT_INTERVAL 500L
#define SPEED_GAUGE_PULSES_INTEGRATION_TIME 500L

//speed gauge related variables
uint32_t last_controller_update = 0;
uint32_t last_speed_calculation = 0;

bool was_speed_gauge_pulse_pin_high = false;
double speed_kph_displayed_f = 0.0;
double speed_to_display_f = 0.0;
double value_to_write_f = 0.0;

Servo speed_gauge_controller;
RingBuf<uint32_t, SPEED_GAUGE_PULSES_BUFFER_SIZE> speed_gauge_pulses;
uint32_t pop_buffer;
//                INPUT_MEASUREMENT       OUTPUT             TARGET_VALUE         kp   ki    kd
PID speedGaugePID(&speed_kph_displayed_f, &value_to_write_f, &speed_to_display_f, 0.2, 0.55, 0.01, DIRECT);

//rev counter related variables
uint32_t last_engine_pulse = 0;

volatile bool rpm_pulse_detected = false;

uint32_t rpm_to_display = 0;

//speed counter related variables
uint32_t last_speed_pulse = 0;

volatile uint8_t speed_pulse_buffer = 0;
volatile bool speed_pulse_buffer_limit_reached = false;

double displayed_speed(RingBuf<uint32_t, SPEED_GAUGE_PULSES_BUFFER_SIZE> *pulses_buffer){
  uint32_t diff_buffer = 0;
  uint32_t no_values_considered = 0;
  uint32_t oldest_value = millis()>SPEED_GAUGE_PULSES_INTEGRATION_TIME?millis()-SPEED_GAUGE_PULSES_INTEGRATION_TIME:0;
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

void rpm_pulse_isr(){
  rpm_pulse_detected = true;
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
  pinMode(SPEED_GAUGE_PULSE_INPUT_PIN, INPUT);
  pinMode(POTI_INPUT_PIN, INPUT);
  pinMode(RPM_GAUGE_DIR_PIN, OUTPUT);
  pinMode(RPM_GAUGE_PWM_PIN, OUTPUT);
  pinMode(RPM_PULSE_PIN, INPUT_PULLUP);
  pinMode(SPEED_PULSE_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(RPM_PULSE_PIN), rpm_pulse_isr, RISING);
  attachInterrupt(digitalPinToInterrupt(SPEED_PULSE_PIN), speed_pulse_isr, RISING);
  speed_gauge_controller.attach(SPEED_GAUGE_CONTROLLER_PIN);
  Serial.begin(115200);
  //turn the PID on
  speedGaugePID.SetMode(AUTOMATIC);
}

void loop() {
  //SPEED GAUGE RELATED CODE
  //acquisition of the speed gauge's rotational speed
  if (digitalRead(SPEED_GAUGE_PULSE_INPUT_PIN) == HIGH && !was_speed_gauge_pulse_pin_high){
    if (speed_gauge_pulses.isFull())  speed_gauge_pulses.pop(pop_buffer);
    speed_gauge_pulses.push(millis());
    was_speed_gauge_pulse_pin_high = true;
  }else if(digitalRead(SPEED_GAUGE_PULSE_INPUT_PIN) == LOW){
    was_speed_gauge_pulse_pin_high = false;
  }
  //controller updates
  if (last_speed_calculation + SPEED_CALCULATION_INTERVAL < millis()){
    speed_kph_displayed_f = displayed_speed(&speed_gauge_pulses);
    speedGaugePID.Compute();
  }
  if (last_controller_update + CONTROLLER_UPDATE_INTERVAL < millis()){
    last_controller_update = millis();
    //speed_to_display_f = (double) map((long) analogRead(POTI_INPUT_PIN), 0L, 1023L, 0L, 100L);
    speed_gauge_controller.write((speed_to_display_f < 10)?40:map((long) value_to_write_f, 0, 150, 40, 150));
  }

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

  //REV COUNTER RELATED CODE
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
}
