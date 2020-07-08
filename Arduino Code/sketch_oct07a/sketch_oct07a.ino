#include <AFMotor.h>
AF_DCMotor right_motor(1, MOTOR12_8KHZ);
AF_DCMotor left_motor(2, MOTOR12_8KHZ);

void setup() {
  Serial.begin(9600);
  right_motor.setSpeed(250);
  left_motor.setSpeed(250);
}
String voice;

//-----------------------------------------------------------------------// 
void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
  if (voice.length() > 0) {
    Serial.println(voice);
       if(voice == "stop") 
       {
        right_motor.run (RELEASE);
        left_motor.run (RELEASE);
        delay(500);
       }  
       if(voice == "forward") 
       {
        right_motor.run (FORWARD);
        left_motor.run (FORWARD);
        delay(500);
       }  
        if(voice == "backward") 
       {
        right_motor.run (BACKWARD);
        left_motor.run (BACKWARD);
        delay(500);
       }  
        if(voice == "right") 
       {
        right_motor.run (RELEASE);
        left_motor.run (FORWARD);
        delay(500);
       }  
        if(voice == "left") 
       {
        right_motor.run (FORWARD);
        left_motor.run (RELEASE);
        delay(500);
       }  
  }  
  } 
