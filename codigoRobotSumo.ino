
float t; // variable t=tiempo
float d; // variable d=distancia
float d1; // variable d=distancia

// Declaramos que el pin Trig del ultrasonico uno
int trig = 7;
int echo = 6;
//declaramos pines para untrasonico 2
int trig1 = 10;
int echo1 = 11;
//declaramos pines para motores
int IN3 = 5;
int IN4 = 4;
int IN2 = 2;
int IN1 = 3;
int IN13 = 13;
int IN12 = 12;

void setup()
{
  Serial.begin(9600);

  //Establecemos con PinMode si el pin sera OUTPUT o INPUT
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);


  //establecemos PinMode de los motores 1 y 2
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin 4
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin 5
  pinMode (IN13, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN12, OUTPUT);
}
void loop()
{
  //declaramos los pwm
  analogWrite(IN13, 250);
  analogWrite(IN12, 250);
do {
  digitalWrite(trig, HIGH); // Establecemos el valor del pin HIGH(5V)
  delayMicroseconds(1000); // Espera un segundo
  digitalWrite(trig, LOW); // Valor del pin LOW(0V)

  d = pulseIn(echo, HIGH); //Para leer cuando Echo sea HIGH
  d = (d / 2) / 29.1; //Ecuacion
  delay(100);
  
  Serial.println(d);

  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW);
  digitalWrite (IN2, LOW);
  digitalWrite (IN1, LOW);
    
  } while (d < 40);
  
if ( d>40){
  Serial.print("FUERA DE RANGO");
  
  digitalWrite (IN4, LOW);
  digitalWrite (IN3, LOW);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
}

  digitalWrite(trig1, HIGH); // Establecemos el valor del pin HIGH(5V)
    delayMicroseconds(1000); // Espera un segundo
    digitalWrite(trig1, LOW); // Valor del pin LOW(0V)

    d1 = pulseIn(echo1, HIGH); //Para leer cuando Echo sea HIGH
    d1 = (d1/ 2) / 29.1; //Ecuacion
    delay(100);

    Serial.println(d);
}
  
