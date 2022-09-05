#include "Button.h"

AbstractButton::AbstractButton(Adafruit_ILI9341* iInst, FillType iType, int iOnColor, int iOffColor){
  inst = iInst;
  fillType = iType;
  onColor = iOnColor;
  offColor = iOffColor;
}

AbstractButton::AbstractButton(Adafruit_ILI9341* iInst, FillType iType, int iColor){
  inst = iInst;
  fillType = iType;
  onColor = iColor;
  offColor = iColor;
}

bool AbstractButton::isEnabled() const{
  return !isDisabled;
}



RoundButton::RoundButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iR, int iOnColor, int iOffColor) : AbstractButton(iInst, iType, iOnColor, iOffColor){
  x = iX, y = iY, r = iR;
}
RoundButton::RoundButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iR, int iColor) : AbstractButton(iInst, iType, iColor){
  x = iX, y = iY, r = iR;
}

void RoundButton::render(){
  if(fillType == FillType::FILL){
    inst->fillCircle(x, y, r, onColor);
  }
  else{
    inst->drawCircle(x, y, r, onColor);
  }
  isDisabled = false;
}

void RoundButton::hide(){
  if(fillType == FillType::FILL){
    inst->fillCircle(x, y, r, offColor);
  }
  else{
    inst->drawCircle(x, y, r, offColor);
  }
  isDisabled = true;
}

bool RoundButton::isPressed(int px, int py) const{
  return (x-px) * (x-px) + (y-py) * (y-py) < r * r;
}



RectButton::RectButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iW, int iH, int iOnColor, int iOffColor) : AbstractButton(iInst, iType, iOnColor, iOffColor){
  this->x1 = iX;
  this->y1 = iY;
  this->x2 = iX+iW;
  this->y2 = iY+iH;
  this->w = iW;
  this->h = iH;
}

RectButton::RectButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iW, int iH, int iColor) : AbstractButton(iInst, iType, iColor){
  this->x1 = iX;
  this->y1 = iY;
  this->x2 = iX+iW;
  this->y2 = iY+iH;
  this->w = iW;
  this->h = iH;
}
  
void RectButton::render(){
  if(fillType == FillType::FILL){
    inst->fillRect(x1, y1, w, h, onColor);
  }
  else{
    inst->drawRect(x1, y1, w, h, onColor);
  }
  isDisabled = false;
}

void RectButton::hide(){
  if(fillType == FillType::FILL){
    inst->fillRect(x1, y1, w, h, offColor);
  }
  else{
    inst->drawRect(x1, y1, w, h, offColor);
  }
  isDisabled = true;
}

bool RectButton::isPressed(int px, int py) const{
  if(isDisabled){
    return false;
  }

  if(px > x1 && px < x2 && py > y1 && py < y2){
    return true;
  }

  return false;
}



RoundRectButton::RoundRectButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iW, int iH, int iR, int iOnColor, int iOffColor) : RectButton(iInst, iType, iX, iY, iW, iH, iOnColor, iOffColor){
  r = iR;
}

RoundRectButton::RoundRectButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iW, int iH, int iR, int iColor) : RectButton(iInst, iType, iX, iY, iW, iH, iColor){
  r = iR;
}
  
void RoundRectButton::render(){
  if(fillType == FillType::FILL){
    inst->fillRoundRect(x1, y1, w, h, r, onColor);
  }
  else{
    inst->drawRoundRect(x1, y1, w, h, r, onColor);
  }
}

void RoundRectButton::hide(){
  if(fillType == FillType::FILL){
      inst->fillRoundRect(x1, y1, w, h, r, offColor);
  }
  else{
    inst->drawRoundRect(x1, y1, w, h, r, offColor);
  }
}



RoundSymbolButton::RoundSymbolButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iR, char iSymbol, int iOnColor, int iOffColor) : RoundButton(iInst, iType, iX, iY, iR, iOnColor, iOffColor){
  symbol = iSymbol;
}

RoundSymbolButton::RoundSymbolButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iR, char iSymbol, int iColor) : RoundButton(iInst, iType, iX, iY, iR, iColor){
  symbol = iSymbol;
}

void RoundSymbolButton::render(){
  
}

void RoundSymbolButton::hide(){
  
}

char RoundSymbolButton::getSymbol() const{
  return symbol;
}
