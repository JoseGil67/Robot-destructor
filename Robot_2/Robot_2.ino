
#include <SoftwareSerial.h>

// Declaración de los pines del Arduino
int claxon = 4;
#define RX 5
#define TX 6
SoftwareSerial BT(RX, TX); //Crea un UART por Software
int EN1 = 10;
int EN2 = 11;
int M1 = 12;
int M2 = 13;
int velo = 250;


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
  pinMode(claxon, OUTPUT);


  digitalWrite (M1, HIGH);
  analogWrite (EN1, 0);
  digitalWrite (M2, HIGH);
  analogWrite (EN2, 0);
  digitalWrite (claxon, HIGH);
  delay (200);
  digitalWrite (claxon, LOW);
}

void loop() {


  //Preguntar si hay dato disponible en el puerto serial
  if (BT.available()) {
    char crt = BT.read();
    Serial.write(crt);

    // CONTROL VELOCIDAD

    if (crt == '0') {
      velo = 100;
    }

    if (crt == '1') {
      velo = 120;
    }
    if (crt == '2' ) {
      velo = 135 ;
    }
    if (crt == '3' ) {
      velo = 150 ;
    }
    if (crt == '4' ) {
      velo = 165 ;
    }
    if (crt == '5' ) {
      velo = 180 ;
    }
    if (crt == '6' ) {
      velo = 195 ;
    }
    if (crt == '7' ) {
      velo = 210 ;
    }
    if (crt == '8' ) {
      velo = 230 ;
    }
    if (crt == '9' ) {
      velo = 255 ;
    }


    // CONTROL DIRECCION

    if (crt == 'S') {
      Parar();
    }
    if (crt == 'F') {
      Adelante();
    }
    if (crt == 'B') {
      Atras();
    }
    if (crt == 'R') {
      Giroderecha();
    }
    if (crt == 'L') {
      Giroizquierda();
    }

  }
  if (crt == 'I') {
    Derecha();
  }

}
if (crt == 'G') {
  Izquierda();
}


if (crt == 'V') {
  pito();
}

if (crt == 'v') {
  nopito();
}
}
}

void Derecha()
{
  digitalWrite (M1, HIGH);
  analogWrite (EN1, velo);
  digitalWrite (M2, HIGH);
  analogWrite (EN2, (velo / 2));
}

void Izquierda()
{
  digitalWrite (M1, HIGH);
  analogWrite (EN1, (velo / 2));
  digitalWrite (M2, HIGH);
  analogWrite (EN2, velo);
}


void Adelante()
{
  digitalWrite (M1, HIGH);
  analogWrite (EN1, velo);
  digitalWrite (M2, HIGH);
  analogWrite (EN2, velo);
}

void Atras()
{
  digitalWrite (M1, LOW);
  analogWrite (EN1, velo);
  digitalWrite (M2, LOW);
  analogWrite (EN2, velo);
}

void Parar()
{
  digitalWrite (M1, HIGH);
  digitalWrite (EN1, 0);
  digitalWrite (M2, HIGH);
  digitalWrite (EN2, 0);
}

void Giroderecha()
{
  digitalWrite (M1, HIGH);
  analogWrite (EN1, velo);
  digitalWrite (M2, LOW);
  analogWrite (EN2, velo);
}

void Giroizquierda()
{
  digitalWrite (M1, LOW);
  analogWrite (EN1, velo);
  digitalWrite (M2, HIGH);
  analogWrite (EN2, velo);
}
void pito()
{
  digitalWrite (claxon, HIGH);
}
void nopito()
{
  digitalWrite (claxon, LOW);
}
