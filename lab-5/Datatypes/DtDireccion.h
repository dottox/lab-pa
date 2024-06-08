#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <string>
using namespace std;

struct DtDireccion 
{
  private:
    string calle;
    string ciudad;
    int nro;

  public:
    DtDireccion();
    DtDireccion(string, string, int);
    string getCalle();
    string getCiudad();
    int getNro();
};

#endif