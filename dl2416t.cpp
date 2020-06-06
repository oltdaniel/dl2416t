#include "dl2416t.hpp"

void DL2416T::init(
  uint8_t d0Pin,
  uint8_t d1Pin,
  uint8_t d2Pin,
  uint8_t d3Pin,
  uint8_t d4Pin,
  uint8_t d5Pin,
  uint8_t d6Pin,
  uint8_t a0Pin,
  uint8_t a1Pin,
  uint8_t wrPin
)
{
  // Store pins
  this->d0Pin = d0Pin;
  this->d1Pin = d1Pin;
  this->d2Pin = d2Pin;
  this->d3Pin = d3Pin;
  this->d4Pin = d4Pin;
  this->d5Pin = d5Pin;
  this->d6Pin = d6Pin;
  this->a0Pin = a0Pin;
  this->a1Pin = a1Pin;
  this->wrPin = wrPin;

  // Set all pins we use to output pins
  pinMode(this->d0Pin,  OUTPUT);
  pinMode(this->d1Pin,  OUTPUT);
  pinMode(this->d2Pin,  OUTPUT);
  pinMode(this->d3Pin,  OUTPUT);
  pinMode(this->d4Pin,  OUTPUT);
  pinMode(this->d5Pin,  OUTPUT);
  pinMode(this->d6Pin,  OUTPUT);

  pinMode(this->a0Pin,  OUTPUT);
  pinMode(this->a1Pin,  OUTPUT);
  
  pinMode(this->wrPin,  OUTPUT);

  // Set default states
  digitalWrite(this->a0Pin, LOW);
  digitalWrite(this->a1Pin, LOW);

  digitalWrite(this->wrPin, HIGH);
}

void DL2416T::displayChar(char c, uint8_t pos)
{
  // Set position (left to right)
  switch(pos) {
    case 1:
      digitalWrite(this->a0Pin, HIGH);
      digitalWrite(this->a1Pin, HIGH);
      break;
    case 2:
      digitalWrite(this->a0Pin, HIGH);
      digitalWrite(this->a1Pin, LOW);
      break;
    case 3:
      digitalWrite(this->a0Pin, LOW);
      digitalWrite(this->a1Pin, HIGH);
      break;
    case 4:
      digitalWrite(this->a0Pin, LOW);
      digitalWrite(this->a1Pin, LOW);
      break;
  }
  
  // Set data pins
  digitalWrite(this->d0Pin,  (c & 0b00000001) ? HIGH : LOW);
  digitalWrite(this->d1Pin,  (c & 0b00000010) ? HIGH : LOW);
  digitalWrite(this->d2Pin,  (c & 0b00000100) ? HIGH : LOW);
  digitalWrite(this->d3Pin,  (c & 0b00001000) ? HIGH : LOW);
  digitalWrite(this->d4Pin,  (c & 0b00010000) ? HIGH : LOW);
  digitalWrite(this->d5Pin,  (c & 0b00100000) ? HIGH : LOW);
  digitalWrite(this->d6Pin,  (c & 0b00100000) ? LOW  : HIGH);

  // Start write
  digitalWrite(this->wrPin, LOW);

  delayMicroseconds(1);

  // End write
  digitalWrite(this->wrPin, HIGH);
}
