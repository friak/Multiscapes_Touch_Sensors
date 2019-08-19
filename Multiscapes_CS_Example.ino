#include <CapacitiveSensor.h>


CapacitiveSensor   cs1 = CapacitiveSensor(4, 8);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin
CapacitiveSensor   cs2 = CapacitiveSensor(4, 6);
CapacitiveSensor   cs3 = CapacitiveSensor(4, 2);

int lED1 = 3;
int lED2 = 5;
int lED3 = 9;

//int ledPins[] = {3, 5, 9};
//int pinCount = 3;


void setup()
{
//  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
//    pinMode(ledPins, OUTPUT);
//  }
pinMode(lED1, OUTPUT);
pinMode(lED2, OUTPUT);
pinMode(lED3, OUTPUT);

Serial.begin(9600);
}

void loop()
{
  long start = millis();
  long val1 =  cs1.capacitiveSensor(30);
  long val2 =  cs2.capacitiveSensor(30);
  long val3 =  cs3.capacitiveSensor(30);

  if (val1 >= 100 && val2 <= 100 && val3 <= 100) {
    digitalWrite(lED1, HIGH);
    digitalWrite(lED2, LOW);
    digitalWrite(lED3, LOW);
  }

  else if ((val2 >= 100 && val1 <= 100) || (val3 >= 100 && val1 <=100)) {
    digitalWrite(lED1, LOW);
    digitalWrite(lED2, HIGH);
    digitalWrite(lED3, LOW);
  }


  else if (val1 >= 100 && val3 >= 100 && val2 <= 100) {
      digitalWrite(lED1, LOW);
      digitalWrite(lED2, LOW);
      digitalWrite(lED3, HIGH);
    }
    else {
      digitalWrite(lED1, LOW);
      digitalWrite(lED2, LOW);
      digitalWrite(lED3, LOW);
    }

    //  Serial.print(millis() - start);        // check on performance in milliseconds
    //  Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print(val1);
    Serial.print(" - ");
    Serial.print(val2);
    Serial.print(" - ");
    Serial.print(val3);
    Serial.println();
  }
