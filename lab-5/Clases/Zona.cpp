#include "../Clases/Zona.h"

#include "../ICollection/collections/List.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/Integer.h"

Zona::Zona(int codigo, string nombre)
{
  this->codigo = codigo;
  this->nombre = nombre;
  this->propiedades = new OrderedDictionary();
  this->edificios = new OrderedDictionary();
}

int Zona::getCodigo()
{
  return this->codigo;
}

string Zona::getNombre()
{
  return this->nombre;
}

void Zona::setCodigo(int codigo)
{
  this->codigo = codigo;
}

void Zona::setNombre(string nombre)
{
  this->nombre = nombre;
}

void Zona::seleccionarEdificio(int codigo)
{
  IKey* key = new Integer(codigo);
  this->edificioActual = dynamic_cast<Edificio*>(this->edificios->find(codigo));
  delete key;
}

void Zona::seleccionarPropiedad(int codigo)
{
  IKey* key = new Integer(codigo);
  this->propiedadActual = dynamic_cast<Propiedad*>(this->propiedades->find(key));
  delete key;
}

void Zona::deseleccionarEdificio()
{
  this->edificioActual = nullptr;
}

void Zona::deseleccionarPropiedad()
{
  this->propiedadActual = nullptr;
}

DtZona Zona::getInfo()
{
  return DtZona(this->codigo, this->nombre);
}


ICollection* Zona::getInfoPropiedades(string email)
{
  IDictionary* ret = new List();
  IIterator* it = this->propiedades->getIterator();
  while (it->hasCurrent())
  {
    Propiedad* prop = dynamic_cast<Propiedad*>(it->getCurrent());
    DtInfo data = prop->getInfoPropiedad(email);
    DtInfo* info = new DtInfo(data.getCodigo(), data.getCantMensajes(), data.getDireccion());
    ret->add(info);
    it->next();
  }
  delete it;
  return ret;
}

ICollection* Zona::listarEdificios()
{
  IDictionary* ret = new List();
  IIterator* it = this->edificios->getIterator();
  while (it->hasCurrent())
  {
    Edificio* edif = dynamic_cast<Edificio*>(it->getCurrent());
    DtEdificio data = edif->getInfo();
    DtEdificio* info = new DtEdificio(data.getCodigo(), data.getNombre());
    ret->add(info);
    it->next();
  }
  delete it;
  return ret;
}

void agregarDatosApt(DtDatosApartamento datos)
{
  // Por implementar, usando edificio actual, delegar en edificio
}

void agregarDatosCasa(DtDatosCasa datos)
{
  this->propiedadActual->setDatos(datos);
}

void seleccionarPago(string tipo, float precio) {
  this->propiedadActual->setTipo(tipo);
  this->propiedadActual->setPrecio(precio);
}

void Zona::darAlta()
{
  IKey* key = new Integer(codigo);
  this->propiedades->add(key, this->propiedadActual);
  delete key;
}

Zona::~Zona()
{
  if (this->edificioActual != nullptr)
  {
    delete this->edificioActual;
  }
  if (this->propiedadActual != nullptr)
  {
    delete this->propiedadActual;
  }
  delete this->propiedades;
  delete this->edificios;
}