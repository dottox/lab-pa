#ifndef USUARIO_H
#define USUARIO_H

#include "../ICollection/interfaces/ICollectible.h"

#include <string>
using namespace std;

class Usuario : public ICollectible {
  private:
    string email;
    string contrasenia;
  
  public:
    Usuario(string, string);
    bool validar(string);
    string getEmail(string);
    ~Usuario();
};

#endif
