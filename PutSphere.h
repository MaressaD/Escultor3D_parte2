#ifndef PUTSPHRE_H
#define PUSPHERE_H
#include "Figurageometrica.h"
#include <iostream>

class PutSphere : public Figurageometrica {
private:
  int xcenter, ycenter, zcenter, radius;
  float r, g, b, a;

public:
  PutSphere(int xcenter, int ycenter, int zcenter, int radius, float  r, float  g, float  b, float a);
  ~PutSphere();
  void draw(Sculptor &s);
};

#endif