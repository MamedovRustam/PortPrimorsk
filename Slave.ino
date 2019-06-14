#include "FastLED.h"
#define NUM_LEDS 18
CRGB leds[NUM_LEDS];
#define PIN 6

void setup()
{
  FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}

void loop() {
  RunningLights(0xff, 0xff, 0x00, 200);
}

void RunningLights(byte red, byte green, byte blue, int WaveDelay) {
  int Position = 0;

  for (int j = 0; j < NUM_LEDS * 1; j++)
  {
    Position++;
    for (int i = 0; i < NUM_LEDS; i++) {
      setPixel(i, ((sin(i + Position) * 127 + 130) / 255)*red,
               ((sin(i + Position) * 127 + 130) / 255)*green,
               ((sin(i + Position) * 127 + 130) / 255)*blue);
    }

    FastLED.show();
    delay(65);
  }
}

void setPixel(int Pixel, byte red, byte green, byte blue)
{
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;

}

void setAll(byte red, byte green, byte blue) {
  for (int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  FastLED.show();
}
