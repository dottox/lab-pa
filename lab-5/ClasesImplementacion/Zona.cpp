#include "../Clases/Zona.h"

#include "../ICollection/collections/List.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/Integer.h"
#include "../ICollection/String.h"


Zona::Zona(int codigo, string nombre, char departamento)
{
  this->codigo = codigo;
  this->nombre = nombre;
  this->miDepartamento = departamento;
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

DtDatos Zona::zona__edificio__getDatosPropiedad()
{
  if (this->propiedadActual != nullptr)
  {
    DtDatos datos = this->propiedadActual->getDatos();
    return datos;
  } else if (this->edificioActual != nullptr) {
    DtDatos datos = this->getEdificioActual()->getDatosApartamento();
    return datos;
  } else {
    throw "No hay propiedad ni edificio seleccionado";
  }
}

DtDatos Zona::zona__edificio__getDatosPropiedadNoSeleccionada(int codigo)
{
  IKey *key = new Integer(codigo);
  Propiedad *prop = dynamic_cast<Propiedad*>(this->propiedades->find(key));
  delete key;
  if (prop != nullptr)
  {
    return prop->getDatos();
  }
  else
  {
    IIterator *it = this->edificios->getIterator();
    while (it->hasCurrent())
    {
      Edificio *edif = dynamic_cast<Edificio*>(it->getCurrent());
      try {
        DtDatos datos = edif->getDatosApartamentoNoSeleccionado(codigo);
        return datos;
      } catch (const char *e) {
        it->next();
        continue;
      }
    }
    delete it;
    throw "No existe la propiedad";
  }
}

ICollection* Zona::chat__getUltimosMensajes(string email) {
  if (this->getPropiedadActual() == nullptr)
  {
    throw "No hay propiedad seleccionada";
  }
  try {
    return this->getPropiedadActual()->chat__getUltimosMensajes(email);
  } catch (const char* e) {
    throw e;
  }
}

void Zona::propiedad__addChat(Usuario* interesado)
{
  if (this->propiedadActual == nullptr)
  {
    throw "No hay propiedad seleccionada";
  }
  this->getPropiedadActual()->addChat((Interesado*)interesado);
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
    DtInfo* info = new DtInfo(prop->getCodigo(), prop->getTipo(), prop->getDireccion());
    ret->add(info);
    it->next();
  }
  delete it;
  return ret;
}

ICollection* Zona::edificio__getInfoPropiedades(string email) {
  ICollection* ret = new List();
  IIterator* it2 = this->edificios->getIterator();
  while (it2->hasCurrent())
  {
    Edificio* edif = dynamic_cast<Edificio*>(it2->getCurrent());
    ICollection* props = edif->getInfoPropiedades(email, true);
    IIterator* it3 = props->getIterator();
    while (it3->hasCurrent())
    {
      DtInfo* info = dynamic_cast<DtInfo*>(it3->getCurrent());
      ret->add(info);
      it3->next();
    }
    delete it3;
    it2->next();
  }

  delete it2;
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

string Zona::propiedad__getNombreInmobiliaria()
{
  if (this->getPropiedadActual() == nullptr)
  {
    throw "No hay propiedad seleccionada";
  }
  try {
    return this->getPropiedadActual()->getNombreInmobiliaria();
  } catch (const char* e) {
    throw e;
  }
}

char Zona::getDepartamento()
{
  return this->miDepartamento;
}

void Zona::edificio__agregarDatosApt(DtDatosApartamento datos, Usuario* inmobiliaria)
{
  this->getEdificioActual()->agregarDatosApt(datos, inmobiliaria, this->getCodigo(), this->getDepartamento());
}

void Zona::agregarDatosCasa(DtDatosCasa datos, Usuario* inmobiliaria)
{ 
  IKey* key = new Integer(datos.getCodigo());
  if(this->propiedades->find(key) != nullptr){
    delete key;
    throw "Ya existe una propiedad con ese codigo";
  }
  delete key;
  Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(inmobiliaria);
  Propiedad* casa = new Casa(datos, inmo, this->getCodigo(), this->getDepartamento());
  this->propiedadActual = casa;
}

void Zona::propiedad__seleccionarPago(string tipo, float precio) {
  this->getPropiedadActual()->setTipo(tipo);
  this->getPropiedadActual()->setPrecio(precio);
}

Propiedad* Zona::zona__edificio__darAlta()
{
  try {
    if (this->getPropiedadActual() == nullptr) {
      if (this->getEdificioActual() != nullptr) {
        return this->getEdificioActual()->zona__edificio__darAlta();
        
      }
      else {
        throw "No hay propiedad seleccionada";
      }
    }
    IKey* key = new Integer(this->getPropiedadActual()->getCodigo());
    this->propiedades->add(key, this->getPropiedadActual());
    return this->getPropiedadActual();
  } catch (const char* e) {
    throw e;
  }
}

void Zona::chat__addMensaje(DtMensaje mensaje)
{
  if (this->getPropiedadActual() == nullptr)
  {
    throw "No hay propiedad seleccionada";
  }
  this->getPropiedadActual()->chat__addMensaje(mensaje);
}

void Zona::propiedad__seleccionarChat(string email)
{
  if (this->getPropiedadActual() == nullptr)
  {
    throw "No hay propiedad seleccionada";
  }
  this->getPropiedadActual()->seleccionarChat(email);
}

Propiedad* Zona::getPropiedadActual() {
  return this->propiedadActual;
}

Edificio* Zona::getEdificioActual() {
  return this->edificioActual;
}

void Zona::aux__deseleccionarTodo(bool borrarCasa = false) {

  if (this->getPropiedadActual() != nullptr) {
    if (borrarCasa) {
      delete this->getPropiedadActual();
    } else {
      this->getPropiedadActual()->aux__deseleccionarTodo();
    }
  } 
  else if (this->getEdificioActual() != nullptr) {
    this->getEdificioActual()->aux__deseleccionarTodo(borrarCasa);
  }
  this->deseleccionarEdificio();
  this->deseleccionarPropiedad();
}

DtInfo* Zona::propiedad__detallesPropiedad(int codigo, string email){
  try {
    IKey* key = new Integer(codigo);
    Propiedad* propiedad = dynamic_cast<Propiedad*>(this->propiedades->find(key));
    delete key;
    if (propiedad != nullptr) {
      DtInfo info = propiedad->getInfoPropiedad(email);
      return new DtInfo(info.getCodigo(), info.getCantMensajes(), info.getDireccion());
    }
    else if (this->getEdificioActual() != nullptr) {
      DtInfo info = this->getEdificioActual()->propiedad__getInfoPropiedad(codigo, email);
      return new DtInfo(info.getCodigo(), info.getCantMensajes(), info.getDireccion());
    } else {
      throw "No hay propiedad ni edificio seleccionado";
    }
  } catch (const char* e) {
    throw e;
}
}

bool Zona::propiedad__isChatSeleccionado(){
  if(this->getPropiedadActual() != nullptr){
    return this->getPropiedadActual()->isChatSeleccionado();
  }
  throw "No hay propiedad seleccionada";
}

ICollection* Zona::chat__getMensajes(){
  if(this->getPropiedadActual() == nullptr){
      throw "No hay propiedad seleccionada";
  }
  return this->getPropiedadActual()->chat__getMensajes();
}

#include <iostream>

void Zona::darDeAltaEdificio(DtEdificio edificio, Usuario* usuario){
  IKey* key = new String((char*)edificio.getNombre().c_str());
  Edificio* e = dynamic_cast<Edificio*>(this->edificios->find(key));
  if(e != nullptr){
    delete key;
    throw "Ya existe un edificio con ese nombre";
  }
  Inmobiliaria* inmobiliaria = dynamic_cast<Inmobiliaria*>(usuario);
  Edificio* edi = new Edificio(edificio.getNombre(), edificio.getCantPisos(), edificio.getGastosComunes(), inmobiliaria);
  this->edificios->add(key, edi);
  inmobiliaria->addEdificio(edi);
  this->edificioActual = edi;
}

#include <iostream>

bool Zona::eliminarPropiedad(int codigo) {
  IKey* key = new Integer(codigo);
  Propiedad* prop = dynamic_cast<Propiedad*>(this->propiedades->find(key));

  if (prop != nullptr) {
    this->propiedades->remove(key);
    delete key;
    return true;
  } else {
    IIterator* it = this->edificios->getIterator();
    while (it->hasCurrent()) {
      Edificio* edificio = dynamic_cast<Edificio*>(it->getCurrent());
      if (edificio->eliminarPropiedad(codigo)) {
        delete it;
        return true;
      }
      it->next();
    }
    delete it;
    return false;
  }
}


Zona::~Zona()
{
  delete this->propiedades;
  delete this->edificios;
}