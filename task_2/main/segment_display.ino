// BCD outputs from Arduino to 7-segment decoder
// Connect pins: A0=1, A1=2, A2=4, A3=8

int bcdPins[4] = {A0, A1, A2, A3};

void setup_segment_display() {
  // Set BCD pins as OUTPUT
  for (int i = 0; i < 4; i++) {
    pinMode(bcdPins[i], OUTPUT);
  }
  displayDigit(1);
}

void displayDigit(int num) {
  if (num < 0 || num > 9) return; // only 0–9

  // Write each bit of num to BCD pins
  for (int i = 0; i < 4; i++) {
    int bitValue = (num >> i) & 0x01;
    digitalWrite(bcdPins[i], bitValue);
  }
}
