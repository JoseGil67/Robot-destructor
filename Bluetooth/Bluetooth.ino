
#include <SoftwareSerial.h>

// Declaración de los pines del Arduino

#define RX 5
#define TX 6
SoftwareSerial BT(RX, TX); //Crea un UART por Software
int EN1 = 10;
int EN2 = 11;
int M1 = 12;
int M2 = 13;


//Initial state


void setup() {

  // CREAMOS PUERTO SERIE
  Serial.begin(9600); //Velocidad de Monitor Serial
  BT.begin(9600); //Velocidad Hc-05

  //Configura los pines de salida
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);

  char crt;

  digitalWrite (M1, HIGH);
  digitalWrite (EN1, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (EN2, LOW);

}

void loop() {
  char crt; //Variable caracter que recibe los datos via Bluetooth

  //Preguntar si hay dato disponible en el puerto serial
  if (BT.available()) {
    crt = BT.read();
    Serial.write(crt);

    if (crt == "S") {
      Parar();
    }
    if (crt == "F") {
      Adelante();
    }
    if (crt == "B") {
      Atras();
    }
  }
}

void Adelante()
{
  digitalWrite (M1, HIGH);
  digitalWrite (EN1, HIGH);
  digitalWrite (M2, HIGH);
  digitalWrite (EN2, HIGH);
}

void Atras()
{
  digitalWrite (M1, LOW);
  digitalWrite (EN1, HIGH);
  digitalWrite (M2, LOW);
  digitalWrite (EN2, HIGH);
}

void Parar()
{
  digitalWrite (M1, HIGH);
  digitalWrite (EN1, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (EN2, LOW);
}
