#include "../Clases/Usuario.h"

Usuario::Usuario(string email, string contrasenia)
{
  this->email = email;
  this->contrasenia = contrasenia;
}

bool Usuario::validar(string contrasenia)
{
  return this->contrasenia == contrasenia;
}

string Usuario::getEmail()
{
  return this->email;
}

void Usuario::setContrasenia(string contrasenia)
{
  this->contrasenia = contrasenia;
}

Usuario::~Usuario()
{
}
