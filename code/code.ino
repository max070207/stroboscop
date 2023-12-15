#include <FastLED.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#define POT_PIN_1 A0
#define POT_PIN_2 A1
#define POT_MAX_ANGLE 270.0

//OPTIONS
#define DEBUG true
//END OPTIONS
//Servo myServo;
//#define NUM_LEDS 8
#define LED_PIN 10
//CRGB leds[NUM_LEDS];
//#define LED_MAX_NUM 255.0
#define MOTOR_PIN 9
SoftwareSerial mySerial(3, 2); // RX, TX

void setup() {
  Serial.println("Welcome!");
  pinMode(POT_PIN_1, INPUT);
  pinMode(POT_PIN_2, INPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  //LEDS.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
  //LEDS.setBrightness(100);
  Serial.begin(115200);
  while(!Serial);
  Serial.println("hi, i'm a blutooth module");
  mySerial.begin(115200);
  while(!mySerial);
}

void loop() {
  servoprivod();
  //ledring();
  /*if(mySerial.available())
    Serial.write(mySerial.read());
  if(Serial.available())
    mySerial.write(Serial.read());*/
}

void servoprivod(){
  int rotation1 = analogRead(POT_PIN_1);
  int rotation2 = analogRead(POT_PIN_2);
  Serial.print("Потенциометр 1:");
  Serial.println(rotation1);
  Serial.print("Потенциометр 2:");
  Serial.println(rotation2);
  /*int angle = int(rotation1 / 1024.0 * POT_MAX_ANGLE);
  angle = constrain(angle, 0, 180);
  myServo.write(angle);*/
  analogWrite(MOTOR_PIN, map(rotation1, 0, 1023, 150, 0));
  analogWrite(LED_PIN, map(rotation2, 0, 1023, 0, 255));
  delay(1000);
}
/*
void ledring(){
  for(int i=0; i < 9; i++){
    leds[i] = CHSV(0, 0, 0);
    FastLED.show();
    delay(1);
  }
  delay(100);
  for(int i=0; i < 9; i++){
    leds[i] = CHSV(192, 255, 128);
    FastLED.show();
    delay(1);
  }
  delay(100);
}*/
