#include "../Clases/Edificio.h"
#include "../Clases/Inmobiliaria.h"
#include "../Clases/Apartamento.h"

#include "../ICollection/collections/List.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/String.h"
#include "../ICollection/Integer.h"


Edificio::Edificio(string nombre, int cantPisos, float gastosComunes, Inmobiliaria* inmo)
{
  this->nombre = nombre;
  this->cantPisos = cantPisos;
  this->gastosComunes = gastosComunes;
  this->inmobiliaria = inmo;
  this->apartamentos = new OrderedDictionary();
}



DtDatos Edificio::getDatosApartamento(){
  if (this->getPropiedadActual() != nullptr) {
    return this->getPropiedadActual()->getDatos();
  } else {
    throw "No existe apartamento seleccionado";
  }
}

DtDatos Edificio::getDatosApartamentoNoSeleccionado(int codigo) {
  IKey* key = new Integer(codigo);
  Propiedad* apt = dynamic_cast<Propiedad*>(this->apartamentos->find(key));
  delete key;
  if (apt != nullptr) {
    return apt->getDatos();
  } else {
    throw "No existe apartamento";
  }

}

DtInfo Edificio::propiedad__getInfoPropiedad(int codigo, string email)
{
  IKey* key = new Integer(codigo);
  Propiedad* apt = dynamic_cast<Propiedad*>(this->apartamentos->find(key));
  delete key;
  if (apt == nullptr) {
    throw "No existe apartamento";
  }
  return apt->getInfoPropiedad(email);
}

string Edificio::getNombre()
{
  return this->nombre;
}

int Edificio::getCantPisos()
{
  return this->cantPisos;
}

float Edificio::getGastosComunes()
{
  return this->gastosComunes;
}

void Edificio::setNombre(string nombre)
{
  this->nombre = nombre;
}

void Edificio::setCantPisos(int cantPisos)
{
  this->cantPisos = cantPisos;
}

void Edificio::setGastosComunes(float gastosComunes)
{
  this->gastosComunes = gastosComunes;
}

void Edificio::seleccionarPropiedad(int codigo)
{
  IKey* key = new Integer(codigo);
  this->apartamentoActual = dynamic_cast<Apartamento*>(this->apartamentos->find(key));
  delete key;
}

void Edificio::deseleccionarPropiedad()
{
  this->apartamentoActual = nullptr;
}

DtEdificio Edificio::getInfo()
{
  return DtEdificio(this->nombre, this->cantPisos, this->gastosComunes);
}

ICollection* Edificio::getInfoPropiedades(string email, bool necesitaTipo = false)
{
  ICollection* ret = new List();
  IIterator* it = this->apartamentos->getIterator();
  DtInfo* info;
  while (it->hasCurrent())
  {
    Apartamento* apt = dynamic_cast<Apartamento*>(it->getCurrent());
    if (necesitaTipo) {
      info = new DtInfo(apt->getCodigo(), apt->getTipo(), apt->getDireccion());
    }
    else {
      DtInfo datos = apt->getInfoPropiedad(email); 
      info = new DtInfo(datos.getCodigo(), datos.getCantMensajes(), datos.getDireccion());
    }
    ret->add(info);
    it->next();
  }
  delete it;
  return ret;
}

void Edificio::agregarDatosApt(DtDatosApartamento datos, Usuario* inmobiliaria, int codigoZona, char codigoDep)
{
  Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(inmobiliaria);
  Propiedad* apt = new Apartamento(datos, inmo, codigoZona, codigoDep);
  this->apartamentoActual = apt;
}

Propiedad* Edificio::zona__edificio__darAlta()
{
  if (this->getPropiedadActual() != nullptr) {
    IKey* key = new Integer(getPropiedadActual()->getCodigo());
    this->apartamentos->add(key, this->getPropiedadActual());
    return this->getPropiedadActual();
  } else {
    throw "No existe apartamento seleccionado";
  }
}

Propiedad* Edificio::getPropiedadActual() {
  return this->apartamentoActual;
}


void Edificio::aux__deseleccionarTodo(bool borrarCasa = false) {
  if (this->getPropiedadActual() != nullptr) {
    if (borrarCasa) {
      delete this->getPropiedadActual();
    } else {
      this->getPropiedadActual()->aux__deseleccionarTodo();
    }
  }
  this->deseleccionarPropiedad();
}

#include <iostream>

void Edificio::modificarDatosApartamento(DtDatosApartamento datos, int codigo) {
  cout << "llego edificio";
  IKey* key = new Integer(codigo);
  Apartamento* apt = dynamic_cast<Apartamento*>(this->apartamentos->find(key));
  delete key;
  if (apt == nullptr) {
    throw "No existe apartamento";
  }
  apt->setDatos(datos); 
}

bool Edificio::eliminarPropiedad(int codigo){
  IKey* key = new Integer(codigo);
  Propiedad* apt = dynamic_cast<Propiedad*>(this->apartamentos->find(key));
  if(apt == nullptr){
    delete key;
    return false;
  }
  this->apartamentos->remove(key);
  delete apt;
  delete key;
  return true;
}

Edificio::~Edificio()
{
  if (this->apartamentoActual != nullptr) {
    delete this->apartamentoActual;
  }

  delete this->apartamentos;
}