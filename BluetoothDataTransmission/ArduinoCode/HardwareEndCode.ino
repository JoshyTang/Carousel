#include <SoftwareSerial.h>   // Import library
// Define pins of the BLE module
SoftwareSerial BT(8, 9); // HC-05 TX to UNO-D8 port; HC-05 RX to UNO-D9 port
char val;  // Store the received data
int pin = A0;
void setup() {
     analogReference(INTERNAL);
       Serial.begin(9600);   
       Serial.println("BT is ready!");
       // Baud rate 38400 for HC-06
       BT.begin(9600);
}
void loop() {
       // Send the data received by the serial monitor to the BLE module
       int sensorValue = analogRead(pin);
     float voltage= sensorValue * (1.1 / 1023.0) * 1000;
//     Serial.println(voltage, DEC); 
       //if (Serial.available()) {
//              val = Serial.read();
//              Serial.println(voltage DEC); 
              Serial.println(voltage,1); 
              //val = 'A';
              BT.print(voltage);
              BT.print(';');
       //}
       // Send the data received by the BLE module to the serial monitor
       if (BT.available()) {
              val = BT.read();
              Serial.print(val);

       }
                     delay(100);
}
