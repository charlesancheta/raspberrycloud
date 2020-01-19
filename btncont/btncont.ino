#include <AccelStepper.h>
#define HALFSTEP 8

#define STEPPER_MAX_SPEED 3000
#define STEPPER_FAST STEPPER_MAX_SPEED
#define STEPPER_SLOW (STEPPER_MAX_SPEED/2)

// Motor pin definitions
#define PIN_MOTOR1_IN1  8     // IN1 on the ULN2003 driver 1
#define PIN_MOTOR1_IN2  9     // IN2 on the ULN2003 driver 1
#define PIN_MOTOR1_IN3  10    // IN3 on the ULN2003 driver 1
#define PIN_MOTOR1_IN4  11    // IN4 on the ULN2003 driver 1

#define PIN_MOTOR2_IN1  4     // IN1 on the ULN2003 driver 2
#define PIN_MOTOR2_IN2  5     // IN2 on the ULN2003 driver 2
#define PIN_MOTOR2_IN3  6    // IN3 on the ULN2003 driver 2
#define PIN_MOTOR2_IN4  7    // IN4 on the ULN2003 driver 2

AccelStepper stepperX(HALFSTEP, PIN_MOTOR1_IN1, PIN_MOTOR1_IN3, PIN_MOTOR1_IN2, PIN_MOTOR1_IN4);
AccelStepper stepperY(HALFSTEP, PIN_MOTOR2_IN1, PIN_MOTOR2_IN3, PIN_MOTOR2_IN2, PIN_MOTOR2_IN4);


void setup() {
  for (int i = 22; i < 26; i++)
  {
    digitalWrite(i, HIGH);
  }
  
  
  stepperX.setMaxSpeed(STEPPER_MAX_SPEED);
  stepperX.setAcceleration(300.0);
  stepperX.setSpeed(STEPPER_FAST);
      stepperX.enableOutputs();
      
  stepperY.setMaxSpeed(STEPPER_MAX_SPEED);
  stepperY.setAcceleration(300.0);
  stepperY.setSpeed(STEPPER_FAST);
      stepperY.enableOutputs();
//  stepperX.disableOutputs();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(22) == LOW) {
    stepperX.move(10);
    stepperX.run();
  } 
  if (digitalRead(23) == LOW) {
    stepperX.move(10);
    stepperX.run();
  }

  if (digitalRead(24) == LOW) {
    stepperY.move(10);
    stepperY.run();
  } 
  if (digitalRead(25) == LOW) {
    stepperX.move(-10);
    stepperY.run();
  }
  
}
