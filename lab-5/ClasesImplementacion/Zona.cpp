#include "../Clases/Zona.h"

#include "../ICollection/collections/List.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/Integer.h"
#include "../ICollection/String.h"

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

void Zona::seleccionarEdificio(string nombre)
{
  IKey* key = new String((char*)nombre.c_str());
  this->edificioActual = dynamic_cast<Edificio*>(this->edificios->find(key));
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

ICollection* Zona::listarEdificios()
{
  ICollection* ret = new List();
  IIterator* it = this->edificios->getIterator();
  while (it->hasCurrent())
  {
    Edificio* edif = dynamic_cast<Edificio*>(it->getCurrent());
    DtEdificio data = edif->getInfo();
    DtEdificio* info = new DtEdificio(data.getNombre(), data.getCantPisos(), data.getGastosComunes());
    ret->add(info);
    it->next();
  }
  delete it;
  return ret;
}

void Zona::agregarDatosApt(DtDatosApartamento datos)
{
  this->edificioActual->agregarDatosApt(datos);
}

void Zona::agregarDatosCasa(DtDatosCasa datos)
{
  this->propiedadActual->setDatos(datos);
}

void Zona::seleccionarPago(string tipo, float precio) {
  this->propiedadActual->setTipo(tipo);
  this->propiedadActual->setPrecio(precio);
}

void Zona::darAlta(int codigo)
{
  IKey* key = new Integer(codigo);
  this->propiedadActual->setCodigo(codigo);
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