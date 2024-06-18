#include "../Clases/Departamento.h"

#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/Integer.h"
#include "../ICollection/String.h"

Departamento::Departamento(char codigo, string nombre)
{
  this->codigo = codigo;
  this->nombre = nombre;
  this->zonas = new OrderedDictionary();
}

void Departamento::getCodigo()
{
  return this->codigo;
}

void Departamento::getNombre()
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

void Departamento::addChat(Interesado* interesado)
{
  if (this->zonaActual == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->zonaActual->addChat(interesado);
}

DtDEpartamento Departamento::getInfo()
{
  DtDepartamento dtDepartamento = DtDepartamento(this->codigo, this->nombre);
  return dtDepartamento;
}

ICollection* Departamento::getZonas()
{
  ICollection* dtZonas = new List();
  IIterator* it = this->zonas->getIterator();
  while (it->hasCurrent()) {
    IKey* key = it->getCurrent();
    Zona* zona = dynamic_cast<Zona*>(this->zonas->find(key));
    DtZona infoZona = zona->getInfo();
    DtZona* ptrInfoZona = new DtZona(infoZona.getCodigo(), infoZona.getNombre());

    dtZonas->add(ptrInfoZona);
    it->next();
  }
  return dtZonas;
}

void Departamento::buscarZona(int codigo)
{
  // ???
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

Departamento::~Departamento()
{
  if (this->zonaActual != nullptr) {
    delete this->zonaActual;
  }
  delete this->zonas;
}