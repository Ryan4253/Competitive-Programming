#include "Buzzer.h"

Buzzer::Buzzer(int iPin) : pin(iPin){}

void Buzzer::playSong(Song song){
  for(int i = 0; i < song.size(); i++){
      auto t = song.getSegment(i);
      int duration = t.length * 15000 / song.getTempo();
      setTone(t.note, duration * 0.9);
      delay(duration);
      off();
  }
}

void Buzzer::setTone(int freq, int duration){
  tone(pin, freq, duration);
}

void Buzzer::off(){
  noTone(pin);
}
