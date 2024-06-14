#include "../Clases/Administrador.h"

Administrador::Administrador(string email, string contrasenia) : Usuario::Usuario(email, contrasenia)
{
}

string Administrador::getTipoUsuario()
{
  return "Administrador";
}

Administrador::~Administrador()
{
}