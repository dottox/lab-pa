#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include "../ICollection/interfaces/ICollectible.h"

#include <string>
using namespace std;

class ICollectible;

struct DtDireccion : public ICollectible
{
  private:
    string calle;
    string ciudad;
    int numero;

  public:
    DtDireccion();
    DtDireccion(string, string, int);
    string getCalle();
    string getCiudad();
    int getNumero();

    ~DtDireccion();
};

#endif