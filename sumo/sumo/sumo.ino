
#include <QTRSensors.h>         //Pololu QTR Sensor Library

//***********DEFINE PARAMETERS*************************
#define LeftSense1   10   //Left Line Sensor Pin
#define RightSense1   A0   //Right Line Sensor Pin 
#define LeftSense2   2   //Left Line Sensor Pin
#define RightSense2   A3   //Right Line Sensor Pin 

#define interrup 4
#define pin13 13
#define B1 3
#define B2 5
#define A1 6
#define A2 9

int start=1;
int  ech1= 12;
int trig1= 11;
int  ech2= 8;
int trig2= 7;

int lectura=0;  
float cm=0;
int sleft1,sright1,sleft2,sright2=0;
int distancia,tiempo=0;
int distancia2,tiempo2=0;
int vel1=255;
int vel2=130;
//*******************************************************

//Create QTR Sensor Line Following Object
QTRSensorsRC qtrrc((unsigned char[]) {LeftSense1, RightSense1,LeftSense2, RightSense2},4,2500, QTR_NO_EMITTER_PIN);
unsigned int sensorValues[4];
void avanzar (void);
void retroceder (void);
void izquierda (void);
void derecha (void);
void detener (void);
void imprimir (void);
void setup()
{
  Serial.begin(9600);  
  pinMode(B1,OUTPUT);
  pinMode(B2,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(pin13,OUTPUT);
  pinMode(interrup,INPUT);
  pinMode(ech1,INPUT);
  pinMode(trig1,OUTPUT);
  pinMode(ech2,INPUT);
  pinMode(trig2,OUTPUT);

}

void loop()
{

while(start==HIGH)  
{ int i=0;

  start=digitalRead(interrup);
  Serial.println(interrup);
  if(start==LOW)
    for(i=0;i<4;i++)
      {digitalWrite(pin13,HIGH);
      delay(500);
      digitalWrite(pin13,LOW);  
      delay(500);  
        }   
    }

///////////////////////////////////////////
qtrrc.read(sensorValues);             
if(sensorValues[0]>1000)
sleft1=1;
else
sleft1=1;
if(sensorValues[1]>1000)
sright1=1;
else
sright1=1;

if(sensorValues[2]>1000)
sleft2=1;
else
sleft2=1;
if(sensorValues[3]>1000)
sright2=1;
else
sright2=1;



/////////sensor atrás///////////////// 
 digitalWrite(trig1,LOW);
 delayMicroseconds(10);
 digitalWrite(trig1,HIGH);
 delayMicroseconds(10); 
 digitalWrite(trig1,LOW);
 lectura=digitalRead(ech1);
 tiempo =pulseIn(ech1,HIGH);
 distancia=(tiempo*0.017);

///////sensor delante//////////
 digitalWrite(trig2,LOW);
 delayMicroseconds(10);
 digitalWrite(trig2,HIGH);
 delayMicroseconds(10); 
 digitalWrite(trig2,LOW);
 tiempo2 =pulseIn(ech2,HIGH);
 distancia2=(tiempo2*0.017);
///////IMPRIMIR///////////////////// 
 imprimir();
 avanzar();
 retroceder();
 derecha();
 izquierda();
detener();
//////////CONTROL///////////////////
 if((sleft2==0 || sright2==0)||(sleft2==0 && sright2==0))
  {retroceder();delay(500);Serial.println("linea adelante");}
 else 
 {
  if((sleft1==0 || sright1==0)||(sleft1==0 && sright1==0)) 
   {avanzar();delay(500);Serial.println("linea tracera");
    }
   else
    {if(sleft1==1 && sright1==1 && sleft2==1 && sright2==1)
      {if(distancia2 <30)
         {Serial.println("ataque");
          avanzar();
           }
      else
          {if(distancia<20)
              {
                Serial.println("ataque tracero");
                derecha();
                delay(1000);
                }
           else 
              {izquierda();
                Serial.println("busqueda");
                }
            }   
        }  
      } 
  } 






////////////////////////////
//motores


}
void avanzar()
{analogWrite(B1,vel1);
 analogWrite(B2,0);
 analogWrite(A1,vel1); 
 analogWrite(A2,0);
  }
void retroceder()
{analogWrite(B1,0);
 analogWrite(B2,vel1);
 analogWrite(A1,0); 
 analogWrite(A2,vel1);
  }
void izquierda()
{analogWrite(B1,0);
 analogWrite(B2,vel2);
 analogWrite(A1,vel2); 
 analogWrite(A2,0);
  }
void derecha()
{analogWrite(B1,vel2);
 analogWrite(B2,0);
 analogWrite(A1,0); 
 analogWrite(A2,vel2);
  }
void detener()
{analogWrite(B1,0);
 analogWrite(B2,0);
 analogWrite(A1,0); 
 analogWrite(A2,0);
  }
  
void imprimir ()
{ Serial.print("Left1: ");
  Serial.print(sleft1);
  Serial.print(" Right1: ");
  Serial.print(sright1);
  Serial.print(" Left2: ");
  Serial.print(sleft2);
  Serial.print(" Right2: ");
  Serial.print(sright2);
  
  
  
  Serial.print(" DISTANCIA: ");
  Serial.print(distancia);
  Serial.print("  DISTANCIA2: ");
  Serial.println(distancia2);

  delay(10);
    }
  

  
  
