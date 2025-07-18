/************* Android + Bluetooth + Arduino pick and place robot ****************

************** PIN CONFIGURATION *****************

  PIN      CONECTION

  9      BASE ARM SERVO
  10     MIDDLE ARM SERVO
  11     GRIPPER ARM SERVO
  RX     TX (HC05 BLUETOOTH MODULE)
  TX     RX (HC05 BLUETOOTH MODULE)

******************** CONTROLS *******************

  BUTTON         FUNCTION

  UP           BASE ARM (MOVE ON ONE SIDE)
  DOWN         BASE ARM (MOVE ON ANOTHER SIDE)
  RIGHT        MIDDLE ARM (MOVE ON ONE SIDE)
  LEFT         MIDDLE ARM (MOVE ON ANOTHER SIDE)
  TRIANGLE     GRIPPER OPEN
  CROSS        GRIPPER CLOSE

************************************************
*/

#include <Servo.h>

//DEFINATIONS FOR CONTROLLER
char RX_RAW;                             //VARIABLE FOR RECEIVED VALUES FROM ARDUINO BLUETOOTH CONTROLLER APP

//DEFINATIONS FOR SERVO
#define SERVO_BASE_PIN      9            //DEFINE BASE ARM SERVO TO DIGITAL PIN 9
#define SERVO_MIDDLE_PIN    10           //DEFINE MIDDLE ARM SERVO TO DIGITAL PIN 10 
#define SERVO_GRIPPER_PIN   11           //DEFINE GRIPPER ARM SERVO TO DIGITAL PIN 11 
Servo SERVO_BASE;                        //DEFINE BASE ARM SERVO
Servo SERVO_MIDDLE;                      //DEFINE MIDDLE ARM SERVO
Servo SERVO_GRIPPER;                     //DEFINE GRIPPER ARM SERVO
int BASE_VALUE = 0, MIDDLE_VALUE = 0, GRIPPER_VALUE = 0;

void setup()
{
  Serial.begin(9600);                         //SERIAL COMMUNICATION FOR HC05, BAUDRATE = 9600

  SERVO_BASE.attach(SERVO_BASE_PIN);          //SET BASE ARM SERVO TO DIGITAL PIN 9
  SERVO_MIDDLE.attach(SERVO_MIDDLE_PIN);      //SET MIDDLE ARM SERVO TO DIGITAL PIN 10
  SERVO_GRIPPER.attach(SERVO_GRIPPER_PIN);    //SET GRIPPER ARM SERVO TO DIGITAL PIN 11

  //SET TO INITIAL POSITION
  SERVO_BASE.write(BASE_VALUE);
  SERVO_MIDDLE.write(MIDDLE_VALUE);
  SERVO_GRIPPER.write(GRIPPER_VALUE);
}

void controller()
{
  if (Serial.available())
  {
    RX_RAW = Serial.read();                         //RECEIVING VALUES FROM ARDUINO BLUETOOTH CONTROLLER APP
    switch (RX_RAW)
    {
      case '1' ://LEFT BUTTON
        BASE_VALUE--;
        if (BASE_VALUE < 0)
          BASE_VALUE = 0;
        SERVO_BASE.write(BASE_VALUE);           //TO MOVE BASE ARM ON ONE SIDE
        delay(15);
        break;
      case '2' ://UP BUTTON
        MIDDLE_VALUE++;
        if (MIDDLE_VALUE > 180)
          MIDDLE_VALUE = 180;
        SERVO_MIDDLE.write(MIDDLE_VALUE);      //TO MOVE MIDDLE ARM ON ONE SIDE
        delay(15);
        break;
      case '3' ://RIGHT BUTTON
        BASE_VALUE++;
        if (BASE_VALUE > 180)
          BASE_VALUE = 180;
        SERVO_BASE.write(BASE_VALUE);          //TO MOVE BASE ARM ON ANOTHER SIDE
        delay(15);
        break;
      case '4' ://DOWN
        MIDDLE_VALUE--;
        if (MIDDLE_VALUE < 0)
          MIDDLE_VALUE = 0;
        SERVO_MIDDLE.write(MIDDLE_VALUE);     //TO MOVE MIDDLE ARM ON ANOTHER SIDE
        delay(15);
        break;
      case '5' ://SELECT BUTTON
        break;
      case '6' ://START BUTTON
        break;
      case 's' ://SQUARE BUTTON
        break;
      case 't' ://TRIANGLE BUTTON
        GRIPPER_VALUE = 0;
        SERVO_GRIPPER.write(GRIPPER_VALUE);                   //TO OPEN GRIPPER
        delay(15);
        break;
      case 'x' ://CROSS BUTTON
        GRIPPER_VALUE = 180;
        SERVO_GRIPPER.write(GRIPPER_VALUE);                 //TO CLOSE GRIPPER
        delay(15);
        break;
      case 'c' ://CIRCLE BUTTON
        break;
      default :
        SERVO_BASE.write(BASE_VALUE);           
        SERVO_MIDDLE.write(MIDDLE_VALUE);     
        SERVO_GRIPPER.write(GRIPPER_VALUE);                 
        break;
    }

  }
}

void loop()
{
  controller();
}
