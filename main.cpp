#include "CutBox.h"
#include "CutEllipsoid.h"
#include "CutSphere.h"
#include "CutVoxel.h"
#include "Figurageometrica.h"
#include "PutBox.h"
#include "PutEllipsoid.h"
#include "PutSphere.h"
#include "PutVoxel.h"
#include "sculptor.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(void) {

  vector<Figurageometrica *> figs;
  vector<Figurageometrica *>::iterator itf;
  ifstream fin;
  stringstream ss;
  string s, token;
  int nx, ny, nz;
  float r, g, b, a;

  fin.open("figura5.txt");

  if (!fin.is_open()) {
    cout << "nao abriu arquivo figura\n";
    exit(EXIT_FAILURE);
  }

  while (fin.good() /*verifica se chegou ao fim do arquivo*/) {
    // processa a linha
    getline(fin, s); // tudo q é lido por fin esta sendo armazenado em s
    if (!fin.good()) {
      break;
    } else {
      ss.clear();
      ss.str(s);
      ss >> token;
      if (ss.good()) {
        if (token.compare("dimensoes") == 0) {
          int x, y, z;
          ss >> x >> y >> z;
          nx = x;
          ny = y;
          nz = z;
        }
      }
    }
  }

  cout << nx << endl;
  Sculptor *t;
  t = new Sculptor(nx, ny, nz);

  fin.close();

  fin.open("figura5.txt");

  if (!fin.is_open()) {
    cout << "nao abriu arquivo figura\n";
    exit(EXIT_FAILURE);
  }

  while (fin.good()) {
    getline(fin, s);
    if (!fin.good()) {
      break;
    } else {
      ss.clear();
      ss.str(s);
      ss >> token;
      if (ss.good()) {

        if (token.compare("PutVoxel") == 0) {
          int x, y, z;
          ss >> x >> y >> z >> r >> g >> b >> a;
          figs.push_back(new PutVoxel(x, y, z, r, g, b, a));
        }
        if (token.compare("CutVoxel") == 0) {
          int x, y, z;
          ss >> x >> y >> z;
          figs.push_back(new CutVoxel(x, y, z));
        }
        if (token.compare("PutBox") == 0) {
          int x0, x1, y0, y1, z0, z1;
          ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
          figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        if (token.compare("CutBox") == 0) {
          int x0, y0, x1, y1, z0, z1;
          ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
          figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
        }
        if (token.compare("PutSphere") == 0) {
          int xcenter, ycenter, zcenter, radius;
          ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
          figs.push_back(
              new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
        }
        if (token.compare("CutSphere") == 0) {
          int xcenter, ycenter, zcenter, radius;
          ss >> xcenter >> ycenter >> zcenter >> radius;
          figs.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));
        }
        if (token.compare("PutEllipsoid") == 0) {
          int xcenter, ycenter, zcenter, rx, ry, rz;
          ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
          figs.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz,r, g, b, a));
        }
        if (token.compare("CutEllipsoid") == 0) {
          int xcenter, ycenter, zcenter, rx, ry, rz;
          ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
          figs.push_back(
              new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
        }
      }
    }
  }
  for (size_t i = 0; i < figs.size(); i++) {
    cout << "draw\n";
    figs[i]->draw(*t);
  }

  t->writeOFF((char *)"Escultura.off");

  for (size_t i = 0; i < figs.size(); i++) {
    delete figs[i];
  }
  fin.close();
  delete t;
  return 0;
}
