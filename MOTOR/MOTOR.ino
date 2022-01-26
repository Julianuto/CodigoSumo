int IN3 = 5; 
int IN4 = 4;
int IN2 = 2;
int IN1 =3;
int IN13 = 13; 
int IN12 = 12; 

void setup()
{
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin 4 
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin 5
  pinMode (IN13, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN1, OUTPUT);
   pinMode (IN12, OUTPUT);
}
void loop()
{
  analogWrite(IN13,250);
  analogWrite(IN12,250);
  // Motor gira en un sentido
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW); 
    digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW); 
  delay(4000);
  // Motor no gira
  digitalWrite (IN4, LOW); 
   digitalWrite (IN2, LOW); 
  delay(500);

  // Motor gira en sentido inverso
  digitalWrite (IN3, HIGH);
    digitalWrite (IN1, HIGH);
  delay(4000);
  // Motor no gira
  digitalWrite (IN3, LOW); 
    digitalWrite (IN1, LOW); 
  delay(5000);

}
