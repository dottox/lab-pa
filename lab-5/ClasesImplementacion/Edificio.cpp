#include "../Clases/Edificio.h"
#include "../Clases/Inmobiliaria.h"

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

DtInfo Edificio::getInfoPropiedad(int codigo, string email)
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

ICollection* Edificio::getInfoPropiedades(string email)
{
  ICollection* ret = new List();
  IIterator* it = this->apartamentos->getIterator();
  while (it->hasCurrent())
  {
    Apartamento* apt = dynamic_cast<Apartamento*>(it->getCurrent());
    DtInfo data = apt->getInfoPropiedad(email);
    DtInfo* info = new DtInfo(data.getCodigo(), data.getCantMensajes(), data.getDireccion());
    ret->add(info);
    it->next();
  }
  delete it;
  return ret;
}

void Edificio::agregarDatosApt(DtDatosApartamento datos, Usuario* inmobiliaria)
{
  if (this->getPropiedadActual() != nullptr) {
    Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(inmobiliaria);
    Propiedad* apt = new Apartamento(datos, inmo);
    this->apartamentoActual = apt;
  } else {
    throw "No existe apartamento seleccionado";
  }
}

void Edificio::darAlta()
{
  if (this->getPropiedadActual() != nullptr) {
    IKey* key = new Integer(getPropiedadActual()->getCodigo());
    this->apartamentos->add(key, this->getPropiedadActual());
  } else {
    throw "No existe apartamento seleccionado";
  }
}

Propiedad* Edificio::getPropiedadActual() {
  return this->apartamentoActual;
}

int Edificio::generarCodigoPropiedad() {
  return this->apartamentos->getSize() + 1;
}

void Edificio::deseleccionarTodo(bool borrarCasa = false) {
  if (this->getPropiedadActual() != nullptr) {
    if (borrarCasa) {
      delete this->getPropiedadActual();
    } else {
      this->getPropiedadActual()->deseleccionarTodo();
    }
  }
  this->deseleccionarPropiedad();
}

Edificio::~Edificio()
{
  if (this->apartamentoActual != nullptr) {
    delete this->apartamentoActual;
  }

  delete this->apartamentos;
}