#ifndef DTDEPARTAMENTO_H
#define DTDEPARTAMENTO_H

#include "../ICollection/interfaces/ICollectible.h"

#include <string>
using namespace std;

class ICollectible;

struct DtDepartamento : public ICollectible
{
  private:
    char codigo;
    string nombre;

  public:
    DtDepartamento(char, string);
    int getCodigo();
    string getNombre();

    ~DtDepartamento();
};

#endif