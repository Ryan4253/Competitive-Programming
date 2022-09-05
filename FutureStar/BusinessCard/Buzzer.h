#include <Arduino.h>
#include "Song.h"

#ifndef _Buzzer_H
#define _Buzzer_H

class Buzzer{
  public:
  Buzzer(int iPin);

  void playSong(Song iSong);

  void setTone(int freq, int duration = 2<<30);

  void off();

  private:
  int pin;
};

#endif
