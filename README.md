# PROYECTO-EN-ARDUINO
AUTO A CONTROL REMOTO VIA IR (infrarrojo)

Componentes Utilizados en Control Remoto

- Arduino UNO
- Sensor Emisor Infrarrojo IR (extraido del Modulo Diodo Tansmisor Infrarrojo Emisor Ir Ky-005 porque estaba quemada la plaquita)
- Módulo JoyStick biaxial XY KY-023
- Resistencia 220 ohm
- Bateria 9Vcc

Componentes Utilizados en Auto

- Arduino UNO
- Sensor Receptor de infrarrojos (Extraido de una tele sin funcionar)
- Módulo L9110 (para controlar ambos motores)
- Motor 5v
- Motor 9v
- LED rojo
- Resistencia 220 ohm
- Switch encendido/apagado (para la alimentacion externa de ambos motores y modulo L9110)
- Baterias 9vcc


En este proyecto de la Materia "Taller de Robotica" se desarrollo con arduino un auto a control remoto via infrarrojo.
Se utilizo dos arduinos, uno para el control y otro para el auto.

En el control se utilizo un diodo emisor de infrarrojos conrrespondiente al modulo Ky-005, pero sin el modulo ya que esta se encontraba quemada y para el correcto funcionamiento del emisor se tuvo que conectar con una resistencia de 220 ohm.
Tambien se utilizo un Módulo JoyStick biaxial XY KY-023 para enviar las señales de marcha al auto. El Eje "X" del joystick correspone al giro izquierda/derecha del auto, el Eje "Y" al avance y retroceso y el Switch (click) para encender y apagar un led.

En el Auto se utilizo un receptor de infrarrojos extraido de una tele para recibir las señales del control, a este led no es necesario conectarle con una resistencia porque trabaja con 5v y se conecto directamente a arduino.
Se utilizo un motor de 9Vcc para la traccion y uno de 5vcc* para el giro, siendo el encargado de estas acciones el Módulo L9110.            *el motor de 5vcc tiene como tension maxima de trabajo hasta 9vcc segun fabricante*.


En el Codigo se utilizo la libreria de Shirrif (#include <IRremote.hpp>) en ambos arduinos.
En el control no se utilizaron valores hexadecimales como suele ser el standard (ademas estos codigos corresponden a controles remotos tales como los de las teles, dvds, tiras led ,etc). Se crearon codigos propios y en valores decimales para que sea mas
sencilla su interpretacion. El valor 1 que envia el control al auto significa "parado". El 2 adelante, 3 atras, 4 derecha, 5 izquierda y 6 es el click que enciende el led.
Cuando el auto recibe el valor numero 2 (o sea, el joystick empujado hacia adelante) se activa el pin "5" en arduino que a su vez envia la señal al Módulo L9110 y hace funcionar al motor. Esto se aplica igual cuando empujamos el joystick hacia atras y el auto retrocede,
en ese caso el pin que se activa es el "6".
Lo mismo ocurre para los giros de derecha a izquierda con sus respectivos pines.

El proyecto busca demostrar el funcionamiento de arduino y sus componentes. No busca ser viable, como juguete por ejemplo, ya que tiene varias limitaciones. 
El infrarrojo no tiene mucha alcance y eso perjudica el correcto funcionamiento de ambos dispositivos (control y auto). Por ejemplo, si se envia la señal 2 (correspondiente al avance del auto), cuando el auto se aleje demasiado del control este se quedara con esa señal recibida y por ende no se frenara. 
Es necesario operar dentro del alcance o bien modificar el codigo para que el auto se pare cuando deje de recibir señal.
Ademas es susceptible a otras señales por lo que perjudica la comunicacion entre ambos dispositivos. Los mismos motores generan ruido electrico que puede reducir la calidad de la señal del infrarrojo.



