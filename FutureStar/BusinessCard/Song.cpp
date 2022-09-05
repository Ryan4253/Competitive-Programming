#include "Song.h"

SongSegment::SongSegment(int iNote, Length iLength){
  note = iNote, length = iLength;
}

Song::Song(int iTempo, std::vector<SongSegment> iSong) : song(iSong){
  tempo = iTempo;
  int beat = 0;
  for(auto t : song){
    beat += t.length;
  }

  duration = (beat / 4) / tempo * 60 * 1000;
}

int Song::getTempo() const{
  return tempo;
}

SongSegment Song::getSegment(int index) const{
  if(index < 0 || index >= song.size()){
    return {0, Sixteenth};
  }

  return song[index];
}

int Song::size() const{
  return song.size();
}
