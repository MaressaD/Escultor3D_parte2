#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "Figurageometrica.h"
#include <iostream>

class CutEllipsoid : public Figurageometrica {
private:
  int xcenter, ycenter, zcenter, rx, ry, rz;

public:
  CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  ~CutEllipsoid();
  void draw(Sculptor &s);
};

#endif