#ifndef RGB_Controller
#define RGB_Controller

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "RGBColors.h"


// ---------- GENERIC DEVICE

class Device {
  protected:
    Color state = Color(0, 0, 0);

    byte s = 0;
    int d = 0;

  public:
    Device(byte speed, int minDelay);
    virtual void init() = 0;

    int getSpeedDelay(int maxDelay);
    byte getSpeed();
    void setSpeed(byte speed);
    
    // Color setters
    virtual void clear() = 0;
    virtual void set(Color color) = 0;
    // Animations
    void fade(Color color);
    void breath(Color color);
    void breath2(Color color1, Color color2);
    void pulse(Color color);
    void candle(Color color);
    void rainbow();
};


// ---------- RGB DEVICE

class DeviceRGB: public Device {
  private:
    int rPin = 0;
    int gPin = 0;
    int bPin = 0;

  public:
    DeviceRGB(int redPin, int greenPin, int bluePin, byte speed, int minDelay);

    void init() override;
    void clear() override;
    void set(Color color) override;
};


// ---------- RGBW DEVICE

class DeviceRGBW: public Device {
  private:
    int rPin = 0;
    int gPin = 0;
    int bPin = 0;
    int wPin = 0;
  
  public:
    DeviceRGBW(int redPin, int greenPin, int bluePin, int whitePin, byte speed, int minDelay);

    void init();
    void clear();
    void set(Color color);
};


#endif