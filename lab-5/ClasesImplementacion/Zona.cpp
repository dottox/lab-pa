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

void Zona::addChat(Usuario* interesado)
{
  if (this->propiedadActual == nullptr)
  {
    throw "No hay propiedad seleccionada";
  }
  this->propiedadActual->addChat((Interesado*)interesado);
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
  
  if (this->propiedadActual == nullptr)
  {
    throw "La propiedad no existe";
  }
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
  ICollection* ret = new List();
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

void Zona::seleccionarTipoPropiedad(string tipo)
{
  this->tipoPropiedadActual = tipo;
}

void Zona::darAlta()
{
  IKey* key = new Integer(this->propiedadActual->getCodigo());
  this->propiedades->add(key, this->propiedadActual);
}

void Zona::addMensaje(DtMensaje mensaje)
{
  if (this->propiedadActual == nullptr)
  {
    throw "No hay propiedad seleccionada";
  }
  this->propiedadActual->addMensaje(mensaje);
}

void Zona::seleccionarChat(string email)
{
  if (this->propiedadActual == nullptr)
  {
    throw "No hay propiedad seleccionada";
  }
  this->propiedadActual->seleccionarChat(email);
}

Propiedad* Zona::getPropiedadActual() {
  return this->propiedadActual;
}

Edificio* Zona::getEdificioActual() {
  return this->edificioActual;
}

void Zona::deseleccionarTodo() {
  if (this->getPropiedadActual() != nullptr) {
    this->getPropiedadActual()->deseleccionarTodo();
  } 
  else if (this->getEdificioActual() != nullptr) {
    this->getEdificioActual()->deseleccionarTodo();
  }
  this->deseleccionarEdificio();
  this->deseleccionarPropiedad();
}

DtDatos Zona::detallesPropiedad(int codigo){
  if(propiedadActual != nullptr){
    return this->getPropiedadActual()->getInfo();
  }else if(edificioActual != nullptr){
    return this->getEdificioActual()->getInfo(codigo);
  }
    throw "No hay propiedad seleccionada";
}


Zona::~Zona()
{
  delete this->propiedades;
  delete this->edificios;
}