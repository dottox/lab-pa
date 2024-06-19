#ifndef DTZONA_H
#define DTZONA_H

#include <string>
using namespace std;

#include "../ICollection/interfaces/ICollectible.h"

class ICollectible;

struct DtZona : public ICollectible{
  private:
    int codigo;
    string nombre;

  public:
    DtZona(int, string);
    int getCodigo();
    string getNombre();

    ~DtZona();
};

#endif