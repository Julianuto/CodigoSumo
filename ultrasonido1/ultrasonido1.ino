#include <LiquidCrystal.h> // incluimos librerias del LCD
LiquidCrystal lcd(12,11,5,4,3,2); //declaramos los pines del arduino 

// Declaramos que el pin Trig del ultrasonico sera el pin 9 del arduino, y que el pin Echo sera el 8
int trig = 7; 
int echo = 6; 

float t; // variable t=tiempo
float d; // variable d=distancia

void setup() {

//Establecemos con PinMode si el pin sera OUTPUT o INPUT
pinMode(echo, INPUT);
pinMode(trig, OUTPUT);

Serial.begin(9600); //Iniciamos el serial monitor

lcd.begin(16,2); // iniciamos el LCD y le decimos el tamaÃ±o del display (16x2) 
lcd.clear(); // limpiamos el LCD

lcd.setCursor(0,0); // para establecer el cursor arriba a la izquierda
lcd.print("Dist:"); // Texto del primer renglon
lcd.setCursor(0,1); // para establecer abajo a la izquierda
lcd.print("Coloque objeto"); // Texto del segundo renglon

}

void loop() {

/*    El sensor utrasonico funciona por medio de pulsos 
      que envia al objeto a medir, y la distancia es proporcional 
      a la duracion del pulso, por lo tanto usaremos la ecuacion fisica d=v*t
*/

digitalWrite(trig, HIGH); // Establecemos el valor del pin HIGH(5V)
delayMicroseconds(1000); // Espera un segundo
digitalWrite(trig, LOW); // Valor del pin LOW(0V)

d = pulseIn(echo, HIGH); //Para leer cuando Echo sea HIGH
d = (d/ 2) / 29.1; //Ecuacion
delay(100);


// Este sensor es capaz de detectar hasta 5 mts.
if (d < 200) // Le damos instruccion para que si es menor de 5 mts continue
{
     if (d < 100) //Si es menor de 1 m, desplegara la informacion en cm.
    {
      //Para imprimirlo en el serial monitor:
      Serial.print("Distancia: ");
      Serial.println(d);
      
      //Para imprimirlo en el LCD:
      lcd.setCursor(0,0);             
      lcd.print("Dist:          ");   
      lcd.setCursor(7,0);             
      lcd.print(d);
      lcd.print(" cm");
    }

        if (d >= 100) //Si es mayor a 1 m, lo despliega en mts.
    {
      Serial.print("Distancia: ");
      Serial.println(d);
      
      
      //En el LCD
      lcd.setCursor(0,0);
      lcd.print("Dist.:          ");
      lcd.setCursor(7,0);
      lcd.print(d/100);
      lcd.print(" m");
    }  
  }

else //Si es mayor 5mts, especifique que el objeto esta fuera de rango
  {
    Serial.print("FUERA DE RANGO");
    
    lcd.setCursor(0,0);
    lcd.print(" FUERA DE RANGO ");

    
  }
  
}
