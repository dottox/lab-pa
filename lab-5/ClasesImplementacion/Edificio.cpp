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

DtDatos getInfo(){
  if(apartamentoActual == nullptr){
    throw "No hay apartamento seleccionado";
  }
  return this->getPropiedadActual()->getInfo();
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

void Edificio::agregarDatosApt(DtDatosApartamento datos)
{
  if (this->getPropiedadActual() != nullptr) {
    this->getPropiedadActual()->setDatos(datos);
  } else {
    throw "No existe apartamento seleccionado";
  }
}

void Edificio::seleccionarPago(string tipo, float monto)
{
  if (this->getPropiedadActual() != nullptr) {
    this->getPropiedadActual()->setPrecio(monto);
    this->getPropiedadActual()->setTipo(tipo);
  } else {
    throw "No existe apartamento seleccionado";
  }
}

void Edificio::darAlta(int codigo)
{
  IKey* key = new Integer(codigo);
  if (this->getPropiedadActual() != nullptr) {
    this->apartamentos->add(key, this->getPropiedadActual());
  } else {
    delete key;
    throw "No existe apartamento seleccionado";
  }
}

Apartamento* Edificio::getPropiedadActual() {
  return this->apartamentoActual;
}

void Edificio::deseleccionarTodo() {
  if (this->getPropiedadActual() != nullptr) {
    this->getPropiedadActual()->deseleccionarTodo();
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