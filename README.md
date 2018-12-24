# [18-19] Icaro Robotics
Repository for ICARO Project 2018-2019 for Pacinotti students

## Struttura della repository
    .
    ├── elettronica
    │   ├── CAM_settings
    |   ├── design_rule_check
    |   ├── eagle_lib
    |   └── rescue
    |       ├── IcaroRescue_Sol
    |       └── IcaroRescue_TODO
    └── informatica
        └── rescue
            ├── link_utili
            |   └── Icaro 2018-2019.txt
            └── rescue_firmware

La struttura reale contiene molti più file che però non sono molto rilevanti per te.

## Informatica
### Cosa devi fare:
Se sei l'informatico del tuo gruppo, segui questi passi per recuperare il programma su cui lavorare:
1. Scarica il repository tramite il tastone verde **Clone or download** in alto nella pagina
2. Decomprimi il file .zip che hai scaricato, possibilmente dentro una cartella facilmente accessibile
3. Ti consiglio di creare un tuo repository (TODO: Guida per repository) e copiarci dentro la cartella **rescue_firmware** presente nella cartella __informatica/rescue/__. Alternativamente puoi lavorare direttamente all'interno della cartella decompressa.

### Primi passi :)
Il tuo primo obiettivo è quello di far muovere il robot... come facciamo ?
All'interno della cartella __rescue_firmware__ sono presenti questi files

      rescue_firmware/
      ├── rescue_drive.cpp
      ├── rescue_drive.h
      ├── rescue_firmware.ino
      ├── rescue_motore.cpp
      └── rescue_motore.h

Come puoi notare, (apparte rescue_firmware.ino) tutti i file hanno un corrispettivo **.h** e un **.cpp**. Questo perché
in C++ la costruzione di una libreria è suddivisa in due programmi complementari contenuti in questi due files.

Senza allungare troppo la brodaglia, ti ho semplificato il lavoro costruendo uno scheletro di tutti i programmi.
Per far muovere il robot dovrai completare prima rescue_motore **.cpp** seguendo le istruzioni fornite (leggiti anche rescue_motore **.h** in quanto contiene le definizioni delle strutture e delle variabili usate)

Come fai a verificare se il programma funziona ? 
Qui entra in gioco il programma **rescue_firmware.ino** che puoi aprire con __Arduino IDE__. Una volta aperto,
premi la freccia in alto per verificare il programma (oppure premi Ctrl-R) e il compilatore ti dirà se ci sono errori (oppure orrori) di programmazione nei file che hai scritto.

Quando hai terminato di scrivere il programma, puoi caricare il programma su Arduino (TODO) e il robot si muoverà formando un quadrato :)

### Rilevazione degli ostacoli
// TODO


### Seguiamo la linea !
// TODO

### Quasi fatto !
// TODO
##
## Elettronica
### Libreria Icaro (icaro.lbr)
La libreria __icaro.lbr__ contiene i componenti realizzati da voi in questi anni.
Attualmente la libreria contiene:
* __GY31 TCS230__ (Sensore di colore)

### Design Rule Check (DRU)
Il file __Sparkfun.dru__ contiene le regole di design necessarie ad Eagle per testare il tuo circuito, ed assicurarti che non abbia fatto orrori durante la creazione del board.
Per attivarlo segui i seguenti passi:
1) Apri il file .brd del tuo circuito
2) Scegli lo strumento DRC
3) Premi sul tasto __Load...__ e carica il file __Sparkfun.dru__
4) Clicca su __Check__ e osserva gli errori che ti stampa. Il tuo obiettivo è __rimuovere tutti gli errori__

### Rescue Line Sensor
La cartella rescue/__IcaroRescue_TODO/__ contiene alcuni progetti pre completati di sensori di linea. Questo per semplificarti il lavoro di stesura dei componenti visti a lezione (e per evitare a me giorni di debug a capire che orrori hai fatto!).
Il tuo compito è scegliere uno di questi circuiti, completarne la pcb e poi contattarmi per la verifica del circuito... Buon lavoro!

## Reference

__TCS230__ Color Sensor:
1) [HowToMechatronics guide](https://howtomechatronics.com/tutorials/arduino/arduino-color-sensing-tutorial-tcs230-tcs3200-color-sensor/)

2) [TCS230 Sensor Calibration](https://arduinoplusplus.wordpress.com/2015/07/15/tcs230tcs3200-sensor-calibration/)

3) [RGB to HSL](https://www.programmingalgorithms.com/algorithm/rgb-to-hsl?lang=C)
