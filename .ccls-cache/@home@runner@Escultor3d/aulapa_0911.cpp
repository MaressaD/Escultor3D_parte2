#include "CutEllipsoid.h"
#include "CutSphere.h"
#include "CutVoxel.h"
#include "PutEllipsoid.h"
#include "PutSphere.h"
#include "PutVoxel.h"
#include <fstream>
#include <iostream>

int main() {
  std::vector<figurageometrica *> figs;
  std::vector<figurageometrica *>::iterator itf;

  // abrir arquivo

  std::string s;
  while (fin.good /*verifica se chegou ao fim do arquivo*/) {
    // processa a linha
    fin >> s;
    std::cout << "leu" << s << std::endl;
    if (s.compare("reta") == 0) // compara a string s com a string reta)
    {
      int x0, y0, x1, y1;
      fin >> x0 > y0 >> x1 >> y1;
      fin >> r >> g >> b;
      figs.push_back(new Reta(x0, y0, x1, y1, r, g, b));
    };
    if (s.compare("retangulo") == 0) {
      int x0, y0, x1, y1;
      fin >> x0 > y0 >> x1 >> y1;
      fin >> r >> g >> b;
      figs.push_back(new Retangulo(x0, y0, x1, y1, r, g, b));
    };
    if (s.compare("circulo") == 0) {
      int x0, y0, x1, y1;
      fin >> x0 > y0 >> raio;
      fin >> r >> g >> b;
      figs.push_back(new Circulo(x0, y0, raio, r, g, b));
    };
  }
}
