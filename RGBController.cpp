#include "RGBController.h"


// ---------- GENERIC DEVICE

Device::Device(byte speed, int minDelay) {
  s = speed;
  d = minDelay;
}

// Animation speed controllers
int Device::getSpeedDelay(int maxDelay) {
  double speedFactor = 1.00 - (double)s / 255.00;
  int speedDelay = int(speedFactor * maxDelay);
  speedDelay = speedDelay < d ? d : speedDelay;
  return speedDelay;
}

byte Device::getSpeed() {
  return s;
}

void Device::setSpeed(byte speed) {
  s = speed;
}

// Color setters
void Device::clear() {
  state = Color(0, 0, 0, 0);
}

void Device::set(Color color) {
  state = color.copy();
}

// Animations
void Device::fade(Color color) {
  // FIX: strange behavior of setting individual colors (colors get stuck on 0.33 at the beginning and gradually fix themselves, never get lower 0.02)

  int deltaH = (int)(state.getHue() * 100) - (int)(color.getHue() * 100);
  int deltaS = (int)(state.getSaturation() * 100) - (int)(color.getSaturation() * 100);
  int deltaV = (int)(state.getValue() * 100) - (int)(color.getValue() * 100);

  while(deltaH != 0 || deltaS != 0 || deltaV != 0) {

    Serial.println("State: " + state.hsvToString());

    double newH = 0.0, newS = 0.0, newV = 0.0;

    // Adjust hue
    if (deltaH > 0) {
      deltaH -= 1;
      newH = state.getHue() - 0.01;
    } else if (deltaH < 0) {
      deltaH += 1;
      newH = state.getHue() + 0.01;
    } else {
      newH = state.getHue();
    }
    // Adjust saturation
    if (deltaS > 0) {
      deltaS -= 1;
      newS = state.getSaturation() - 0.01;
    } else if (deltaS < 0) {
      deltaS += 1;
      newS = state.getSaturation() + 0.01;
    } else {
      newS = state.getSaturation();
    }
    // Adjust lightness
    if (deltaV > 0) {
      deltaV -= 1;
      newV = state.getValue() - 0.01;
    } else if (deltaV < 0) {
      deltaV += 1;
      newV = state.getValue() + 0.01;
    } else {
      newV = state.getValue();
    }

    Color newColor = Color(newH, newS, newV);
    set(newColor);

    //state.setHue(newH);
    //state.setSaturation(newS);
    //state.setValue(newV);
    //set(state);

    delay(getSpeedDelay(250));
  }
}

// void Device::breath(Color color);
// void Device::breath2(Color color1, Color color2);
// void Device::pulse(Color color);
// void Device::candle(Color color);
// void Device::rainbow();


// ---------- RGB DEVICE

DeviceRGB::DeviceRGB(int redPin, int greenPin, int bluePin, byte speed, int minDelay): Device{speed, minDelay} {
  rPin = redPin;
  gPin = greenPin;
  bPin = bluePin;
}

void DeviceRGB::init() {
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void DeviceRGB::clear() {
  Device::clear();

  analogWrite(rPin, state.getRed());
  analogWrite(gPin, state.getGreen());
  analogWrite(bPin, state.getBlue());
}

void DeviceRGB::set(Color color) {
  Device::set(color);

  analogWrite(rPin, state.getRed());
  analogWrite(gPin, state.getGreen());
  analogWrite(bPin, state.getBlue());
}


// ---------- RGBW DEVICE

DeviceRGBW::DeviceRGBW(int redPin, int greenPin, int bluePin, int whitePin, byte speed, int minDelay): Device{speed, minDelay} {
  rPin = redPin;
  gPin = greenPin;
  bPin = bluePin;
  wPin = whitePin;
}

void DeviceRGBW::init() {
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(wPin, OUTPUT);
}

void DeviceRGBW::clear() {
  Device::clear();

  analogWrite(rPin, state.getRed());
  analogWrite(gPin, state.getGreen());
  analogWrite(bPin, state.getBlue());
  analogWrite(wPin, state.getWhite());
}

void DeviceRGBW::set(Color color) {
  Device::set(color);

  analogWrite(rPin, state.getRed());
  analogWrite(gPin, state.getGreen());
  analogWrite(bPin, state.getBlue());
  analogWrite(wPin, state.getWhite());
}

