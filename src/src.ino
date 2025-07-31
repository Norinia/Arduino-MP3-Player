

#include <SPI.h>      // libraries

#include <SdFat.h>

#include <vs1053_SdFat.h>

SdFat sd;       //SD Karte benennen

vs1053 MP3player;   //MP3 Shield als „MP3Player benennen

int t=6000;       //Der Wert für „t“ gibt im Code den zeitlichen Abstand zwischen dem Abspielen der Datei an.

void setup() {

  if(!sd.begin(SD_SEL, SPI_FULL_SPEED)) sd.initErrorHalt(); //SD Karte mit MP3 Dateien auslesen

  if (!sd.chdir("/")) sd.errorHalt("sd.chdir");

  MP3player.begin();    //MP3 Shield starten

  MP3player.setVolume(60,60); //Die Lautstärke einstellen

}

void loop() {

  MP3player.available();

  MP3player.playTrack(1);     //Das MP3 Shield spielt nun die MP3 Datei mit dem Namen „track001“. Bei einer Datei mit dem Namen „track002“ müsste eine „2“ anstelle der „1“ in diese Klammer.  

  delay(t);               //Vorher festgelegte Pause

}
