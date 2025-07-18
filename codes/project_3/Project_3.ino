/************* Ultrasonic Distance meter using Arduino ****************

************** PIN CONFIGURATION *****************

  PIN      CONECTION

   2     RS (LCD DISPLAY)
   3     E  (LCD DISPLAY)
   4     D4 (LCD DISPLAY)
   5     D5 (LCD DISPLAY)
   6     D6 (LCD DISPLAY)
   7     D7 (LCD DISPLAY)
   9     TRIGGER PIN (ULTRASOUND SENSOR)
   10    ECHO PIN(ULTRASOUND SENSOR)
   
************************************************
*/

#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);            //SET INTERFACING PINS OF LCD 16x2

//DEFINATION FOR ULTRASOUND SENSOR
#define TRIGGER_PIN 9                           //DEFINE TRIGGER PIN TO DIGITAL PIN 9
#define ECHO_PIN 10                             //DEFINE ECCHO PIN TO DIGITAL PIN 10      

long TIME_TAKEN=0;                              
int DISTANCE_CM=0, DISTANCE_INCH=0;              

void setup() 
{
  lcd.begin(16, 2);                             //DEFINE LCD 16x2

  pinMode(TRIGGER_PIN,OUTPUT);                  //SET TRIGGER PIN TO OUTPUT
  pinMode(ECHO_PIN,INPUT);                      //SET ECHO PIN TO INPUT     
  
} 

void display(int a, int b)
{
  lcd.setCursor(0,0);
  lcd.print("DISTANCE: ");
  delay(10);
  lcd.print(a);
  delay(10);
  lcd.print(" CM");
  delay(10);
  
  lcd.setCursor(0,1);
  lcd.print("DISTANCE: ");
  delay(10);
  lcd.print(b);
  delay(10);
  lcd.print(" INCH");
  delay(10);
}

void ultrasonic_read()
{
  digitalWrite(TRIGGER_PIN,LOW);         //CLEAR TRIGGER PIN 
  delayMicroseconds(2);

  digitalWrite(TRIGGER_PIN,HIGH);        //SET TRIGGER PIN FOR 10 SEC
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN,LOW);         
 
  TIME_TAKEN = pulseIn(ECHO_PIN, HIGH);  // READ THE ECHO PIN, STORE THE SOUND WAVE TRAVEL TIME IN MICROSECONDS
  
  DISTANCE_CM =  TIME_TAKEN * 0.034/2;   //CALCULATING DISTANCE IN CENTIMETER 
  DISTANCE_INCH = TIME_TAKEN * 0.0133/2; //CALCULATING DISTANCE IN INCHES

  display(DISTANCE_CM,DISTANCE_INCH);    //DISPLAY BOTH VALUES ON LCD DISPLAY
}

void loop() 
{
  ultrasonic_read();
}
