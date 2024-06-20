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

void Departamento::darAltaZona(int codigo, string nombre)
{
  IKey* key = new Integer(codigo);
  Zona* zona = new Zona(codigo, nombre);
  this->zonas->add(key, zona);
}

Zona* Departamento::getZonaActual()
{
  return this->zonaActual;
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
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->getZonaActual()->addChat(interesado);
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
    Zona* zona = dynamic_cast<Zona*>(it->getCurrent());
    DtZona infoZona = zona->getInfo();
    DtZona* ptrInfoZona = new DtZona(infoZona.getCodigo(), infoZona.getNombre());
    dtZonas->add(ptrInfoZona);
    it->next();
  }
  delete it;
  return dtZonas;
}

ICollection* Departamento::getInfoPropiedades(string email) {
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  return this->getZonaActual()->getInfoPropiedades(email);
}

void Departamento::seleccionarTipoPropiedad(string tipo)
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->getZonaActual()->seleccionarTipoPropiedad(tipo);
}

ICollection* Departamento::listarEdificios()
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  return this->getZonaActual()->listarEdificios();
}

void Departamento::deseleccionarZonaActual() {
  this->zonaActual = nullptr;
}

void Departamento::deseleccionarTodo(bool borrarCasa = false)
{
  if (this->getZonaActual() != nullptr) {
    this->getZonaActual()->deseleccionarTodo(borrarCasa);
  }
  this->deseleccionarZonaActual();
}


void Departamento::seleccionarEdificio(string nombre)
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->getZonaActual()->seleccionarEdificio(nombre);
}

void Departamento::agregarDatosApt(DtDatosApartamento datos, Usuario* inmobiliaria)
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->getZonaActual()->agregarDatosApt(datos, inmobiliaria);
}

DtDatos Departamento::getDatosPropiedad()
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  try {
    return this->getZonaActual()->getDatosPropiedad();
  } catch (const char* e) {
    throw e;
  }
}

ICollection* Departamento::getUltimosMensajes(string email) {
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  try {
    return this->getZonaActual()->getUltimosMensajes(email);
  } catch (const char* e) {
    throw e;
  }
}

int Departamento::zona__generarCodigoPropiedad() {
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }

  try {
    return this->getZonaActual()->generarCodigoPropiedad();
  } catch (const char* e) {
    throw e;
  }
}

void Departamento::agregarDatosCasa(DtDatosCasa datos, Usuario* inmobiliaria)
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->getZonaActual()->agregarDatosCasa(datos, inmobiliaria);
}

void Departamento::seleccionarPago(string tipo, float precio)
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->getZonaActual()->seleccionarPago(tipo, precio);
}

void Departamento::darAlta()
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->getZonaActual()->darAlta();
}

void Departamento::seleccionarPropiedad(int codigo)
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->getZonaActual()->seleccionarPropiedad(codigo);
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

bool Departamento::isChatSeleccionado()
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  return this->getZonaActual()->isChatSeleccionado();
}

void Departamento::seleccionarChat(string email)
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->zonaActual->seleccionarChat(email);
}

void Departamento::addMensaje(DtMensaje mensaje)
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->zonaActual->addMensaje(mensaje);
}

DtInfo* Departamento::detallesPropiedad(int codigo, string email){
  if(zonaActual == nullptr){
    throw "No hay zona seleccionada";
  }
  try {
    return this->getZonaActual()->detallesPropiedad(codigo, email);
  } catch (const char* e) {
    throw e;
  }
}

ICollection* Departamento::getMensajes()
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  return this->getZonaActual()->getMensajes();
}

void Departamento::darDeAltaEdificio(DtEdificio edificio, Usuario* inmobiliaria){
  if (this->zonaActual == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->getZonaActual()->darDeAltaEdificio(edificio, inmobiliaria);
}

void Departamento::modificarDatosCasa(DtDatosCasa datos,Usuario inmobiliaria);{
  if (this->zonaActual == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->getZonaActual()->modificarDatosCasa(datos, inmobiliaria);
}


Departamento::~Departamento()
{
  delete this->zonas;
}
