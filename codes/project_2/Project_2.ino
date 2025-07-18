/************* Voice-controlled home automation ****************

************** PIN CONFIGURATION *****************

  PIN      CONECTION

  9      REALY FOR LIGHT
  10     RELAY FOR FAN
  RX     TX (HC05 BLUETOOTH MODULE)
  TX     RX (HC05 BLUETOOTH MODULE)

******************** CONTROLS *******************

  VOICE           FUNCTION

  LIGHT ON        LIGHT WILL ON
  LIGHT OFF       LIGHT WILL OFF
  FAN ON          FAN WILL ON 
  FAN OFF         FAN WILL OFF
  ON BOTH         FAN AND LIGHT WILL ON
  OFF BOTH        FAN AND LIGHT WILL OFF

************************************************
*/

//DEFINATION FOR LIGHT AND FAN
#define LIGHT_RELAY_PIN 9                         //DEFINE LIGHT RELAY PIN TO DIGITAL PIN 9
#define FAN_RELAY_PIN   10                        //DEFINE FAN RELAY PIN TO DIGITAL PIN 10

String RX_RAW;

void setup()
{
  Serial.begin(9600);                             //SERIAL COMMUNICATION FOR HC05, BAUDRATE = 9600

  pinMode(LIGHT_RELAY_PIN, OUTPUT);               //SET LIGHT RELAY PIN AS OUTPUT
  pinMode(FAN_RELAY_PIN, OUTPUT);                 //SET FAN RELAY PIN AS OUTPUT 
}

void controller()
{
  if(Serial.available())
  {
    RX_RAW = Serial.readString();                 //RECEIVING VALUE FROM ARDUINO BLUETOOTH VOICE CONTROLLER APP

    if(RX_RAW == "light on")                      //TO ON LIGHT
        digitalWrite(LIGHT_RELAY_PIN,HIGH);

    if(RX_RAW == "light off")                     //TO OFF LIGHT
        digitalWrite(LIGHT_RELAY_PIN,LOW);

    if(RX_RAW == "fan on")                        //TO ON FAN
        digitalWrite(FAN_RELAY_PIN,HIGH);

    if(RX_RAW == "fan off")                       //TO OFF FAN
        digitalWrite(FAN_RELAY_PIN,LOW);
    
    if(RX_RAW == "both on")                       //TO ON BOTH FAN AND LIGHT
    {
        digitalWrite(LIGHT_RELAY_PIN,HIGH);
        digitalWrite(FAN_RELAY_PIN,HIGH);
    }
    if(RX_RAW == "both off")                      //TO OFF BOTH FAN AND LIGHT
    {
        digitalWrite(LIGHT_RELAY_PIN,LOW);
        digitalWrite(FAN_RELAY_PIN,LOW);
    }
  }
}

void loop() 
{
  controller();    
}
