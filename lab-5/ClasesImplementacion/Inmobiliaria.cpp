#include "../Clases/Inmobiliaria.h"
#include "../ICollection/collections/List.h"

Inmobiliaria::Inmobiliaria(string email, string contrasenia, DtFecha fecha, DtDireccion direccion) : Usuario::Usuario(email, contrasenia, fecha)
{
  this->direccion = direccion;
  this->propiedades = new List();
}

void Inmobiliaria::addPropiedad(Propiedad* propiedad)
{
  this->propiedades->add(propiedad);
}

ICollection* Inmobiliaria::getPropiedades()
{
  // Debería retornar una lista de DtPropiedades.
}

DtDireccion Inmobiliaria::getDireccion()
{
  return this->direccion;
}

void Inmobiliaria::setDireccion(DtDireccion direccion)
{
  this->direccion = direccion;
}

Inmobiliaria::~Inmobiliaria()
{
  delete this->propiedades;
}