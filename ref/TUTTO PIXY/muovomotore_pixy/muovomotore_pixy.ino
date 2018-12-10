#include <SPI.h>  
#include <Pixy.h>

#define PIN_MOTOR_DIR = 12;
#define PIN_MOTOR_PWM = 11;
Pixy pixy;

void setup()
{

  Serial.begin(9600);
  Serial.print("INIZIO...");
  Serial.print("ASPETTO OGGETTO");

  pixy.init();
}

void loop()
{ 
  static int i = 0;
  int j;
  uint16_t acquisizione;
  char buf[32]; 
  uint16_t puppa;
  acquisizione = pixy.getBlocks();
  puppa = pixy.blocks[i].height;
  
  if (acquisizione)
  {
    i++;
    
    if (i%50==0)
    {
      sprintf(buf, "VISTA %d:\n", acquisizione);   //sprintf = Serial.print;
      Serial.print(buf);
      for (j=0; j<acquisizione; j++)
      {
        sprintf(buf, "CORDINATE %d: ", j);
        Serial.print(buf); 
        pixy.blocks[j].print();
        Serial.println(puppa);
      }
    }
  
  }
}
//%50
