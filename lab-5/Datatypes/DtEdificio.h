#ifndef DTEDIFICIO_H
#define DTEDIFICIO_H

#include <string>
using namespace std;

struct DtEdificio 
{
  private:
    string nombre;
    int cantPisos;
    float gastosComunes;

  public:
    DtEdificio(string, int, float);
    string getNombre();
    int getCantPisos();
    float getGastosComunes();
};

#endif