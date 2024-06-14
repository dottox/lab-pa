#ifndef INTERESADO_H
#define INTERESADO_H

#include "Usuario.h"

#include "../Datatypes/DtFecha.h"

#include <string>
using namespace std;

class Interesado : public Usuario {
  private:
    string nombre;
    string apellido;
    DtFecha fechaNacimiento;
  
  public:
    string getTipoUsuario();
    Interesado(string, string, string, string, DtFecha);
    ~Interesado();
};

#endif
