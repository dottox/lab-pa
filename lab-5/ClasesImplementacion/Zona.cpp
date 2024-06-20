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

DtDatos Zona::getDatosPropiedad()
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

ICollection* Zona::getUltimosMensajes(string email) {
  if (this->propiedadActual == nullptr)
  {
    throw "No hay propiedad seleccionada";
  }
  try {
    return this->propiedadActual->getUltimosMensajes(email);
  } catch (const char* e) {
    throw e;
  }
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

void Zona::agregarDatosApt(DtDatosApartamento datos, Usuario* inmobiliaria)
{
  this->edificioActual->agregarDatosApt(datos, inmobiliaria);
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
  Casa* casa = new Casa(datos, inmo);
  Propiedad* propiedad = dynamic_cast<Propiedad*>(casa);
  this->propiedadActual = propiedad;
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
  try {
    if (this->propiedadActual == nullptr) {
      if (this->edificioActual != nullptr){
        this->edificioActual->darAlta();
        return;
      }
      else {
        throw "No hay propiedad seleccionada";
      }
    }
    IKey* key = new Integer(this->propiedadActual->getCodigo());
    this->propiedades->add(key, this->propiedadActual);
  } catch (const char* e) {
    throw e;
  }
}

int Zona::generarCodigoPropiedad()
{
  try {
    if (this->edificioActual != nullptr) {
      return this->edificioActual->generarCodigoPropiedad();
    } else {
      return this->propiedades->getSize() + 1;
    }
  } catch (const char* e) {
    throw e;
  }
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

void Zona::deseleccionarTodo(bool borrarCasa = false) {

  if (this->getPropiedadActual() != nullptr) {
    if (borrarCasa) {
      delete this->getPropiedadActual();
    } else {
      this->getPropiedadActual()->deseleccionarTodo();
    }
  } 
  else if (this->getEdificioActual() != nullptr) {
    this->getEdificioActual()->deseleccionarTodo(borrarCasa);
  }
  this->deseleccionarEdificio();
  this->deseleccionarPropiedad();
}

DtInfo* Zona::detallesPropiedad(int codigo, string email){
  try {
    IKey* key = new Integer(codigo);
    Propiedad* propiedad = dynamic_cast<Propiedad*>(this->propiedades->find(key));
    delete key;
    if (propiedad != nullptr) {
      DtInfo info = propiedad->getInfoPropiedad(email);
      return new DtInfo(info.getCodigo(), info.getCantMensajes(), info.getDireccion());
    }
    else if (this->getEdificioActual() != nullptr) {
      DtInfo info = this->getEdificioActual()->getInfoPropiedad(codigo, email);
      return new DtInfo(info.getCodigo(), info.getCantMensajes(), info.getDireccion());
    } else {
      throw "No hay propiedad ni edificio seleccionado";
    }
  } catch (const char* e) {
    throw e;
}
}

bool Zona::isChatSeleccionado(){
  if(this->propiedadActual != nullptr){
    return this->propiedadActual->isChatSeleccionado();
  }
  throw "No hay propiedad seleccionada";
}

ICollection* Zona::getMensajes(){
  if(this->propiedadActual == nullptr){
      throw "No hay propiedad seleccionada";
  }
  return this->propiedadActual->getMensajes();
}

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
}


Zona::~Zona()
{
  delete this->propiedades;
  delete this->edificios;
}