# DL2416T

Controling the Siemens DL2416T with an Arduino.

## The Component

![Imgur](https://i.imgur.com/kFANJgu.jpg)

## Code

```C
#include "dl2416t.hpp"

DL2416T disp;

void setup()
{
  // Connecting D0-D6 with PINS 2-8
  // Connecting A0-A1 with PINS 9-10
  // Connecting WR with PIN 11
  disp.init(2,3,4,5,6,7,8,9,10,11);
}

char string[] = "1234567890";
uint8_t p = 0;

void loop() {
  disp.displayChar(string[p], 1);
  disp.displayChar(string[(p + 1) % 10], 2);
  disp.displayChar(string[(p + 2) % 10], 3);
  disp.displayChar(string[(p + 3) % 10], 4);

  p++;
  p %= 10;
  delay(100);
}
```
