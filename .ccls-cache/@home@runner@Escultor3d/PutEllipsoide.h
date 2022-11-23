#ifndef PUTELLIPSOIDE_H
#define PUTELLIPSOIDE_H
#include "Figurageometrica.h"
#include <iostream>

class PutEllipsoide : public Figurageometrica {
private:
  int xcenter, ycenter, zcenter, rx, ry, rz;
  float r, g, b, a;

public:
  PutEllipsoide(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  ~PutEllipsoide();
  void draw(Sculptor &s);
};

#endif