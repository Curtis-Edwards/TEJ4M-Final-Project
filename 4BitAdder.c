/*
Curtis Edwards
TEJ4M
Final Project
4-Bit Full Adder and Subtractor
*/

int pin19 = 19;
int pin18 = 18;
int pin17 = 17;
int pin16 = 16;
int pin15 = 15;
int pin14 = 14;
int pin13 = 13;
int pin12 = 12;
int pin11 = 11;

const int interval = 1500; // Set interval of display in milliseconds
const int numberOfBits = 4;

void setup()
{
  pinMode(pin19, OUTPUT);
  pinMode(pin18, OUTPUT);
  pinMode(pin17, OUTPUT);
  pinMode(pin16, OUTPUT);
  pinMode(pin15, OUTPUT);
  pinMode(pin14, OUTPUT);
  pinMode(pin13, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int subtract = 0; subtract <= 1; subtract++) {
    for (int A3_Counter = 0; A3_Counter <= 1; A3_Counter++) {
      for (int A2_Counter = 0; A2_Counter <= 1; A2_Counter++) {
        for (int A1_Counter = 0; A1_Counter <= 1; A1_Counter++) {
          for (int A0_Counter = 0; A0_Counter <= 1; A0_Counter++) {
            for (int B3_Counter = 0; B3_Counter <= 1; B3_Counter++) {
              for (int B2_Counter = 0; B2_Counter <= 1; B2_Counter++) {
                for (int B1_Counter = 0; B1_Counter <= 1; B1_Counter++) {
                  for (int B0_Counter = 0; B0_Counter <= 1; B0_Counter++) {
                    digitalWrite(pin19, subtract);
                    digitalWrite(pin18, B0_Counter);
                    digitalWrite(pin17, A0_Counter);
                    digitalWrite(pin16, B1_Counter);
                    digitalWrite(pin15, A1_Counter);
                    digitalWrite(pin14, B2_Counter);
                    digitalWrite(pin13, A2_Counter);
                    digitalWrite(pin12, B3_Counter);
                    digitalWrite(pin11, A3_Counter);
                    
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
                    bitWrite(sumOfTop, 2, A2_Counter);
                    bitWrite(sumOfTop, 3, A3_Counter);
                    bitWrite(sumOfBottom, 0, B0_Counter);
                    bitWrite(sumOfBottom, 1, B1_Counter);
                    bitWrite(sumOfBottom, 2, B2_Counter);
                    bitWrite(sumOfBottom, 3, B3_Counter);
                    
                    bitWrite(sumOfTopDecimal, 0, A0_Counter);
                    bitWrite(sumOfTopDecimal, 1, A1_Counter);
                    bitWrite(sumOfTopDecimal, 2, A2_Counter);
                    bitWrite(sumOfTopDecimal, 3, A3_Counter);
                    bitWrite(sumOfBottomDecimal, 0, B0_Counter);
                    bitWrite(sumOfBottomDecimal, 1, B1_Counter);
                    bitWrite(sumOfBottomDecimal, 2, B2_Counter);
                    bitWrite(sumOfBottomDecimal, 3, B3_Counter);
                    
                    if (subtract == 1) {
                      // Check if bottom number is negative
                      if (bitRead(sumOfBottom, (numberOfBits - 1)) == 1) {
                        subtractOverflow = true;
                      }
                      bitWrite(sumOfBottom, 0, bitRead(~(B0_Counter), 0));
                      bitWrite(sumOfBottom, 1, bitRead(~(B1_Counter), 0));
                      bitWrite(sumOfBottom, 2, bitRead(~(B2_Counter), 0));
                      bitWrite(sumOfBottom, 3, bitRead(~(B3_Counter), 0));
                      sumOfBottom++;
                      bitWrite(sumOfBottom, (numberOfBits), 0);
                      // Check if bottom number is still negative after flip, if so, its overflow
                      if ((subtractOverflow == 1) && (bitRead(sumOfBottom, (numberOfBits - 1)) == 1)) {
                        overflow = true;
                      }
                    } else {
                      bitWrite(sumOfBottom, 0, B0_Counter);
                      bitWrite(sumOfBottom, 1, B1_Counter);
                      bitWrite(sumOfBottom, 2, B2_Counter);
                      bitWrite(sumOfBottom, 3, B3_Counter);
                    }
                    
                    sum = sumOfTop + sumOfBottom;
                    bitWrite(sum, (numberOfBits), 0);

                    // Check for overflow
                    if (bitRead(sumOfTop, (numberOfBits - 1)) == bitRead(sumOfBottom, (numberOfBits - 1))) {
                      if (bitRead(sumOfTop, (numberOfBits - 1)) != bitRead(sum, (numberOfBits - 1))) {
                        overflow = true;
                      }
                    }
                    
                    // re-write bits if there negative (for decimal display)
                    if (B3_Counter == 1) {
                      bitWrite(sumOfBottomDecimal, 0, bitRead(~(sumOfBottomDecimal), 0));
                      bitWrite(sumOfBottomDecimal, 1, bitRead(~(sumOfBottomDecimal), 1));
                      bitWrite(sumOfBottomDecimal, 2, bitRead(~(sumOfBottomDecimal), 2));
                      bitWrite(sumOfBottomDecimal, 3, bitRead(~(sumOfBottomDecimal), 3));
                      sumOfBottomDecimal++;
                      bitWrite(sumOfBottomDecimal, numberOfBits, 0);
                      sumOfBottomDecimal = sumOfBottomDecimal * -1;
                    }
                    
                    if (A3_Counter == 1) {
                      bitWrite(sumOfTopDecimal, 0, bitRead(~(sumOfTopDecimal), 0));
                      bitWrite(sumOfTopDecimal, 1, bitRead(~(sumOfTopDecimal), 1));
                      bitWrite(sumOfTopDecimal, 2, bitRead(~(sumOfTopDecimal), 2));
                      bitWrite(sumOfTopDecimal, 3, bitRead(~(sumOfTopDecimal), 3));
                      sumOfTopDecimal++;
                      bitWrite(sumOfTopDecimal, numberOfBits, 0);
                      sumOfTopDecimal = sumOfTopDecimal * -1;
                    }
                    
                    sumDecimal = sum;
                    if (bitRead(sum, (numberOfBits - 1)) == 1) {
                      bitWrite(sumDecimal, 0, bitRead(~(sum), 0));
                      bitWrite(sumDecimal, 1, bitRead(~(sum), 1));
                      bitWrite(sumDecimal, 2, bitRead(~(sum), 2));
                      bitWrite(sumDecimal, 3, bitRead(~(sum), 3));
                      sumDecimal++;
                      bitWrite(sumDecimal, numberOfBits, 0);
                      sumDecimal = sumDecimal * -1;
                    }
                    
                    /*          */
                    /*  OUTPUT  */
                    /*          */
                    
                    Serial.print("\n\n");
                    Serial.print(
                      "    " +
                      String(A3_Counter) +
                      String(A2_Counter) +
                      String(A1_Counter) +
                      String(A0_Counter)
                    );
                    Serial.print("  (" + String(sumOfTopDecimal) + ")\n");
                    if (subtract == 1) {
                      Serial.print(" -  ");
                    } else {
                      Serial.print(" +  ");
                    }
                    Serial.print(
                      String(B3_Counter) +
                      String(B2_Counter) +
                      String(B1_Counter) +
                      String(B0_Counter)
                    );
                    Serial.print("  (" + String(sumOfBottomDecimal) + ")\n");
                    Serial.print(" --------\n  ");
                    Serial.print(
                      "  " +
                      String(bitRead(sum, 3)) +
                      String(bitRead(sum, 2)) +
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
        }
      }
    }
  }
  Serial.print("\n");
}