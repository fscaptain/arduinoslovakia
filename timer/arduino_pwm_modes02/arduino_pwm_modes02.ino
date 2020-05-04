/**
  Arduino PWM modes - Timer2 Fast PWM
  v. 1.0
  Copyright (C) 2020 Robert Ulbricht
  https://www.arduinoslovakia.eu

  IDE: 1.8.12 or higher
  Board: Arduino Pro Mini

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "dump.h"

DREG(TCCR2A, COM2A1, COM2A0, COM2B1, COM2B0, RESERVED, RESERVED, WGM21, WGM20)
DREG(TCCR2B, FOC2A, FOC2B, RESERVED, RESERVED, WGM22, CS22, CS21, CS20)
 
void setup() {
  pinMode(11, OUTPUT); // TIMER2A
  analogWrite(11, 1);  // minimal PWM value

  Serial.begin(9600);
  Serial.println("PWM modes");
  
  // TIMER2
  Serial << _(TCCR2A);
  Serial << _(TCCR2B);
  DUMPVAL(OCR2A)
  DUMPVAL(OCR2B)

  Serial.println("TIMER2 Mode 3: Fast PWM");
  TCCR2A = _BV(COM2A1) | _BV(WGM21) | _BV(WGM20);
  Serial << _(TCCR2A);
  Serial << _(TCCR2B);
  DUMPVAL(OCR2A)
  DUMPVAL(OCR2B)
}

void loop() {
}
