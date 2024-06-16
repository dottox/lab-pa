#include "../Clases/Inmobiliaria.h"
#include "../ICollection/collections/List.h"

Inmobiliaria::Inmobiliaria(string email, string contrasenia, DtDireccion direccion) : Usuario::Usuario(email, contrasenia)
{
  this->direccion = direccion;
  this->propiedades = new List();
}

void Inmobiliaria::addPropiedad(Propiedad* propiedad)
{
  this->propiedades->add(propiedad);
}

string Inmobiliaria::getTipoUsuario()
{
  return "Inmobiliaria";
}

ICollection* Inmobiliaria::getPropiedades()
{
  // Debería retornar una lista de DtPropiedades.
  return this->propiedades;
}

DtDireccion* Inmobiliaria::getDireccion()
{
  return new DtDireccion(this->direccion);
}

void Inmobiliaria::setDireccion(DtDireccion direccion)
{
  this->direccion = direccion;
}

Inmobiliaria::~Inmobiliaria()
{
  delete this->propiedades;
}