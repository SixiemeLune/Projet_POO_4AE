#include "classes.h"


My_Servo servo1;

void setup() { 
  servo1.connect(12); //GPIO 12 corresponds to D6
}

void loop() {
  servo1.Open_Blinds(); 
  delay(1000);
  servo1.Close_Blinds(); 
  delay(1000);
}
