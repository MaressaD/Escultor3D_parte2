#include "PutEllipsoide.h"
PutEllipsoide::PutEllipsoide(int xcenter, int ycenter, int zcenter, int rx,
                             int ry, int rz) {
  this->xcenter = xcenter;
  this->ycenter = ycenter;
  this->zcenter = zcenter;
  this->rx = rx;
  this->ry = ry;
  this->rz = rz;
}
PutEllipsoide::~PutEllipsoide() {}
void PutEllipsoide::draw(Sculptor &s) {

  int i, j, k;
  float x, y, z, aux;
  for (i = 0; i < nx; i++) {
    for (j = 0; j < ny; j++) {
      for (k = 0; k < nz; k++) {
        x = ((float)(i - xcenter) * (float)(i - xcenter)) / (rx * rx);
        y = ((float)(j - ycenter) * (float)(j - ycenter)) / (ry * ry);
        z = ((float)(k - zcenter) * (float)(k - zcenter)) / (rz * rz);
        aux = x + y + z;
        if (aux < 1) {
          s.SetColor(r, g, b, a);
          s.PutVoxel(r, j, k);
        }
      }
    }
  }
}