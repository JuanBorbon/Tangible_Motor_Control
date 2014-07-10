#include <AFMotor.h>    // http://www.ladyada.net/make/mshield/download.html
                            // https://github.com/adafruit/AccelStepper
#include <Servo.h>

    AF_Stepper motor1(200, 2); // try 400 if 200 does not work
    AF_Stepper motor2(200, 1);
    int spos = 0;
    Servo myservo;
    int byte_in;
    int change = 50;
    char nextMsg;
     
    void setup() {
     
        /* in RPM */
        motor1.setSpeed(100);
        motor2.setSpeed(100);
        myservo.attach(10);
        Serial.begin(9600);
        digitalWrite(13, HIGH); // turn on LED to indicate program has started
    }
     
    void loop() {
     
        if (Serial.available() > 0) {
            byte_in = Serial.read();

            if (byte_in != -1) { // if anything was received...
                decodeMessage(byte_in);
            }
        }

    }
     
    void decodeMessage(int msg) {
      
        int faktor = 1;
        // check command type and command value
        // read bits and move appropriate stepper
        if (msg == 119) {
            // Bit 1 = High   DOWN (1)
            motor1.step(faktor, FORWARD, SINGLE);
        }
        if (msg == 115) {
            // Bit 2 = High   UP (2)
            motor1.step(faktor, BACKWARD, SINGLE);
        }
        if (msg == 97) {
            // Bit 3 = High   LEFT (4)
            motor2.step(faktor, FORWARD, SINGLE);
        }
        if (msg == 100) {
            // Bit 4 = High   RIGHT (8)
            motor2.step(faktor, BACKWARD, SINGLE);
        }
        if (msg == 50){
            myservo.write(spos+change);
            delay(900);
            change = -1*change;
        }

        sendConfirm();
    }
     
    void sendConfirm() {
     
        if (Serial.available() > 0) {
            Serial.flush();
        }
        Serial.print(9999);
        Serial.println();
    }
