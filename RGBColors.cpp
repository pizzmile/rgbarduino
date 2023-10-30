#include "RGBColors.h"


// ---------- UNIVERSAL COLOR SCHEME

Color::Color(double hue, double saturation, double value) {
  h = hue;
  s = saturation;
  v = value;
  w = 0;

  computeRgb();
}

Color::Color(byte red, byte green, byte blue, byte white) {
  r = red;
  g = green;
  b = blue;
  w = white;
  
  computeHsv();
}

void Color::computeRgb() {
  RGBConverter converter;
  byte rgb[3];
  converter.hsvToRgb(h, s, v, rgb);
  r = rgb[0];
  g = rgb[1];
  b = rgb[2];
  w = 0;
}

void Color::computeHsv() {
  RGBConverter converter;
  double hsv[3];
  converter.rgbToHsv(r, g, b, hsv);
  h = hsv[0]; 
  s = hsv[1]; 
  v = hsv[2];
}

double Color::getHue() {return h;}
double Color::getSaturation() {return s;}
double Color::getValue() {return v;}
byte Color::getRed() {return r;}
byte Color::getGreen() {return g;}
byte Color::getBlue() {return b;}
byte Color::getWhite() {return w;}

void Color::setHsv(double hue, double saturation, double value) {
  h = hue;
  s = saturation;
  v = value;
  computeRgb();
}

void Color::setRgbw(byte red, byte green, byte blue, byte white) {
  r = red;
  g = green;
  b = blue;
  w = white;
  computeHsv();
}

void Color::setHue(double hue) {
  h = hue;
  computeRgb();
}
void Color::setSaturation(double saturation) {
  s = saturation;
  computeRgb();
}
void Color::setValue(double value) {
  v = value;
  computeRgb();
}
void Color::setRed(byte red) {
  r = red;
  computeHsv();
}
void Color::setGreen(byte green) {
  g = green;
  computeHsv();
}
void Color::setBlue(byte blue) {
  b = blue;
  computeHsv();
}
void Color::setWhite(byte white) {
  w = white;
  computeHsv();
}

Color Color::copy() {return Color(r, g, b, w);}
String Color::hsvToString() {return "(" + (String)h + ", " + (String)s + ", " + (String)v + ")";}
String Color::rgbToString() {return "(" + (String)r + ", " + (String)g + ", " + (String)b + ")";}
String Color::rgbwToString() {return "(" + (String)r + ", " + (String)g + ", " + (String)b + ", " + (String)w + ")";}


// ---------- INDIVIDUAL COLOR SCHEMES

HSV::HSV(double hue, double saturation, double value) {
  h = hue;
  s = saturation;
  v = value;
}

HSV HSV::copy() {
  return HSV(h, s, v);
}

String HSV::toString() {
  return "(" + String(h) + ", " + String(s) + ", " + String(v) + ")";
}

HSL::HSL(double hue, double saturation, double lightness) {
  h = hue;
  s = saturation;
  l = lightness;
}

HSL HSL::copy() {
  return HSL(h, s, l);
}

String HSL::toString() {
  return "(" + String(h) + ", " + String(s) + ", " + String(l) + ")";
}


RGB::RGB(byte red, byte green, byte blue) {
  r = red;
  g = green;
  b = blue;
}

RGB RGB::copy() {
  return RGB(r, g, b);
}

String RGB::toString() {
  return "(" + String(r) + ", " + String(g) + ", " + String(b) + ")";
}

HSL RGB::toHsl() {
  RGBConverter converter;
  double hsl[3];
  converter.rgbToHsl(r, g, b, hsl);
  return HSL(hsl[0], hsl[1], hsl[2]);
}

RGB RGB::fromHsl(HSL hsl) {
  RGBConverter converter;
  byte rgb[3];
  converter.hslToRgb(hsl.h, hsl.s, hsl.l, rgb);
  return RGB(rgb[0], rgb[1], rgb[2]);
}

HSV RGB::toHsv() {
  RGBConverter converter;
  double hsv[3];
  converter.rgbToHsv(r, g, b, hsv);
  return HSV(hsv[0], hsv[1], hsv[2]);
}

RGB RGB::fromHsv(HSV hsv) {
  RGBConverter converter;
  byte rgb[3];
  converter.hsvToRgb(hsv.h, hsv.s, hsv.v, rgb);
  RGB rgbColor;
  rgbColor = RGB(rgb[0], rgb[1], rgb[2]);
  return rgbColor;
}


RGBW::RGBW(byte red, byte green, byte blue, byte white): RGB{red, green, blue} {
  w = white;
}

RGBW RGBW::copy() {
  return RGBW(r, g, b, w);
}

RGB RGBW::toRGB() {
  return RGB(r, g, b);
}

String RGBW::toString() {
  return "(" + String(r) + ", " + String(g) + ", " + String(b) + ", " + String(w) + ")";
}

HSL RGBW::toHsl() {
  RGBConverter converter;
  double hsl[3];
  converter.rgbToHsl(r, g, b, hsl);
  return HSL(hsl[0], hsl[1], hsl[2]);
}

RGBW RGBW::fromHsl(HSL hsl) {
  RGBConverter converter;
  byte rgb[3];
  converter.hslToRgb(hsl.h, hsl.s, hsl.l, rgb);
  return RGBW(rgb[0], rgb[1], rgb[2], 0);
}

HSV RGBW::toHsv() {
  RGBConverter converter;
  double hsv[3];
  converter.rgbToHsv(r, g, b, hsv);
  return HSV(hsv[0], hsv[1], hsv[2]);
}

RGBW RGBW::fromHsv(HSV hsv) {
  RGBConverter converter;
  byte rgb[3];
  converter.hslToRgb(hsv.h, hsv.s, hsv.v, rgb);
  return RGBW(rgb[0], rgb[1], rgb[2], 0);
}
