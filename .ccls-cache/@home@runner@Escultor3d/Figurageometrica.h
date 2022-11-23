#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"
#include <iostream>

class Figurageometrica {
protected:
  float r, g, b, a;

public:
  Figurageometrica();
  virtual ~Figurageometrica();
  virtual void draw(Sculptor &s)=0;
};

#endif
