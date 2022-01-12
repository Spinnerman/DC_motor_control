#define scr1_gate   8
#define scr2_gate   9
#define pot        A0
byte ZC = 0;
uint16_t alpha;

void setup(void) {
  pinMode(scr1_gate, OUTPUT);
  digitalWrite(scr1_gate, LOW);
  pinMode(scr2_gate, OUTPUT);
  digitalWrite(scr2_gate, LOW);
  attachInterrupt(0, ZC_detect, RISING);       // Enable external interrupt (INT0)
}

void ZC_detect() {
  if(digitalRead(2)==5)
    ZC = 1;
  else
    ZC = 2;
}

void loop() {
  if (ZC == 1) {
    alpha = analogRead(pot) * 2;
    delayMicroseconds(alpha);
    digitalWrite(scr1_gate, HIGH);
    delay(2);
    digitalWrite(scr1_gate, LOW);
//  alpha = analogRead(pot) * 7;
    ZC = 0;
  }
  if (ZC == 2) {
    alpha = analogRead(pot) * 2;
    delayMicroseconds(alpha);
    digitalWrite(scr2_gate, HIGH);
    delay(2);
    digitalWrite(scr2_gate, LOW);
//  alpha = analogRead(pot) * 7;
    ZC = 0;
  }
}
