#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"

class Sculptor {
protected:
  /**
   * @brief v declara a matriz tridimensional do tipo Voxel
   */
  Voxel ***v;
  /**
   * @brief nx declara a dimensão no eixo x
   * ny declara a dimensão no eixo y
   * nz declara a dimensão no eixo z
   */

  int nx, ny, nz;
  /**
   * @brief r,g,b e a declara as cores atuais do desenho, assim como sua
   * transparência "a"
   */
  float r, g, b, a;

public:
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();
  void setColor(float r, float g, float b, float a);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void writeOFF(const char *filename);
};

#endif // SCULPTOR_H
