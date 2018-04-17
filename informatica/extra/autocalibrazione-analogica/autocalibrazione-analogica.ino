/**
 * @brief Guida alla funzione di autocalibrazione di sensori analogici.
 * 
 * @file autocalibrazione-analogica.ino
 * @author Emanuele Giacomini
 * @date 2018-04-16
 */

// millisecondi necessari alla calibrazione del sensore
#define TEMPO_CALIBRAZIONE 3000

int pin_sensore_da_calibrare = A1;
int soglia_sensore;

/**
 * @brief Inizia il processo di autocalibrazione del sensore
 * attaccato al pin analogico fornito.
 * 
 * Al termine, la funzione restituisce la soglia calcolata.
 * 
 * Per calibrare, il programma si mantiene i valori di lettura minima 
 * e lettura massima visti durante l'intervallo di calibrazione.
 * 
 * Al termine restituisce la media fra minimo e massimo che
 * risulta essere un valore di soglia decente.
 * 
 * @param pin 
 * @return int 
 */
int calibraAnalogico(int pin) {
  int lettura = analogRead(pin);
  int min = lettura, max = lettura;
  unsigned long millis_precedenti = millis();
  while( millis() - millis_precedenti < TEMPO_CALIBRAZIONE) {
    lettura = analogRead(pin);
    if(lettura < min) {
      min = lettura;
    }
    if(lettura > max) {
      max = lettura;
    }
  }
  return (max + min) / 2;
}


void setup() {
  Serial.begin(9600);
  Serial.println("Seriale Inizializzata!");

  pinMode(pin_sensore_da_calibrare, INPUT);

  /**
   * @brief Per far funzionare al meglio la calibrazione, bisogna esporre il sensore
   * alle variazioni di stato.
   * Ad esempio per calibrare il sensore di luce, bisogna esporre il sensore nel periodo di calibrazione
   * sia alla sorgente di luce, che alla condizione di luce normale.
   * 
   * Con un minimo di sforzo e' possibile modificare il programma per far calibrare in parallelo piu' pin :)
   * 
   */
  soglia_sensore = calibraAnalogico(pin_sensore_da_calibrare);
  Serial.print("La soglia calcolata e' : ");
  Serial.println(soglia_sensore);
}

void loop() {

}
