//  Programa Control Joystick  //
#include <Arduino.h>
#define DISABLE_CODE_FOR_RECEIVER
#include <IRremote.hpp>

 //  Variables //
 
  // pines //
int IR = 2;
int EJEx = A1;
int EJEy = A2;
int Click = 4; 

  // comandos CMD //                 //Joystick//                    //Conversion de señal a Valores DECIMALES (int)//      // Esto lo hice asi para que resulte
int CMD_Stop = 1;       // eje x e y en la posicion central   //  >                     1                                   // mas sencillo comprender el envio
int CMD_Adelante = 2;   //  eje y empujado hacia adelante     //  >                     2                                   // de las señales IR
int CMD_Atras = 3;      //  eje y empujado hacia atras        //  >                     3                                   // ya que el standar de los codigos 
int CMD_Derecha = 4;    //  eje x empujado hacia la derecha   //  >                     4                                   // es en hexadecimal
int CMD_Izquierda = 5;  //  eje x empujado hacia la izquierda //  >                     5
int CMD_Bocina = 6;                   //click//                                         6


  // Codigo //
void setup() {
  pinMode(Click, INPUT_PULLUP);
  IrSender.begin(IR);
  Serial.begin(9600);

}

void loop() {
    // comandos //

  int ejx = analogRead(EJEx);
  int ejy = analogRead(EJEy);
  int cmd = CMD_Stop;      //Sin accionar joystick//

  if(digitalRead(Click) == LOW) cmd = CMD_Bocina;         
  else if(ejy < 200) cmd = CMD_Adelante;             // Entre 200 y 400 esta parado en comando adelante/atras //
  else if(ejy > 400) cmd = CMD_Atras;
  else if(ejx < 200) cmd = CMD_Izquierda;             // Entre 200 y 400 esta parado en comando izquierda/derecha //
  else if(ejx > 400) cmd = CMD_Derecha;

  IrSender.sendNEC(0, cmd, 0);  // NEC es el protocolo de com del IR // el primer 0 corresponde a la accion // cmd al comando // el ultimo 0 a las repeticiones de señal //
  delay(500);
   
  Serial.print("x: ");
  Serial.print(analogRead(EJEx));
  Serial.print("  |y: ");
  Serial.print(analogRead(EJEy));                            // Esta parte del codigo me imprime en el monitor los valores 
  Serial.print("  |z: ");                                    // de las acciones que se hagan en el joystick
  Serial.print("  |CMD: ");                                  // a modo de prueba de su funcionamiento
  Serial.print(cmd);
  Serial.print("   |→ ");
  if      (cmd == 1) Serial.print("  |PARADO");
   else if (cmd == 2) Serial.print("  |ADELANTE");
   else if (cmd == 3) Serial.print("  |ATRAS");
   else if (cmd == 4) Serial.print("  |DERECHA");
   else if (cmd == 5) Serial.print("  |IZQUIERDA");
   else if (cmd == 6) Serial.print("  |BOCINA");
  Serial.println(digitalRead(Click));
  delay(200);
}
