#include "../Clases/Departamento.h"

#include "../ICollection/collections/List.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/Integer.h"
#include "../ICollection/String.h"

Departamento::Departamento(char codigo, string nombre)
{
  this->codigo = codigo;
  this->nombre = nombre;
  this->zonas = new OrderedDictionary();
}

char Departamento::getCodigo()
{
  return this->codigo;
}

string Departamento::getNombre()
{
  return this->nombre;
}

void Departamento::setCodigo(char codigo)
{
  this->codigo = codigo;
}

void Departamento::setNombre(string nombre)
{
  this->nombre = nombre;
}

void Departamento::addChat(Usuario* interesado)
{
  if (this->zonaActual == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->zonaActual->addChat(interesado);
}

DtDepartamento Departamento::getInfo()
{
  DtDepartamento dtDepartamento = DtDepartamento(this->codigo, this->nombre);
  return dtDepartamento;
}

ICollection* Departamento::getZonas()
{
  ICollection* dtZonas = new List();
  IIterator* it = this->zonas->getIterator();
  while (it->hasCurrent()) {
    IKey* key = dynamic_cast<IKey*>(it->getCurrent());
    Zona* zona = dynamic_cast<Zona*>(this->zonas->find(key));
    DtZona infoZona = zona->getInfo();
    DtZona* ptrInfoZona = new DtZona(infoZona.getCodigo(), infoZona.getNombre());
    dtZonas->add(ptrInfoZona);
    it->next();
  }
  return dtZonas;
}

ICollection* Departamento::getInfoPropiedades(string email) {
  if (this->zonaActual == nullptr) {
    throw "No hay zona seleccionada";
  }
  return this->zonaActual->getInfoPropiedades(email);
}

void Departamento::seleccionarTipoPropiedad(string tipo)
{
  if (this->zonaActual == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->zonaActual->seleccionarTipoPropiedad(tipo);
}

ICollection* Departamento::listarEdificios()
{
  if (this->zonaActual == nullptr) {
    throw "No hay zona seleccionada";
  }
  return this->zonaActual->listarEdificios();
}

void Departamento::seleccionarEdificio(int codigo)
{
  if (this->zonaActual == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->zonaActual->seleccionarEdificio(codigo);
}

void Departamento::agregarDatosApt(DtDatosApartamento datos)
{
  if (this->zonaActual == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->zonaActual->agregarDatosApt(datos);
}

void Departamento::agregarDatosCasa(DtDatosCasa datos)
{
  if (this->zonaActual == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->zonaActual->agregarDatosCasa(datos);
}

void Departamento::seleccionarPago(string tipo, float precio)
{
  if (this->zonaActual == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->zonaActual->seleccionarPago(tipo, precio);
}

void Departamento::darAlta()
{
  if (this->zonaActual == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->zonaActual->darAlta();
}

void Departamento::seleccionarZona(int codigo)
{
  IKey* key = new Integer(codigo);
  Zona* zona = dynamic_cast<Zona*>(this->zonas->find(key));
  delete key;
  if (zona == nullptr) {
    throw "No existe la zona";
  }
  this->zonaActual = zona;
}

void Departamento::seleccionarChat(string email)
{
  if (this->zonaActual == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->zonaActual->seleccionarChat(email);
}

void Departamento::addMensaje(DtMensaje mensaje)
{
  if (this->zonaActual == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->zonaActual->addMensaje(mensaje);
}

Departamento::~Departamento()
{
  if (this->zonaActual != nullptr) {
    delete this->zonaActual;
  }
  delete this->zonas;
}
