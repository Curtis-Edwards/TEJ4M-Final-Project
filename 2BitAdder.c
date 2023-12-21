/*
Curtis Edwards
TEJ4M
Final Project
2-Bit Full Adder and Subtractor
*/

int pin19 = 19;
int pin18 = 18;
int pin17 = 17;
int pin16 = 16;
int pin15 = 15;

const int interval = 2500; // Set interval of display in milliseconds

void setup()
{
  pinMode(pin19, OUTPUT);
  pinMode(pin18, OUTPUT);
  pinMode(pin17, OUTPUT);
  pinMode(pin16, OUTPUT);
  pinMode(pin15, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int subtract = 0; subtract <= 1; subtract++) {
    for (int A1_Counter = 0; A1_Counter <= 1; A1_Counter++) {
      for (int A0_Counter = 0; A0_Counter <= 1; A0_Counter++) {
        for (int B1_Counter = 0; B1_Counter <= 1; B1_Counter++) {
          for (int B0_Counter = 0; B0_Counter <= 1; B0_Counter++) {
            digitalWrite(pin19, subtract);
            digitalWrite(pin18, B0_Counter);
            digitalWrite(pin17, A0_Counter);
            digitalWrite(pin16, B1_Counter);
            digitalWrite(pin15, A1_Counter);
            
            /*                */
            /*  CALCULATIONS  */
            /*                */
            
            // Variables
            int sum = 0;
            int sumDecimal = 0;
            int sumOfTop = 0;
            int sumOfTopDecimal = 0;
            int sumOfBottom = 0;
            int sumOfBottomDecimal = 0;
            bool overflow = false;
            bool subtractOverflow = false;
            
            // Calculate the sum
            bitWrite(sumOfTop, 0, A0_Counter);
            bitWrite(sumOfTop, 1, A1_Counter);
            bitWrite(sumOfBottom, 0, B0_Counter);
            bitWrite(sumOfBottom, 1, B1_Counter);
            
            bitWrite(sumOfTopDecimal, 0, A0_Counter);
            bitWrite(sumOfTopDecimal, 1, A1_Counter);
            bitWrite(sumOfBottomDecimal, 0, B0_Counter);
            bitWrite(sumOfBottomDecimal, 1, B1_Counter);
            
            if (subtract == 1) {
              // Check if bottom number is negative
              if (bitRead(sumOfBottom, 1) == 1) {
                subtractOverflow = true;
              }
              bitWrite(sumOfBottom, 0, bitRead(~(B0_Counter), 0));
              bitWrite(sumOfBottom, 1, bitRead(~(B1_Counter), 0));
              sumOfBottom++;
              bitWrite(sumOfBottom, 2, 0);
              // Check if bottom number is still negative after flip, if so, its overflow
              if ((subtractOverflow == 1) && (bitRead(sumOfBottom, 1) == 1)) {
                overflow = true;
              }
            } else {
              bitWrite(sumOfBottom, 0, B0_Counter);
              bitWrite(sumOfBottom, 1, B1_Counter);
            }
            
            sum = sumOfTop + sumOfBottom;
            bitWrite(sum, 2, 0);

            // Check for overflow
            if (bitRead(sumOfTop, 1) == bitRead(sumOfBottom, 1)) {
              if (bitRead(sumOfTop, 1) != bitRead(sum, 1)) {
                overflow = true;
              }
            }
            
            // re-write bits if there negative (for decimal display)
            if (B1_Counter == 1) {
              bitWrite(sumOfBottomDecimal, 0, bitRead(~(sumOfBottomDecimal), 0));
              bitWrite(sumOfBottomDecimal, 1, bitRead(~(sumOfBottomDecimal), 1));
              sumOfBottomDecimal++;
              bitWrite(sumOfBottomDecimal, 2, 0);
              sumOfBottomDecimal = sumOfBottomDecimal * -1;
            }
            
            if (A1_Counter == 1) {
              bitWrite(sumOfTopDecimal, 0, bitRead(~(sumOfTopDecimal), 0));
              bitWrite(sumOfTopDecimal, 1, bitRead(~(sumOfTopDecimal), 1));
              sumOfTopDecimal++;
              bitWrite(sumOfTopDecimal, 2, 0);
              sumOfTopDecimal = sumOfTopDecimal * -1;
            }
            
            sumDecimal = sum;
            if (bitRead(sum, 1) == 1) {
              bitWrite(sumDecimal, 0, bitRead(~(sum), 0));
              bitWrite(sumDecimal, 1, bitRead(~(sum), 1));
              sumDecimal++;
              bitWrite(sumDecimal, 2, 0);
              sumDecimal = sumDecimal * -1;
            }
            
            /*          */
            /*  OUTPUT  */
            /*          */
            
            Serial.print("\n\n");
            Serial.print(
              "    " +
              String(A1_Counter) +
              String(A0_Counter)
            );
            Serial.print("  (" + String(sumOfTopDecimal) + ")\n");
            if (subtract == 1) {
              Serial.print(
                " -  " +
                String(B1_Counter) +
                String(B0_Counter)
              );
            } else {
              Serial.print(
                " +  " +
                String(B1_Counter) +
                String(B0_Counter)
              );
            }
            Serial.print("  (" + String(sumOfBottomDecimal) + ")\n");
            Serial.print(" ------\n  ");
            Serial.print(
              "  " +
              String(bitRead(sum, 1)) +
              String(bitRead(sum, 0))
            );
            if (overflow == true) {
              Serial.print("  <- Overflow");
            } else {
              Serial.print("  (" + String(sumDecimal) + ")\n");
            }
            delay(interval); // Wait for xxxx millisecond(s)
          } 
        }
      }
    }
  }
  Serial.print("\n");
}
