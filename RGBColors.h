#ifndef RGB_Colors
#define RGB_Colors

#include <Arduino.h>
#include "RGBConverter.h"
 

// ---------- UNIVERSAL COLOR

class Color {
  private:
    double h = 0;
    double s = 0;
    double v = 0;
    byte r = 0;
    byte g = 0;
    byte b = 0;
    byte w = 0;

    void computeHsv();
    void computeRgb();
  
  public:
    Color(double hue, double saturation, double value);
    Color(byte red, byte green, byte blue, byte white);

    double getHue();
    double getSaturation();
    double getValue();
    byte getRed();
    byte getGreen();
    byte getBlue();
    byte getWhite();


    void setHsv(double hue, double saturation, double value);
    void setRgbw(byte red, byte green, byte blue, byte white);
    void setHue(double hue);
    void setSaturation(double saturation);
    void setValue(double value);
    void setRed(byte red);
    void setGreen(byte green);
    void setBlue(byte blue);
    void setWhite(byte white);

    Color copy();
    String hsvToString();
    String rgbToString();
    String rgbwToString();
};


// ---------- SPECIFIC COLOR SCHEMES

class HSV {
  public:
    double h;
    double s;
    double v;

    HSV(double hue=0, double saturation=0, double value=0);
    HSV copy();
    String toString();
};

class HSL {
  public:
    double h;
    double s;
    double l;

    HSL(double hue=0, double saturation=0, double lightness=0);
    HSL copy();
    String toString();
};

class RGB {
  public:
    byte r;
    byte g;
    byte b;

    RGB(byte red=0, byte green=0, byte blue=0);
    RGB copy();
    HSL toHsl();
    RGB fromHsl(HSL hsl);
    HSV toHsv();
    RGB fromHsv(HSV hsv);
    String toString();
};

class RGBW: RGB {
  public:
    byte r;
    byte g;
    byte b;
    byte w;
  
    RGBW(byte red=0, byte green=0, byte blue=0, byte white=0);
    RGBW copy();
    HSL toHsl();
    RGBW fromHsl(HSL hsl);
    HSV toHsv();
    RGBW fromHsv(HSV hsv);
    RGB toRGB();
    String toString();
};

// ---------- Constants
const RGB RGB_OFF = RGB(0, 0, 0);
const RGB RGB_WHITE = RGB(255, 255, 255);
const RGB RGB_RED = RGB(255, 0, 0);
const RGB RGB_ORANGE = RGB(255, 127, 0);
const RGB RGB_YELLOW = RGB(255, 255, 0);
const RGB RGB_LIME = RGB(127, 255, 0);
const RGB RGB_GREEN = (0, 255, 0);
const RGB RGB_SPRING_GREEN = RGB(0, 255, 127);
const RGB RGB_CYAN = RGB(0, 255, 255);
const RGB RGB_DEEP_SKY_BLUE = RGB(0, 127, 255);
const RGB RGB_BLUE = (0, 0, 255);
const RGB RGB_PURPLE =	RGB(127, 0, 225);
const RGB RGB_MAGENTA =	RGB(255, 0, 255);
const RGB RGB_DEEP_PINK =	RGB(255, 0, 127);

const RGBW RGBW_OFF = RGBW(0, 0, 0, 0);
const RGBW RGBW_WHITE = RGBW(0, 0, 0, 255);
const RGBW RGBW_RED = RGBW(255, 0, 0, 0);
const RGBW RGBW_ORANGE = RGBW(255, 127, 0, 0);
const RGBW RGBW_YELLOW = RGBW(255, 255, 0, 0);
const RGBW RGBW_LIME = RGBW(127, 255, 0, 0);
const RGBW RGBW_GREEN = (0, 255, 0, 0);
const RGBW RGBW_SPRING_GREEN = RGBW(0, 255, 127, 0);
const RGBW RGBW_CYAN = RGBW(0, 255, 255, 0);
const RGBW RGBW_DEEP_SKY_BLUE = RGBW(0, 127, 255, 0);
const RGBW RGBW_BLUE = (0, 0, 255, 0);
const RGBW RGBW_PURPLE =	RGBW(127, 0, 225, 0);
const RGBW RGBW_MAGENTA =	RGBW(255, 0, 255, 0);
const RGBW RGBW_DEEP_PINK =	RGBW(255, 0, 127, 0);


#endif