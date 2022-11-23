#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "Figurageometrica.h"
#include <iostream>

class PutVoxel : public Figurageometrica {
  int x, y, z;
  float r, g, b, a;

public:
  PutVoxel(int x, int y, int z, float  r, float  g, float  b, float a);
  ~PutVoxel();
  void draw(Sculptor &s);
};

#endif