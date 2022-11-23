#include "sculptor.h"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>

/*!
 * @brief Sculptor::Sculptor implementa o Construtor da classe Sculptor
 * @param _nx inicializa a dimensao x em nx
 * @param _ny inicializa a dimensao y em ny
 * @param _nz inicializa a dimensao z em nz
 */
Sculptor::Sculptor(int _nx, int _ny, int _nz) {

  nx = _nx;
  ny = _ny;
  nz = _nz;

  int i, j, k;
  v = new Voxel **[nx];

  for (i = 0; i < nx; i++) {
    v[i] = new Voxel *[ny];
  }

  for (i = 0; i < nx; i++) {
    for (j = 0; j < ny; j++) {
      v[i][j] = new Voxel[nz];
    }
  }

  for (i = 0; i < nx; i++) {
    for (j = 0; j < ny; j++) {
      for (k = 0; k < nz; k++) {
        v[i][j][k].r = 0.5;
        v[i][j][k].g = 0.5;
        v[i][j][k].b = 0.5;
        v[i][j][k].a = 0.5;
        v[i][j][k].isOn = false;
      }
    }
  }
}
/**
 * @brief Sculptor::~Sculptor destrutor da classe Scultor
 * @brief Libera memória da matriz tridimensional de Voxels e coloca as
 * dimensões em valor nulo
 */

Sculptor::~Sculptor() {
  int i, j;
  nx = 0;
  ny = 0;
  nz = 0;

  for (i = 0; i < nx; i++) {
    for (j = 0; j < ny; j++) {
      delete[] v[i][j];
    }
  }

  for (i = 0; i < nx; i++) {
    delete[] v[i];
  }

  delete[] v;
}
/**
 * @brief Sculptor::setColor Responsável por atribuir para a cor da imagem os
 * valores r, g e b dos parametros
 * @param r intensidade da cor vermelha
 * @param g intensidade da cor verde
 * @param b intensidade da cor azul
 * @param a intensidade da transparência
 */
void Sculptor::setColor(float r, float g, float b, float a) {
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}
/**
 * @brief Sculptor::putVoxel Cria um Voxel nas coordenadas x ,y e z com as cores
 * já definidas par a o desenho
 * @param x valor da coordenada x
 * @param y valor da coordenada y
 * @param z valor da coordenada z
 */
void Sculptor::putVoxel(int x, int y, int z) {
  v[x][y][z].isOn = true;
  v[x][y][z].r = r;
  v[x][y][z].g = g;
  v[x][y][z].b = b;
}
/**
 * @brief Sculptor::cutVoxel Apaga um Voxel nas coordenadas x ,y e z
 * @param x valor da coordenada x
 * @param y valor da coordenada y
 * @param z valor da coordenada z
 */
void Sculptor::cutVoxel(int x, int y, int z) { v[x][y][z].isOn = false; }

/**
 * @brief Sculptor::writeOFF Escrever em um arquivo com nome filename as
 * informaçãos para o objeto 3d com formatação OFF
 * @param filename nome do arquivo
 */
void Sculptor::writeOFF(const char* filename)
{
    int nvertices,nfaces,i,j,k;
    std::ofstream fout;
    fout.open(filename);
    if(!fout.is_open()){
        std::cout<<"Falha ao abrir o arquivo!"<<std::endl;
        exit(1);
    }

    fout<<"OFF\n";
    int contVoxel=0;
    for(i=0;i<nx;i++){
           for(j=0;j<ny;j++){
               for(k=0;k<nz;k++){
                if(v[i][j][k].isOn==true){
                contVoxel++;
                                }
            }
        }
    }

    nvertices=contVoxel*8;
    nfaces=contVoxel*6;

    fout<<nvertices<<" "<<nfaces<<" 0\n";

    for(i=0;i<nx;i++){
           for(j=0;j<ny;j++){
               for(k=0;k<nz;k++){
                if(v[i][j][k].isOn==true){
                   fout<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<std::endl;
                   fout<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<std::endl;
                   fout<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<std::endl;
                   fout<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<std::endl;
                   fout<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<std::endl;
                   fout<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<std::endl;
                   fout<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<std::endl;
                   fout<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<std::endl;
                }
            }
        }
    }
    int contVertice=0;
    for(i=0;i<nx;i++){
           for(j=0;j<ny;j++){
               for(k=0;k<nz;k++){
                    if(v[i][j][k].isOn==true){
                        fout<<"4 "<<0+8*contVertice<<" "<<3+8*contVertice<<" "<<2+8*contVertice<<" "<<1+8*contVertice<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl; /*face1*/
                       /* 4 corresponde ao numero de vertices na face, como todas as faces são quadradas esse valor sempre será o mesmo*/
                        fout<<"4 "<<4+8*contVertice<<" "<<5+8*contVertice<<" "<<6+8*contVertice<<" "<<7+8*contVertice<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl; /*face2*/
                        fout<<"4 "<<0+8*contVertice<<" "<<1+8*contVertice<<" "<<5+8*contVertice<<" "<<4+8*contVertice<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;; /*face3*/
                        fout<<"4 "<<0+8*contVertice<<" "<<4+8*contVertice<<" "<<7+8*contVertice<<" "<<3+8*contVertice<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl; /*face4*/
                        fout<<"4 "<<3+8*contVertice<<" "<<7+8*contVertice<<" "<<6+8*contVertice<<" "<<2+8*contVertice<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl; /*face5*/
                        fout<<"4 "<<1+8*contVertice<<" "<<2+8*contVertice<<" "<<6+8*contVertice<<" "<<5+8*contVertice<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl; /*face6*/
                        contVertice++;
                    }
              }
           }
       }
    fout.close();
}