#include "CutSphere.h"

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius) {
  this->xcenter = xcenter;
  this->ycenter = ycenter;
  this->zcenter = zcenter;
  this->radius = radius;
}
CutSphere::~CutSphere() {}
void CutSphere::draw(Sculptor &s) {
  int i, j, k, aux, xi, xf, yi, yf, zi, zf;
  float x, y, z;
  xi = xcenter - radius;
  xf = xcenter + radius;

  yi = ycenter - radius;
  yf = ycenter + radius;

  zi = zcenter - radius;
  zf = zcenter + radius;

  for (i = xi; i < xf; i++) {
    for (j = yi; j < yf; j++) {
      for (k = zi; k < zf; k++) {
        aux = (i - xcenter) * (i - xcenter) + (j - ycenter) * (j - ycenter) +
              (k - zcenter) * (k - zcenter);
        if (aux < (radius * radius)) {
          s.cutVoxel(i, j, k);
        }
      }
    }
  }
}
