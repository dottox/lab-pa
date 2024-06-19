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

Propiedad* Inmobiliaria::buscarPropiedad(int codigo)
{
  IIterator* it = this->propiedades->getIterator();
  while (it->hasCurrent())
  {
    Propiedad* propiedad = dynamic_cast<Propiedad*>(it->getCurrent());
    if (propiedad->getCodigo() == codigo)
    {
      return propiedad;
    }
    it->next();
  }
  delete it;
  return nullptr;
}

void Inmobiliaria::removePropiedad(int codigo)
{ // Aquí borro a la propiedad de la lista, luego de esto el objeto de la propiedad debe ser eliminado.
  Propiedad* propiedad = this->buscarPropiedad(codigo);
  if(propiedad == nullptr){
    throw "La propiedad no existe";
  }
  this->propiedades->remove(propiedad);
};


string Inmobiliaria::getTipoUsuario()
{
  return "Inmobiliaria";
}

ICollection* Inmobiliaria::getPropiedades()
{
  // Debería retornar una lista de DtPropiedades.
  return this->propiedades;
}

DtDireccion Inmobiliaria::getDireccion()
{
  return DtDireccion(this->direccion);
}

void Inmobiliaria::setDireccion(DtDireccion direccion)
{
  this->direccion = direccion;
}

Inmobiliaria::~Inmobiliaria()
{
  delete this->propiedades;
}