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

Zona* Departamento::getZonaActual()
{
  return this->zonaActual;
}

void Departamento::comprobarZonaActual()
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
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
  this->comprobarZonaActual();
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
  this->comprobarZonaActual();
  return this->getZonaActual()->getInfoPropiedades(email);
}

void Departamento::seleccionarTipoPropiedad(string tipo)
{
  this->comprobarZonaActual();
  this->getZonaActual()->seleccionarTipoPropiedad(tipo);
}

ICollection* Departamento::listarEdificios()
{
  this->comprobarZonaActual();
  return this->getZonaActual()->listarEdificios();
}


void Departamento::seleccionarEdificio(string nombre)
{
  this->comprobarZonaActual();
  this->getZonaActual()->seleccionarEdificio(nombre);
}

void Departamento::agregarDatosApt(DtDatosApartamento datos)
{
  this->comprobarZonaActual();
  this->getZonaActual()->agregarDatosApt(datos);
}

void Departamento::agregarDatosCasa(DtDatosCasa datos)
{
  this->comprobarZonaActual();
  this->getZonaActual()->agregarDatosCasa(datos);
}

void Departamento::seleccionarPago(string tipo, float precio)
{
  this->comprobarZonaActual();
  this->getZonaActual()->seleccionarPago(tipo, precio);
}

void Departamento::darAlta()
{
  this->comprobarZonaActual();
  this->getZonaActual()->darAlta();
}

void Departamento::seleccionarPropiedad(int codigo)
{
  this->comprobarZonaActual();
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

void Departamento::seleccionarChat(string email)
{
  this->comprobarZonaActual();
  this->zonaActual->seleccionarChat(email);
}

void Departamento::addMensaje(DtMensaje mensaje)
{
  this->comprobarZonaActual();
  this->zonaActual->addMensaje(mensaje);
}

Departamento::~Departamento()
{
  delete this->zonas;
}
