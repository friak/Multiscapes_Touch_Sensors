#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */

CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

int LED = 3;

void setup()                    
{
  pinMode(LED, OUTPUT);
   Serial.begin(9600);
}

void loop()                    
{
    long start = millis();
    long total =  cs_4_8.capacitiveSensor(30);

    if (total >= 200){
      digitalWrite(LED, HIGH);
    }
    else{
      digitalWrite(LED, LOW);
    }

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing
    
    Serial.println(total);                // print sensor output 3

    delay(10);                             // arbitrary delay to limit data to serial port 
}
