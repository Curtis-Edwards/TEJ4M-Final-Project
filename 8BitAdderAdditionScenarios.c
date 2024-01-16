/*
Curtis Edwards
TEJ4M
Final Project
8-Bit Full Adder and Subtractor with scenarios (Addition)
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
int pin10 = 10;
int pin9 = 9;
int pin8 = 8;
int pin7 = 7;
int pin6 = 6;
int pin5 = 5;
int pin4 = 4;
int pin3 = 3;

const int interval = 6000; // Set interval of display in milliseconds
const int numberOfBits = 8;

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
  pinMode(pin10, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int scenario = 0; scenario <= 7; scenario++) {

    /*                */
    /*   SCENARIOS    */
    /*                */

    int A7_Counter = 0;
    int A6_Counter = 0;
    int A5_Counter = 0;
    int A4_Counter = 0;
    int A3_Counter = 0;
    int A2_Counter = 0;
    int A1_Counter = 0;
    int A0_Counter = 0;
    int B7_Counter = 0;
    int B6_Counter = 0;
    int B5_Counter = 0;
    int B4_Counter = 0;
    int B3_Counter = 0;
    int B2_Counter = 0;
    int B1_Counter = 0;
    int B0_Counter = 0;
    int subtract = 0;

    if (scenario == 0) {
      // Scenario 01:
      // Positive number + Positive number
      // 77 + 43 = 120

      Serial.print("Scenario 01:\n");
      Serial.print("Positive number + Positive number\n");
      Serial.print("77 + 43 = 120");

      A7_Counter = 0;
      A6_Counter = 1;
      A5_Counter = 0;
      A4_Counter = 0;
      A3_Counter = 1;
      A2_Counter = 1;
      A1_Counter = 0;
      A0_Counter = 1;

      B7_Counter = 0;
      B6_Counter = 0;
      B5_Counter = 1;
      B4_Counter = 0;
      B3_Counter = 1;
      B2_Counter = 0;
      B1_Counter = 1;
      B0_Counter = 1;

      subtract = 0;
    }
    if (scenario == 1) {
      // Scenario 02:
      // Positive number + Positive number, with overflow
      // 102 + 39 = 141

      Serial.print("Scenario 02:\n");
      Serial.print("Positive number + Positive number, with overflow\n");
      Serial.print("102 + 39 = 141");

      A7_Counter = 0;
      A6_Counter = 1;
      A5_Counter = 1;
      A4_Counter = 0;
      A3_Counter = 0;
      A2_Counter = 1;
      A1_Counter = 1;
      A0_Counter = 0;

      B7_Counter = 0;
      B6_Counter = 0;
      B5_Counter = 1;
      B4_Counter = 0;
      B3_Counter = 0;
      B2_Counter = 1;
      B1_Counter = 1;
      B0_Counter = 1;

      subtract = 0;
    }
    if (scenario == 2) {
      // Scenario 03:
      // Negative number + Positive number, with positive output
      // (-22) + 85 = 63

      Serial.print("Scenario 03:\n");
      Serial.print("Negative number + Positive number, with positive output\n");
      Serial.print("(-22) + 85 = 63");

      A7_Counter = 1;
      A6_Counter = 1;
      A5_Counter = 1;
      A4_Counter = 0;
      A3_Counter = 1;
      A2_Counter = 0;
      A1_Counter = 1;
      A0_Counter = 0;

      B7_Counter = 0;
      B6_Counter = 1;
      B5_Counter = 0;
      B4_Counter = 1;
      B3_Counter = 0;
      B2_Counter = 1;
      B1_Counter = 0;
      B0_Counter = 1;

      subtract = 0;
    }
    if (scenario == 3) {
      // Scenario 04:
      // Negative number + Positive number, with negative output
      // (-74) + 61 = -13

      Serial.print("Scenario 04:\n");
      Serial.print("Negative number + Positive number, with negative output\n");
      Serial.print("(-74) + 61 = -13");

      A7_Counter = 1;
      A6_Counter = 0;
      A5_Counter = 1;
      A4_Counter = 1;
      A3_Counter = 0;
      A2_Counter = 1;
      A1_Counter = 1;
      A0_Counter = 0;

      B7_Counter = 0;
      B6_Counter = 0;
      B5_Counter = 1;
      B4_Counter = 1;
      B3_Counter = 1;
      B2_Counter = 1;
      B1_Counter = 0;
      B0_Counter = 1;

      subtract = 0;
    }
    if (scenario == 4) { 
      // Scenario 05:
      // Positive number + Negative number, with positive output
      // 117 + (-54) = 63

      Serial.print("Scenario 05:\n");
      Serial.print("Positive number + Negative number, with positive output\n");
      Serial.print("117 + (-54) = 63");

      A7_Counter = 0;
      A6_Counter = 1;
      A5_Counter = 1;
      A4_Counter = 1;
      A3_Counter = 0;
      A2_Counter = 1;
      A1_Counter = 0;
      A0_Counter = 1;

      B7_Counter = 1;
      B6_Counter = 1;
      B5_Counter = 0;
      B4_Counter = 0;
      B3_Counter = 1;
      B2_Counter = 0;
      B1_Counter = 1;
      B0_Counter = 0;
    }
    if (scenario == 5) {
      // Scenario 06:
      // Positive number + Negative number, with negative output
      // 65 + (-70) = -5

      Serial.print("Scenario 06:\n");
      Serial.print("Positive number + Negative number, with negative output\n");
      Serial.print("65 + (-70) = -5");


      A7_Counter = 0;
      A6_Counter = 1;
      A5_Counter = 0;
      A4_Counter = 0;
      A3_Counter = 0;
      A2_Counter = 0;
      A1_Counter = 0;
      A0_Counter = 1;

      B7_Counter = 1;
      B6_Counter = 0;
      B5_Counter = 1;
      B4_Counter = 1;
      B3_Counter = 1;
      B2_Counter = 0;
      B1_Counter = 1;
      B0_Counter = 0;
    }
    if (scenario == 6) {
      // Scenario 07:
      // Negative number + Negative number
      // (-36) + (-17) = -53

      Serial.print("Scenario 07:\n");
      Serial.print("Negative number + Negative number\n");
      Serial.print("(-36) + (-17) = -53");

      A7_Counter = 1;
      A6_Counter = 1;
      A5_Counter = 0;
      A4_Counter = 1;
      A3_Counter = 1;
      A2_Counter = 1;
      A1_Counter = 0;
      A0_Counter = 0;

      B7_Counter = 1;
      B6_Counter = 1;
      B5_Counter = 1;
      B4_Counter = 0;
      B3_Counter = 1;
      B2_Counter = 1;
      B1_Counter = 1;
      B0_Counter = 1;
    }
    if (scenario == 7) {
      // Scenario 08:
      // Negative number + Negative number, with underflow
      // (-86) + (-59) = -145

      Serial.print("Scenario 08:\n");
      Serial.print("Negative number + Negative number, with underflow\n");
      Serial.print("(-86) + (-59) = -145");

      A7_Counter = 1;
      A6_Counter = 0;
      A5_Counter = 1;
      A4_Counter = 0;
      A3_Counter = 1;
      A2_Counter = 0;
      A1_Counter = 1;
      A0_Counter = 0;

      B7_Counter = 1;
      B6_Counter = 1;
      B5_Counter = 0;
      B4_Counter = 0;
      B3_Counter = 0;
      B2_Counter = 1;
      B1_Counter = 0;
      B0_Counter = 1;
    }
    
    digitalWrite(pin19, subtract);
    digitalWrite(pin18, B0_Counter);
    digitalWrite(pin17, A0_Counter);
    digitalWrite(pin16, B1_Counter);
    digitalWrite(pin15, A1_Counter);
    digitalWrite(pin14, B2_Counter);
    digitalWrite(pin13, A2_Counter);
    digitalWrite(pin12, B3_Counter);
    digitalWrite(pin11, A3_Counter);
    digitalWrite(pin10, B4_Counter);
    digitalWrite(pin9, A4_Counter);
    digitalWrite(pin8, B5_Counter);
    digitalWrite(pin7, A5_Counter);
    digitalWrite(pin6, B6_Counter);
    digitalWrite(pin5, A6_Counter);
    digitalWrite(pin4, B7_Counter);
    digitalWrite(pin3, A7_Counter);
    
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
    bitWrite(sumOfTop, 4, A4_Counter);
    bitWrite(sumOfTop, 5, A5_Counter);
    bitWrite(sumOfTop, 6, A6_Counter);
    bitWrite(sumOfTop, 7, A7_Counter);
    bitWrite(sumOfBottom, 0, B0_Counter);
    bitWrite(sumOfBottom, 1, B1_Counter);
    bitWrite(sumOfBottom, 2, B2_Counter);
    bitWrite(sumOfBottom, 3, B3_Counter);
    bitWrite(sumOfBottom, 4, B4_Counter);
    bitWrite(sumOfBottom, 5, B5_Counter);
    bitWrite(sumOfBottom, 6, B6_Counter);
    bitWrite(sumOfBottom, 7, B7_Counter);
    
    bitWrite(sumOfTopDecimal, 0, A0_Counter);
    bitWrite(sumOfTopDecimal, 1, A1_Counter);
    bitWrite(sumOfTopDecimal, 2, A2_Counter);
    bitWrite(sumOfTopDecimal, 3, A3_Counter);
    bitWrite(sumOfTopDecimal, 4, A4_Counter);
    bitWrite(sumOfTopDecimal, 5, A5_Counter);
    bitWrite(sumOfTopDecimal, 6, A6_Counter);
    bitWrite(sumOfTopDecimal, 7, A7_Counter);
    bitWrite(sumOfBottomDecimal, 0, B0_Counter);
    bitWrite(sumOfBottomDecimal, 1, B1_Counter);
    bitWrite(sumOfBottomDecimal, 2, B2_Counter);
    bitWrite(sumOfBottomDecimal, 3, B3_Counter);
    bitWrite(sumOfBottomDecimal, 4, B4_Counter);
    bitWrite(sumOfBottomDecimal, 5, B5_Counter);
    bitWrite(sumOfBottomDecimal, 6, B6_Counter);
    bitWrite(sumOfBottomDecimal, 7, B7_Counter);
    
    if (subtract == 1) {
      // Check if bottom number is negative
      if (bitRead(sumOfBottom, (numberOfBits - 1)) == 1) {
        subtractOverflow = true;
      }
      bitWrite(sumOfBottom, 0, bitRead(~(B0_Counter), 0));
      bitWrite(sumOfBottom, 1, bitRead(~(B1_Counter), 0));
      bitWrite(sumOfBottom, 2, bitRead(~(B2_Counter), 0));
      bitWrite(sumOfBottom, 3, bitRead(~(B3_Counter), 0));
      bitWrite(sumOfBottom, 4, bitRead(~(B4_Counter), 0));
      bitWrite(sumOfBottom, 5, bitRead(~(B5_Counter), 0));
      bitWrite(sumOfBottom, 6, bitRead(~(B6_Counter), 0));
      bitWrite(sumOfBottom, 7, bitRead(~(B7_Counter), 0));
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
      bitWrite(sumOfBottom, 4, B4_Counter);
      bitWrite(sumOfBottom, 5, B5_Counter);
      bitWrite(sumOfBottom, 6, B6_Counter);
      bitWrite(sumOfBottom, 7, B7_Counter);
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
    if (B7_Counter == 1) {
      bitWrite(sumOfBottomDecimal, 0, bitRead(~(sumOfBottomDecimal), 0));
      bitWrite(sumOfBottomDecimal, 1, bitRead(~(sumOfBottomDecimal), 1));
      bitWrite(sumOfBottomDecimal, 2, bitRead(~(sumOfBottomDecimal), 2));
      bitWrite(sumOfBottomDecimal, 3, bitRead(~(sumOfBottomDecimal), 3));
      bitWrite(sumOfBottomDecimal, 4, bitRead(~(sumOfBottomDecimal), 4));
      bitWrite(sumOfBottomDecimal, 5, bitRead(~(sumOfBottomDecimal), 5));
      bitWrite(sumOfBottomDecimal, 6, bitRead(~(sumOfBottomDecimal), 6));
      bitWrite(sumOfBottomDecimal, 7, bitRead(~(sumOfBottomDecimal), 7));
      sumOfBottomDecimal++;
      bitWrite(sumOfBottomDecimal, numberOfBits, 0);
      sumOfBottomDecimal = sumOfBottomDecimal * -1;
    }
    
    if (A7_Counter == 1) {
      bitWrite(sumOfTopDecimal, 0, bitRead(~(sumOfTopDecimal), 0));
      bitWrite(sumOfTopDecimal, 1, bitRead(~(sumOfTopDecimal), 1));
      bitWrite(sumOfTopDecimal, 2, bitRead(~(sumOfTopDecimal), 2));
      bitWrite(sumOfTopDecimal, 3, bitRead(~(sumOfTopDecimal), 3));
      bitWrite(sumOfTopDecimal, 4, bitRead(~(sumOfTopDecimal), 4));
      bitWrite(sumOfTopDecimal, 5, bitRead(~(sumOfTopDecimal), 5));
      bitWrite(sumOfTopDecimal, 6, bitRead(~(sumOfTopDecimal), 6));
      bitWrite(sumOfTopDecimal, 7, bitRead(~(sumOfTopDecimal), 7));
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
      bitWrite(sumDecimal, 4, bitRead(~(sum), 4));
      bitWrite(sumDecimal, 5, bitRead(~(sum), 5));
      bitWrite(sumDecimal, 6, bitRead(~(sum), 6));
      bitWrite(sumDecimal, 7, bitRead(~(sum), 7));
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
      String(A7_Counter) +
      String(A6_Counter) +
      String(A5_Counter) +
      String(A4_Counter) +
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
      String(B7_Counter) +
      String(B6_Counter) +
      String(B5_Counter) +
      String(B4_Counter) +
      String(B3_Counter) +
      String(B2_Counter) +
      String(B1_Counter) +
      String(B0_Counter)
    );
    Serial.print("  (" + String(sumOfBottomDecimal) + ")\n");
    Serial.print(" ------------\n  ");
    Serial.print(
      "  " +
      String(bitRead(sum, 7)) +
      String(bitRead(sum, 6)) +
      String(bitRead(sum, 5)) +
      String(bitRead(sum, 4)) +
      String(bitRead(sum, 3)) +
      String(bitRead(sum, 2)) +
      String(bitRead(sum, 1)) +
      String(bitRead(sum, 0))
    );
    if (overflow == true) {
      Serial.print("  <- Overflow/Underflow\n\n\n");
    } else {
      Serial.print("  (" + String(sumDecimal) + ")\n\n\n");
    }
    delay(interval); // Wait for xxxx millisecond(s)
  }
  Serial.print("\n");
}