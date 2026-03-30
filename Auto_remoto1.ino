  // PROGRAMA AUTO  //

#include <IRremote.hpp>  //libreria infrarrojo//

//  Variables  //

 //pines//
const int IR = 2;                  // Pin receptor IR 
const int LED = 8;                 // LED (click del joystick)
int avance = 5;                    // marcha adelante
int retroceso = 6;                 // marcha atras
int derecha = 9;                   // direccion derecha
int izquierda = 10;                // direccion izquierdar


#define led 6
bool estadoLed = false;            // Encendido-Apagado del LED


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(avance, OUTPUT);
  pinMode(retroceso, OUTPUT);
  IrReceiver.begin(IR, ENABLE_LED_FEEDBACK);
  Serial.begin(9600);
}

void loop() {
  if (IrReceiver.decode()) {
    int cmd = IrReceiver.decodedIRData.command;  //codigo de la libreria Irremote//
    Serial.print("Código recibido: ");
    Serial.println(cmd, DEC);              // cmd es el valor de señal recibida por el control//                     
    delay(500);                                                                                                      
    if (cmd == 6) {                                                    //Auto Enciende LED = 6//
      estadoLed = !estadoLed;           
      digitalWrite(LED, estadoLed);
      Serial.println(estadoLed ? "LED encendido" : "LED apagado");
      }
    if (cmd == 1) {                                                    //Auto parado = 1                   // Estos valores son recibidos del control cuando
      digitalWrite(avance, LOW);                                                                           // se acciona el joystick
      digitalWrite(retroceso, LOW);                                                                        // y el receptor los interpreta dando las ordenes
    }                                                                                                      // de marcha/giro/led
    if (cmd == 2) {
      digitalWrite(avance, HIGH);                                      // Auto avanza = 2
    }
    if(cmd == 3) {
      digitalWrite(retroceso, HIGH);                                   // Auto retroceso = 3
    }
    if (cmd == 4) {
      digitalWrite(derecha, HIGH);                                     // Auto gira Der = 4
    }
    if (cmd == 5) {
      digitalWrite(izquierda, HIGH);                                   // Auto gira Izq = 5 
    }
  
    }

    IrReceiver.resume();  
}
