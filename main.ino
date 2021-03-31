#include <Adafruit_NeoPixel.h>

#define LED_PIN  5
#define PIN_SENSOR 16
#define LED_COUNT  12
#define BRIGHTNESS 10

Adafruit_NeoPixel ring(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int i = 0;
int lastButton = 0;
int km = 0;

void setup() {
  Serial.begin(9600);
  pinMode (PIN_SENSOR, INPUT);
  ring.begin();
  ring.setBrightness(BRIGHTNESS);
  ring.clear();
}

void loop() {
  if(digitalRead(PIN_SENSOR) == LOW) {
    if(lastButton == HIGH) {
      i++;
      Serial.println("HIGH");
      Serial.println(i);
      delay(750);
    }
    lastButton = LOW;
  } else {
    lastButton = HIGH;
  }
  
  km = 0;
  km = i*0.2;
  
  switch (i) {
  case 0:
    ring.clear();
    break;
  case 1:
    light(i);
    break;
  case 2:
    light(i);
    break;
  case 3:
    light(i);
    break;
  case 4:
    light(i);
    break;
  case 5:
    light(i);
    break;
  case 6:
    light(i);
    break;
  case 7:
    light(i);
    break;
  case 8:
    light(i);
    break;
  case 9:
    light(i);
    break;
  case 10:
    light(i);
    break;
  case 11:
    light(i);
    break;
  case 12:
    light(i);
    i = 0;
    break;
  default:
    i=0;
    light(12);
    break;
    }
}

void light(int i){
  for(int j = 0;j<i;j++){
    ring.setPixelColor(j, ring.Color(255,0,0));
    ring.show();
  }
}
