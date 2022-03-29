//#define trigger 5
//#define echo 4
#define Relay 6

#define upperTrigger 9
#define upperEcho 8

#define buzzer 10
#define led 2

#define touchSensor 4


float time=0,distance=0;
bool ultrasonicEnabled = true;
void setup()
{
Serial.begin(9600);
 pinMode(touchSensor, INPUT);
// pinMode(trigger,OUTPUT);
// pinMode(echo,INPUT);
 pinMode(upperTrigger,OUTPUT);
 pinMode(upperEcho,INPUT);
 pinMode(buzzer,OUTPUT);
 pinMode(led,OUTPUT);
 pinMode(Relay,OUTPUT);
}
 bool buzzerBool=true;
 bool glassPresent=false;
void loop()
{
  digitalWrite(touchSensor,LOW);
  delay(500);
//    measure_distance();
    if (digitalRead(touchSensor) == HIGH)
    {
      glassPresent = true;
      digitalWrite(touchSensor,LOW);
    }
    else
     {
//      digitalWrite(touchSensor,LOW);
      glassPresent = false;
     }
    // Serial.print(distance);
     if(glassPresent)
     {
        int waterDistance = checkWaterLevel();
        if(waterDistance >= 5){
          digitalWrite(Relay,HIGH);
          buzzerBool = true;
           Serial.print(buzzerBool);
           Serial.print("inside both if\n");
        }else{
          digitalWrite(Relay,LOW);
          if(buzzerBool==true){
            buzzerBool=false;
            toggleBuzzerAndLight();
            Serial.print(buzzerBool);
            Serial.print("inside one if one else\n");
          }
        }
     }
     else
     {
        digitalWrite(Relay,LOW);
     }
   
}
void toggleBuzzerAndLight(){
  digitalWrite(buzzer,HIGH);
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led,LOW);
  digitalWrite(buzzer,LOW);
}
int checkWaterLevel(){
  digitalWrite(upperTrigger,LOW);
 delayMicroseconds(2);
 digitalWrite(upperTrigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(upperTrigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(upperEcho,HIGH);
 
 int waterDistance=time*200/20000;
 return waterDistance;
}
//void measure_distance()
//{
// digitalWrite(trigger,LOW);
// delayMicroseconds(2);
// digitalWrite(trigger,HIGH);
// delayMicroseconds(10);
// digitalWrite(trigger,LOW);
// delayMicroseconds(2);
// time=pulseIn(echo,HIGH);
// 
// distance=time*200/20000;
//// Serial.println(distance);
//}
