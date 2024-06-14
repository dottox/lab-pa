#ifndef DTZONA_H
#define DTZONA_H

#include <string>
using namespace std;

struct DtZona {
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