#ifndef DTEDIFICIO_H
#define DTEDIFICIO_H

#include <string>
using namespace std;

struct DtEdificio : public ICollectible
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

    ~DtEdificio();
};

#endif