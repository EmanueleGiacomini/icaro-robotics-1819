/* 
per i vettori:
pixy.line.numVectors
per le intersezioni:
pixy.line.numVectors
*/

#include<SPI.h>
#include<Pixy2.h>
#include<Pixy2Line.h>

Pixy2 pixy;

void setup()
{
    Serial.begin(9600);
    Serial.println("INIZIALIZZAZIONE LINEA...");

    pixy.init();  //inizializzo gli oggetti della pixy
    pixy.changeProg("line");  //cambio il programma per passare a quello delle linee...
    uint8_t blocco;
    uint8_t i;
    blocco = pixy.line.getMainFeatures();
}

void loop()
{
    uint8_t i;
    for(i=0; i<pixy.line.numVectors; i++)
    {
        pixy.line.vectors[i].print();
    }
}