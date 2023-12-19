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

void setup()
{
  pinMode(pin19, OUTPUT);
  pinMode(pin18, OUTPUT);
  pinMode(pin17, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //for (int subtract = 0; subtract <= 1; subtract++) {
    for (int A0_Counter = 0; A0_Counter <= 1; A0_Counter++) {
      for (int B0_Counter = 0; B0_Counter <= 1; B0_Counter++) {
        int subtract = 0;
        //digitalWrite(pin19, subtract);
        digitalWrite(pin18, B0_Counter);
        digitalWrite(pin17, A0_Counter);
        
        sumOfTop = (A0_Counter * 1);
        sumOfBottom = (B0_Counter * 1);
        if (subtract == 0){
          sum = (
            (A0_Counter * 1)
            +
            (B0_Counter * 1)
          );
        } else {
          sum = (
            (A0_Counter * 1)
            +
            (bitRead(~(B0_Counter), 0) * 1)
          );
        }
        
        bool overflow = false;
        if (A0_Counter == B0_Counter) {
          if (A0_Counter != bitRead(sum, 0)) {
          overflow = true;
          }
        }
        
        if (subtract == 0){
          Serial.print("\n\n");
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
        } else {
          Serial.print("\n\n");
          Serial.print("    " + String(A0_Counter));
          Serial.print("  (" + String(sumOfTop) + ")\n");
          Serial.print(" -  " + String(B0_Counter));
          Serial.print("  (" + String(sumOfBottom) + ")\n");
          Serial.print(" ------\n  ");
          Serial.print("  " + String(bitRead(sum, 0)));
          Serial.print("  (" + String(sum) + ")\n");
        }
        
        delay(2000); // Wait for 1000 millisecond(s)
      }
    }
  //}
  Serial.print("\n");
}
        