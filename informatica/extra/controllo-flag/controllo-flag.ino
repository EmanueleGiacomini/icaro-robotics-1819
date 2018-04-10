/**
 * @brief Esempio utilizzo flag per una programmazione
 * piu' avanzata
 * 
 * @file controllo-flag.ino
 * @author Emanuele Giacomini
 * @date 2018-04-10
 */

/**
 * @brief Le flag risultano utili poiche' ci permettono di eseguire determinate sezioni di programma
 * solo quando si verificano condizioni molto particolari.
 * Ad esempio, vorremmo poter stampare un messaggio, quando (e solo quando) il robot approccia una salita, e
 * quando conclude tale salita.
 * Ci servira' un sensore di pendenza (Dal nostro punto di vista il sensore di pendenza (tilt switch) e' 
 * un modulo la cui lettura digitale restituisce HIGH quando rileva una pendenza, e LOW altrimenti)
 * 
 * Dal sensore vogliamo ricavare quando il suo stato passa da LOW ad HIGH e viceversa (per poter individuare
 * gli istanti )
 */

int pin_tiltswitch = 12; // Per esempio colleghiamo il circuito del sensore di pendenza al pin 12

/**
 * @brief Ma cosa è una flag in programmazione ?
 * Semplicemente una variabile booleana (può assumere i valori 0 o 1) che descrivono
 * se una condizione si e' verificata o no. Per quanto banale, le flag sono uno strumento
 * molto potente perche' rendono il programma molto più leggibile. 
 */

// Vogliamo che flag_ingresso_pendenza risulti true quando approcciamo la salita
bool flag_ingresso_pendenza = false;
// Vogliamo che flag_uscita_pendenza risulti true quando usciamo dalla salita
bool flag_uscita_pendenza = false;

/**
 * @brief Utilizzeremo una funzione chiamata readTilt che interpretera' la lettura del sensore di pendenza
 * per impostare di conseguenza le flag. Osserviamo che le due flag non possono
 * risultare true contemporaneamente
 * 
 * In oltre la funzione chiedera' due parmetri aggiuntivi che rappresentano le locazioni di memoria
 * delle flag di ingresso e uscita dalla pendenza
 */



void readTilt(int pin, bool* flag_in, bool* flag_out) {
    /**
     * @brief Interroga il sensore di pendenza ed imposta le flag di in/out 
     * di conseguenza.
     * 
     * @param pin : pin di collegamento del circuito di pendenza
     * @param flag_in : pointer a flag_ingresso
     * @param flag_out : pointer a flag_uscita
     */

    /**
     * @brief Per individuare gli stati di ingresso / uscita, la via piu'
     * semplice e' quella di analizzare quando lo stato del sensore cambia da
     * LOW ad HIGH e viceversa. Ci salviamo allora una variabile STATIC (in modo
     * da memorizzare un valore ) che contiene lo stato precedente del sensore.
     * Quando lo stato attuale e' diverso da quello precedente, significa che sono
     * uscito o entrato nella fase di salita.
     */

    static bool stato_prec = 0;
    bool stato = digitalRead(pin);

    if(stato != stato_prec) {
        if(stato = HIGH) {
            // stato_prec == 0 e stato == 1 dunque sono entrato nella salita
            *flag_in = true;
        } else {
            // stato_prec == 1 e stato == 0 dunque sono uscito dalla salita
            *flag_out = true;
        }        
    }
    stato_prec = stato;
}

void setup() {
    Serial.begin(9600);
    Serial.println("Seriale inizializzata!");

    pinMode(pin_tiltswitch, INPUT);

}

/**
 * @brief Con la funzione scritta in precedenza possiamo ora definire una routine da eseguire
 * quando una delle flag viene attivata. Nel caso in esempio, vogliamo aumentare la nostra
 * velocita quando siamo sulla salita, e riportarla alla velocita normale, una volta terminata
 * la salita.
 */

void loop() {

    readTilt(pin_tiltswitch, &flag_ingresso_pendenza, &flag_uscita_pendenza);
    if(flag_ingresso_pendenza) {
        flag_ingresso_pendenza = false;
        // velocita += 50;
    }
    if(flag_uscita_pendenza) {
        flag_uscita_pendenza = false;
        // velocita -= 50;
    }
    
}