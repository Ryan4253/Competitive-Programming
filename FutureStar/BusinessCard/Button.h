#include "Adafruit_ILI9341.h"
#include <cmath>

#ifndef _Button_H
#define _Button_H

enum class FillType{
  FILL, OUTLINE
};

class AbstractButton{
  public:  
  AbstractButton(Adafruit_ILI9341* iInst, FillType iType, int iOnColor, int iOffColor);
  AbstractButton(Adafruit_ILI9341* iInst, FillType iType, int iColor);

  virtual void render() = 0;
  virtual void hide() = 0;
  virtual bool isPressed(int x, int y) const = 0;
  bool isEnabled() const;
  
  protected:
  Adafruit_ILI9341* inst;
  int onColor, offColor;  
  bool isDisabled = false;
  FillType fillType;
};

class RoundButton : public AbstractButton{
  public:
  RoundButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iR, int iOnColor, int iOffColor);
  RoundButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iR, int iColor);

  void render() override;
  void hide() override;
  bool isPressed(int px, int py) const override;

  protected:
  int x, y, r;
};

class RectButton : public AbstractButton{
  public:
  RectButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iW, int iH, int iOnColor, int iOffColor);
  RectButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iW, int iH, int iColor);
  
  void render() override;
  void hide() override;
  bool isPressed(int px, int py) const override;

  protected:
  int x1, y1, x2, y2, w, h;
};

class RoundRectButton : public RectButton{
  public:
  RoundRectButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iW, int iH, int iR, int iOnColor, int iOffColor);
  RoundRectButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iW, int iH, int iR, int iColor);
  
  void render() override;
  void hide() override;
  
  protected:
  int r;
};

class RoundSymbolButton : public RoundButton{
  public:
  RoundSymbolButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iR, char iSymbol, int iOnColor, int iOffColor);
  RoundSymbolButton(Adafruit_ILI9341* iInst, FillType iType, int iX, int iY, int iR, char iSymbol, int iColor);

  void render() override;
  void hide() override;
  char getSymbol() const;

  protected:
  char symbol;
};



#endif
