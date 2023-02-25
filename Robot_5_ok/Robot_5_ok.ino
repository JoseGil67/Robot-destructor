#include <SoftwareSerial.h>
#include <Servo.h>

Servo pulsaBote;

// Declaración de los pines del Arduino
int claxon = 4;
#define RX 5
#define TX 6
SoftwareSerial BT(RX, TX); //Crea un UART por Software
int EN1 = 10;
int EN2 = 11;
int M1 = 12;
int M2 = 13;
int velo = 255;
int velow = 150;
int pinservo = 9;
int pinencender = 3;

void setup() {

  // CREAMOS PUERTO SERIE
  Serial.begin(9600); //Velocidad de Monitor Serial
  BT.begin(9600); //Velocidad Hc-05
  pulsaBote.attach(pinservo);

  //Configura los pines de salida
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(claxon, OUTPUT);
  pinMode(pinencender, OUTPUT);
  digitalWrite (pinencender, LOW);
  digitalWrite (M1, HIGH);
  analogWrite (EN1, 0);
  digitalWrite (M2, HIGH);
  analogWrite (EN2, 0);
  digitalWrite (claxon, HIGH);
  delay (200);
  digitalWrite (claxon, LOW);
  pulsaBote.write(180);
  // TEST

  /*
    delay (1000);
    pulsaBote.write(80);
    delay (1000);
    pulsaBote.write(180);
  */
}

void loop() {


  //Preguntar si hay dato disponible en el puerto serial
  if (BT.available()) {
    char crt = BT.read();
    Serial.write(crt);
    /*
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
    */

    //LLAMARADA
    if (crt == 'X') {
      digitalWrite (pinencender, HIGH);
      pulsaBote.write(80);
      delay (1500);
      digitalWrite (pinencender, LOW);
      pulsaBote.write(180);
    }

    if (crt == 'x') {
      digitalWrite (pinencender, HIGH);
      pulsaBote.write(80);
      delay (1500);
      digitalWrite (pinencender, LOW);
      pulsaBote.write(180);
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
      Tododerecha();
    }
    if (crt == 'L') {
      Todoizquierda();
    }

    if (crt == 'I') {
      Adelantederecha();
    }

    if (crt == 'G') {
      Adelanteizquierda();
    }

    if (crt == 'V') {
      pito();
    }

    if (crt == 'v') {
      nopito();
    }

    if (crt == 'J') {
      AtrasDerecha();
    }

    if (crt == 'H') {
      AtrasIzquierda();
    }

  }
}

void AtrasDerecha()
{
  digitalWrite (M1, LOW);
  analogWrite (EN1, (velow) );
  digitalWrite (M2, LOW);
  analogWrite (EN2, (velo));
}

void AtrasIzquierda()
{
  digitalWrite (M1, LOW);
  analogWrite (EN1, (velo));
  digitalWrite (M2, LOW);
  analogWrite (EN2, (velow));
}



void Adelantederecha()
{
  digitalWrite (M1, HIGH);
  analogWrite (EN1, velo);
  digitalWrite (M2, HIGH);
  analogWrite (EN2, velow);
}

void Adelanteizquierda()
{
  digitalWrite (M1, HIGH);
  analogWrite (EN1, velow);
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
  digitalWrite (EN1, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (EN2, LOW);
}

void Tododerecha()
{
  digitalWrite (M1, LOW);
  analogWrite (EN1, 255);
  digitalWrite (M2, HIGH);
  analogWrite (EN2, 255);
}

void Todoizquierda()
{
  digitalWrite (M1, HIGH);
  analogWrite (EN1, 255);
  digitalWrite (M2, LOW);
  analogWrite (EN2, 255);
}
void pito()
{
  digitalWrite (claxon, HIGH);
}
void nopito()
{
  digitalWrite (claxon, LOW);
}
