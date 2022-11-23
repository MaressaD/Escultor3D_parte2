#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "Figurageometrica.h"
#include <iostream>

class PutEllipsoid : public Figurageometrica {
private:
  int xcenter, ycenter, zcenter, rx, ry, rz;
  float r, g, b, a;

public:
  PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float  r, float  g, float  b, float a);
  ~PutEllipsoid();
  void draw(Sculptor &s);
};

#endif