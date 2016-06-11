/* USB Arcade Joystick
   Using Teensy Joystick API
   
   Supports two digital joysticks with 6+1 buttons per player.
*/

#define pinP1JoyU 27
#define pinP1JoyD 0
#define pinP1JoyR 1
#define pinP1JoyL 2
#define pinP1Btn1 3
#define pinP1Btn2 4
#define pinP1Btn3 5
#define pinP1Btn4 7
#define pinP1Btn5 8
#define pinP1Btn6 9
#define pinP1Start 10
#define pinP2JoyU 26
#define pinP2JoyD 25
#define pinP2JoyR 24
#define pinP2JoyL 23
#define pinP2Btn1 22
#define pinP2Btn2 21
#define pinP2Btn3 20
#define pinP2Btn4 19
#define pinP2Btn5 18
#define pinP2Btn6 38
#define pinP2Start 39

void setup() {
  // Activate all inputs in pullup mode
  pinMode(pinP1JoyU, INPUT_PULLUP);
  pinMode(pinP1JoyD, INPUT_PULLUP);
  pinMode(pinP1JoyR, INPUT_PULLUP);
  pinMode(pinP1JoyL, INPUT_PULLUP);
  pinMode(pinP1Btn1, INPUT_PULLUP);
  pinMode(pinP1Btn2, INPUT_PULLUP);
  pinMode(pinP1Btn3, INPUT_PULLUP);
  pinMode(pinP1Btn4, INPUT_PULLUP);
  pinMode(pinP1Btn5, INPUT_PULLUP);
  pinMode(pinP1Btn6, INPUT_PULLUP);
  pinMode(pinP1Start, INPUT_PULLUP);
  pinMode(pinP2JoyU, INPUT_PULLUP);
  pinMode(pinP2JoyD, INPUT_PULLUP);
  pinMode(pinP2JoyR, INPUT_PULLUP);
  pinMode(pinP2JoyL, INPUT_PULLUP);
  pinMode(pinP2Btn1, INPUT_PULLUP);
  pinMode(pinP2Btn2, INPUT_PULLUP);
  pinMode(pinP2Btn3, INPUT_PULLUP);
  pinMode(pinP2Btn4, INPUT_PULLUP);
  pinMode(pinP2Btn5, INPUT_PULLUP);
  pinMode(pinP2Btn6, INPUT_PULLUP);
  pinMode(pinP2Start, INPUT_PULLUP);
  Joystick.useManualSend(true); // So button combos get sent simultaneously as the arcade gods intend.
}

int JoyDtoA(int pinPos, int pinNeg) {
  int value = 512;
  value += (511 * pinPos);
  value += (-511 * pinNeg);
  if(value == 1) {
    return 0;
  } else {
    return value;
  }
}

void loop() {
  // Read P1 Joystick, convert to fake analog on main X/Y
  Joystick.X(JoyDtoA(!digitalRead(pinP1JoyR), !digitalRead(pinP1JoyL)));
  Joystick.Y(JoyDtoA(!digitalRead(pinP1JoyD), !digitalRead(pinP1JoyU)));
  // Read P1 Buttons
  Joystick.button(1, !digitalRead(pinP1Btn1));
  Joystick.button(2, !digitalRead(pinP1Btn2));
  Joystick.button(3, !digitalRead(pinP1Btn3));
  Joystick.button(4, !digitalRead(pinP1Btn4));
  Joystick.button(5, !digitalRead(pinP1Btn5));
  Joystick.button(6, !digitalRead(pinP1Btn6));
  // Read P2 Joystick
  Joystick.button(7, !digitalRead(pinP2JoyU));
  Joystick.button(8, !digitalRead(pinP2JoyD));
  Joystick.button(9, !digitalRead(pinP2JoyR));
  Joystick.button(10, !digitalRead(pinP2JoyL));
  // Read P2 Buttons
  Joystick.button(11, !digitalRead(pinP2Btn1));
  Joystick.button(12, !digitalRead(pinP2Btn2));
  Joystick.button(13, !digitalRead(pinP2Btn3));
  Joystick.button(14, !digitalRead(pinP2Btn4));
  Joystick.button(15, !digitalRead(pinP2Btn5));
  Joystick.button(16, !digitalRead(pinP2Btn6));
  // Read Start Buttons
  if(!digitalRead(pinP1Start)) {
    Keyboard.set_key1(KEY_1);
  } else {
    Keyboard.set_key1(0);
  }
  if(!digitalRead(pinP2Start)) {
    Keyboard.set_key2(KEY_2);
  } else {
    Keyboard.set_key2(0);
  }
  // Send Data
  Joystick.send_now();
  Keyboard.send_now();
  // Do we even need a delay?  Test this.  Default setting 100Hz.
  delay(10);
}
