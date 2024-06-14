#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Usuario.h"

#include <string>
using namespace std;

class Administrador : public Usuario {
  
  public:
    Administrador(string, string);
    string getTipoUsuario();
    ~Interesado();
};

#endif
