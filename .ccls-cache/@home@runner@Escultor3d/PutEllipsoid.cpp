#include "PutEllipsoid.h"
PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx,int ry, int rz, float  r, float  g, float b, float  a) {
  this->xcenter = xcenter;
  this->ycenter = ycenter;
  this->zcenter = zcenter;
  this->rx = rx;
  this->ry = ry;
  this->rz = rz;
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}
PutEllipsoid::~PutEllipsoid() {}
void PutEllipsoid::draw(Sculptor &s) {
  int i, j, k, xi, xf, yi, yf, zi, zf;
  float x, y, z, aux;

  xi = xcenter - rx;
  xf = xcenter + rx;

  yi = ycenter - ry;
  yf = ycenter + ry;

  zi = zcenter - rz;
  zf = zcenter + rz;

  s.setColor(r, g, b, a);

  for (i = xi; i < xf; i++) {
    for (j = yi; j < yf; j++) {
      for (k = zi; k < zf; k++) {
        x = ((float)(i - xcenter) * (float)(i - xcenter)) / (rx * rx);
        y = ((float)(j - ycenter) * (float)(j - ycenter)) / (ry * ry);
        z = ((float)(k - zcenter) * (float)(k - zcenter)) / (rz * rz);
        aux = x + y + z;
        if (aux < 1) {
          s.putVoxel(r, j, k);
        }
      }
    }
  }
}