/*
Curtis Edwards
TEJ4M
Final Project
1-Bit Full Adder and Subtractor
*/

int pin19 = 19;
int pin18 = 18;
int pin17 = 17;
int sum = 0;
int sumOfTop = 0;
int sumOfBottom = 0;

const int interval = 2000; // Set interval of display in milliseconds
const int numberOfBits = 1;

void setup()
{
  pinMode(pin19, OUTPUT);
  pinMode(pin18, OUTPUT);
  pinMode(pin17, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int C0_Counter = 0; C0_Counter <= 1; C0_Counter++) {
    for (int A0_Counter = 0; A0_Counter <= 1; A0_Counter++) {
      for (int B0_Counter = 0; B0_Counter <= 1; B0_Counter++) {
        digitalWrite(pin19, C0_Counter);
        digitalWrite(pin18, B0_Counter);
        digitalWrite(pin17, A0_Counter);
        
        /*                */
        /*  CALCULATIONS  */
        /*                */

        // Variables
        int sum = 0;
        int sumOfTop = 0;
        int sumOfBottom = 0;
        int sumOfCarry = 0;
        bool overflow = false;
        bitWrite(sumOfTop, 0, A0_Counter);
        bitWrite(sumOfBottom, 0, B0_Counter);
        bitWrite(sumOfCarry, 0, C0_Counter);
        
        sum = sumOfTop + sumOfBottom + sumOfCarry;

        if (bitRead(sum, numberOfBits) == 1) {
          overflow = true;
        }
        
        Serial.print("\n\n");
        Serial.print("    " + String(C0_Counter));
        Serial.print("  (" + String(sumOfCarry) + ")\n");
        Serial.print("    " + String(A0_Counter));
        Serial.print("  (" + String(sumOfTop) + ")\n");
        Serial.print(" +  " + String(B0_Counter));
        Serial.print("  (" + String(sumOfBottom) + ")\n");
        Serial.print(" ------\n  ");
        Serial.print("  " + String(bitRead(sum, 0)));
        if (overflow == true) {
          Serial.print("  <- Overflow");
        } else {
          Serial.print("  (" + String(sum) + ")\n");
        }
        delay(interval); // Wait for xxxx millisecond(s)
      }
    }
  }
  Serial.print("\n");
}
