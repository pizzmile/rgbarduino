#include "RGBController.h"

#define RED_PIN D6
#define GREEN_PIN D7
#define BLUE_PIN D5

#define SPEED 200
#define MIN_DELAY 10


DeviceRGB device = DeviceRGB(RED_PIN, GREEN_PIN, BLUE_PIN, SPEED, MIN_DELAY);

int counter = 0;


void setup() {
  Serial.begin(9600);
  Serial.println();

  device.init();
  device.clear();
  device.set(Color(255, 40, 0, 0));
}

void loop() {
  delay(1000);
}
