#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(9,10); // RX,TX

//Initializing Motors Pin
AF_DCMotor motor1(1,MOTOR12_1KHZ);
AF_DCMotor motor2(2,MOTOR12_1KHZ);
AF_DCMotor motor3(3,MOTOR34_1KHZ);
AF_DCMotor motor4(4,MOTOR34_1KHZ);

void setup()
{
//Assigning the Baud rate to the Bluetooth Module
  bluetoothSerial.begin(9600);  
}

char command;

void loop() {
  if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();

//Initializing the Motors to Stop
    Stop(); 
    
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
    }
  }
}

void forward()
{

//Set the Motors Maximum Speed
//Rotating the Motors Clockwise

  motor1.setSpeed(255); 
  motor1.run(FORWARD);  
  motor2.setSpeed(255); 
  motor2.run(FORWARD);  
  motor3.setSpeed(255); 
  motor3.run(FORWARD);  
  motor4.setSpeed(255); 
  motor4.run(FORWARD);  
}

void back()
{
  
//Set the Motors Maximum Speed
//Rotating the Motor Anti-Clockwise

  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
}

void left()
{

//Set the Motors Maximum Speed
//Rotating the Motor Anti-Clockwise

  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  
//Rotating the Motor Clockwise
  motor3.setSpeed(255); 
  motor3.run(FORWARD); 
  motor4.setSpeed(255);
  motor4.run(FORWARD);  
}

void right()
{

//Set the Motors Maximum Speed
//Rotating the Motor Clockwise
  motor1.setSpeed(255); 
  motor1.run(FORWARD);  
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
  
//Rotating the Motor Anti-Clockwise
   
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
}

void Stop()
{

//Set the Motors Speed to Zero

  motor1.setSpeed(0);  
  motor1.run(RELEASE); 
  motor2.setSpeed(0);  
  motor2.run(RELEASE); 
  motor3.setSpeed(0);  
  motor3.run(RELEASE); 
  motor4.setSpeed(0);  
  motor4.run(RELEASE);
}
