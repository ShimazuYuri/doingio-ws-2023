#include <mozzi_midi.h>
#include <Oscil.h>
#include <EventDelay.h>
#include <ADSR.h>
#include <tables/SAW2048_int8.h>  // sine table for
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

#define PIN 12
#define DELAYVAL 500

Adafruit_NeoPixel pixels(10, PIN, NEO_GRB + NEO_KHZ800);


Oscil<SAW2048_NUM_CELLS, AUDIO_RATE> aSaw(SAW2048_DATA);
ADSR<AUDIO_RATE, AUDIO_RATE> envelope;  //エンベロープをかけるためのクラス
unsigned int Dur, Atk, Dec, Sus, Rel;   //ADSRの長さを入れておく変数








const int SENSOR1 = 5;
const int SENSOR2 = 6;
const int SENSOR3 = 7;
const int SENSOR4 = 8;
const int SENSOR5 = 4;
const int SENSOR0 = A0;

unsigned int timer = 0;
unsigned int NUMPIXELS = 10;



void setup() {
  startMozzi(64);
  aSaw.setFreq(440);
  Atk = 1;
  Dec = 80;
  Sus = 10;
  Rel = 20;
  envelope.setADLevels(255, 128);
  envelope.setTimes(Atk, Dec, Sus, Rel);




  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);
  pinMode(SENSOR3, INPUT);
  pinMode(SENSOR4, INPUT);
  pinMode(SENSOR5, INPUT);

  // #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  //   clock_prescale_set(clock_div_1);
  // #endif

  pixels.begin();
}

void lightAll(bool onoff) {
  pixels.clear();
  for (int i = 0; i < 5; i++) {  // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    if (onoff) {
      pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    } else {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
  }
    pixels.show();
}


void updateControl() {
  auto sensor0 = analogRead(SENSOR0);
  bool breath = sensor0 <1000;
  bool sensor1 = digitalRead(SENSOR1) == HIGH;
  bool sensor2 = digitalRead(SENSOR2) == HIGH;
  bool sensor3 = digitalRead(SENSOR3) == HIGH;
  bool sensor4 = digitalRead(SENSOR4) == HIGH;
  bool sensor5 = digitalRead(SENSOR5) == HIGH;

  //  if (timer > 50) {
  //     pixels.clear();
  //       for (int i = 0; i < NUMPIXELS; i++) {  // For each pixel...

  //         // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
  //         // Here we're using a moderately bright green color:
  //         pixels.setPixelColor(i, pixels.Color(0, 150, 0));

  //         pixels.show();
  //       }
  //     timer = 0;
  //     NUMPIXELS = (NUMPIXELS+1)%11;
  //     }

  //   timer++;
  //   Serial.println(timer,NUMPIXELS);

  // lightAll(false);

  //ボタンが押されたらエンベロープのnoteOnを呼ぶ
  if (sensor1 && !sensor2 && !sensor3 && !sensor4 && !sensor5 && breath) {
    aSaw.setFreq(mtof(58));
    envelope.noteOn();
    // lightAll(true);
  }
  if (sensor1 && sensor2 && sensor3 && !sensor4 && !sensor5 && breath) {
    aSaw.setFreq(mtof(60));
    envelope.noteOn();
  }
  if (sensor1 && !sensor2 && sensor3 && !sensor4 && !sensor5 && breath) {
    aSaw.setFreq(mtof(62));
    envelope.noteOn();
  }
  if (!sensor1 && sensor2 && sensor3 && !sensor4 && !sensor5 && breath) {
    aSaw.setFreq(mtof(63));
    envelope.noteOn();
  }

  if (sensor1 && !sensor2 && !sensor3 && sensor4 && !sensor5 && breath) {
    aSaw.setFreq(mtof(65));
    envelope.noteOn();
  }
  if (sensor1 && sensor2 && sensor3 && sensor4 && !sensor5 && breath) {
    aSaw.setFreq(mtof(67));
    envelope.noteOn();
  }
  if (sensor1 && !sensor2 && sensor3 && sensor4 && !sensor5 && breath) {
    aSaw.setFreq(mtof(69));
    envelope.noteOn();
  }
  if (!sensor1 && sensor2 && sensor3 && sensor4 && !sensor5 && breath) {
    aSaw.setFreq(mtof(70));
    envelope.noteOn();
  }




  if (sensor1 && !sensor2 && !sensor3 && !sensor4 && sensor5 && breath) {
    aSaw.setFreq(mtof(51));
    envelope.noteOn();
  }
  if (sensor1 && sensor2 && sensor3 && !sensor4 && sensor5 && breath) {
    aSaw.setFreq(mtof(53));
    envelope.noteOn();
  }
  if (sensor1 && !sensor2 && sensor3 && !sensor4 && sensor5 && breath) {
    aSaw.setFreq(mtof(55));
    envelope.noteOn();
  }
  if (!sensor1 && sensor2 && sensor3 && !sensor4 && sensor5 && breath) {
    aSaw.setFreq(mtof(57));
    envelope.noteOn();
  }
}




int updateAudio() {
  envelope.update();
  return (int)(envelope.next() * aSaw.next()) >> 8;
  //エンベロープのボリュームは0～256なので、かけてからビットシフトをする
}




void loop() {
  audioHook();
}
