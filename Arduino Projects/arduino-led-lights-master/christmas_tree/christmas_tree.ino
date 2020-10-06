#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUM_LEDS 100
     
    // Parameter 1 = number of pixels in strip
    // Parameter 2 = pin number (most are valid)
    // Parameter 3 = pixel type flags, add together as needed:
    //   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
    //   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
    //   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
    //   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_RGB + NEO_KHZ400);

        
void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  while(true) {
    for (int i = 0; i < 3; i++) {
      snow();
    }
    
    rainbow_chase();
    for (int i = 0; i < 3; i++) {
      full_rainbow_fade();
    }
  }
}

// set all LEDs to a color
void set_all(int r, int g, int b) {
  for (int i = 0; i < 100; i++) {
    strip.setPixelColor(i, r,g,b);
  }
  strip.show();
  delay(100);
}

// DIY rainbow fade based on this chart:
// http://academe.co.uk/wp-content/uploads/2012/04/451px-HSV-RGB-comparison.svg_.png
void full_rainbow_fade() {
  int r = 120;
  int g = 0;
  int b = 0;
  for (int i = 0; i < 60; i++) {
    g += 2;
    set_all(r,g,b);
  }
  for (int i = 0; i < 60; i++) {
    r -= 2;
    set_all(r,g,b);
  }
  for (int i = 0; i < 60; i++) {
    b += 2;
    set_all(r,g,b);
  }
  for (int i = 0; i < 60; i++) {
    g -= 2;
    set_all(r,g,b);
  }
  for (int i = 0; i < 60; i++) {
    r += 2;
    set_all(r,g,b);
  }
  for (int i = 0; i < 60; i++) {
    b -= 2;
    set_all(r,g,b);
  }
}

// colors based on the same chart as above, but calculated differently for the rainbow_chase
int red(int deg) {
  if (deg < 60 || deg >= 300)
    return 120;
  if (deg >= 60 && deg < 120)
    return 120 - (2*(deg-60));
  if (deg >= 240 && deg < 300)
    return 2* (deg - 240);
  return 0;
}

int green (int deg) {
  if (deg < 180 && deg >= 60)
    return 120;
  if (deg >= 180 && deg < 240)
    return 120 - (2*(deg-180));
  if (deg >= 0 && deg < 60)
    return 2* (deg);
  return 0;
}

int blue(int deg) {
  if (deg < 300 && deg >= 180)
    return 120;
  if (deg >= 300 && deg < 360)
    return 120 - (2*(deg-300));
  if (deg >= 120 && deg < 180)
    return 2* (deg - 120);
  return 0;
}

void rainbow_chase() {
  int r,g,b;
  for (int i = 0; i < 5000; i++) {
    //set_all(r,g,b);
    r = red(i%360);
    g = green(i%360);
    b = blue(i%360);
    clear_lights();
    int offset = 33 - i%33;
    for (int n = 0; n < 3; n++) {   
      strip.setPixelColor((n*33 + offset)%100, r,g,b);
    }
    strip.show();
    delay(50);
  }
}

// uses random brightness values for white to make it look like twinkling snow falling
void snow() {
  clear_lights();
  strip.show();
  int l = 100;
  int r = 100;
  while (r > 0) {
    if (l > 0)
      l -= 1;
    if (r-l > 60 || l == 0)
      r -= 1;

    clear_lights();
    for (int i = l; i < r; i++) {
      int c = random(100);
      strip.setPixelColor(i, c,c,c);
    }
    strip.show();
    delay(100);
  }
}


void clear_lights() {
  for (int i = 0; i < 100; i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
}


