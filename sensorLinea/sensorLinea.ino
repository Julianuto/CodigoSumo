int SENSOR = 8;
int resultado;
void setup() {
  // put your setup code here, to run once:
  pinMode(SENSOR,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  resultado=analogRead(SENSOR);
  delay(100);
  Serial.println(resultado);
    delay(100);


}
