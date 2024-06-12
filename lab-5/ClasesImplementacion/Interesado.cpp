#include "../Clases/Interesado.h"

Interesado::Interesado(string email, string contrasenia, string nombre, string apellido, DtFecha fechaNacimiento) : Usuario::Usuario(email, contrasenia)
{
  this->nombre = nombre;
  this->apellido = apellido;
  this->fechaNacimiento = fechaNacimiento;
}

Interesado::~Interesado()
{
}
