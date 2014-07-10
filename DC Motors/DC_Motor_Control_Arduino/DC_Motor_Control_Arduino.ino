// OWI robotic arm control 
// By Juan Borbon and the Children's Museum of Houston 

#include <AFMotor.h> // This call the library the tells the arduino how to use the motor shield

int wait = 50;         // duration of motor activation for every command
AF_DCMotor motor1(1);  // Tells the arduino where the motors are attached and what they are named
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);       // Sets up the serial communication. This allows
                            // the arduino to talk to your computer                            
}

void loop(){
  int msg = Serial.read(); // reads message from computer and stores it
  
  if (msg == 1){              // reads message
    motor1.setSpeed(100);     // sets the speed of each motor
    motor1.run(FORWARD);      // tells the motor to move forward
    delay(wait);              // lets to motor run for a while
    motor1.setSpeed(0);       // stops the motor
    msg = 0;                  // resets the message
  }
  else if (msg == 2){
    motor1.setSpeed(100);
    motor1.run(BACKWARD);
    delay(wait);
    motor1.setSpeed(0);
    msg = 0;
  }  
  else if (msg == 3){
    motor2.setSpeed(100);
    motor2.run(FORWARD);
    delay(wait);
    motor2.setSpeed(0);
    msg = 0;
  }
  else if (msg == 4){
    motor2.setSpeed(100);
    motor2.run(BACKWARD);
    delay(wait);
    motor2.setSpeed(0);
    msg = 0;
  }  

  else if (msg == 5){
    motor3.setSpeed(100);
    motor3.run(FORWARD);
    delay(wait);
    motor3.setSpeed(0);
    msg = 0;
  }
  else if (msg == 6){
    motor3.setSpeed(100);
    motor3.run(BACKWARD);
    delay(wait);
    motor3.setSpeed(0);
    msg = 0;
  }  
  
  else if (msg == 7){
    motor4.setSpeed(100);
    motor4.run(FORWARD);
    delay(wait);
    motor4.setSpeed(0);
    msg = 0;
  }
  else if (msg == 8){
    motor4.setSpeed(100);
    motor4.run(BACKWARD);
    delay(wait);
    motor4.setSpeed(0);
    msg = 0;
  }  
  if (Serial.available() > 0) {
            Serial.flush();
  }
}
  

