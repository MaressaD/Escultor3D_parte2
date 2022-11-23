#include "PutSphere.h"
PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float  r, float  g, float  b, float  a) {
  this->xcenter = xcenter;
  this->ycenter = ycenter;
  this->zcenter = zcenter;
  this->radius = radius;
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}
PutSphere::~PutSphere() {}
void PutSphere::draw(Sculptor &s) {

  int i, j, k, aux, xi, xf, yi, yf, zi, zf;
  float x, y, z;

  xi = xcenter - radius;
  xf = xcenter + radius;

  yi = ycenter - radius;
  yf = ycenter + radius;

  zi = zcenter - radius;
  zf = zcenter + radius;
  
  s.setColor(r, g, b, a);

  for (i = xi; i < xf; i++) {
    for (j = yi; j < yf; j++) {
      for (k = zi; k < zf; k++) {
        aux = (i - xcenter) * (i - xcenter) + (j - ycenter) * (j - ycenter) +
              (k - zcenter) * (k - zcenter);
        if (aux < (radius * radius)) {
          s.putVoxel(i, j, k);
        }
      }
    }
  }
}