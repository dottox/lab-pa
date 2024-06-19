#ifndef USUARIO_H
#define USUARIO_H

#include "../ICollection/interfaces/ICollectible.h"

#include <string>
using namespace std;

class ICollectible;

class Usuario : public ICollectible {
  private:
    string email;
    string contrasenia;

  protected:
    Usuario(string, string);

  public:
    // Getters
    virtual string getEmail();
    virtual string getContrasenia();

    // Setters
    virtual void setContrasenia(string);

    // Otros
    virtual string getTipoUsuario() = 0;
    
    // Funciones de los casos de usos
    virtual bool validar(string);

    // Destructor
    virtual ~Usuario();
};

#endif
