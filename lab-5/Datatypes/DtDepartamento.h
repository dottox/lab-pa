#ifndef DTDEPARTAMENTO_H
#define DTDEPARTAMENTO_H

#include <string>
using namespace std;

struct DtDepartamento 
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