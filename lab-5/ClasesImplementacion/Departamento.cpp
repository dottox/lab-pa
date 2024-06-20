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
  Zona* zona = new Zona(codigo, nombre, this->getCodigo());
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

void Departamento::propiedad__addChat(Usuario* interesado)
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  try {
    this->getZonaActual()->propiedad__addChat(interesado);
  } catch (const char* e) {
    throw e;
  }
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

ICollection* Departamento::zona__getInfoPropiedades(string email) {
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  try {
    return this->getZonaActual()->getInfoPropiedades(email);
  } catch (const char* e) {
    throw e;
  }
}

ICollection* Departamento::edificio__getInfoPropiedades(string email) {
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  try {
    return this->getZonaActual()->edificio__getInfoPropiedades(email);
  } catch (const char* e) {
    throw e;
  }

}

ICollection* Departamento::zona__listarEdificios()
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  try {
    return this->getZonaActual()->listarEdificios();
  } catch (const char* e) {
    throw e;
  }
}

void Departamento::zona__darDeAltaEdificio(DtEdificio edificio,Usuario* Inmobiliaria)
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->getZonaActual()->darDeAltaEdificio(edificio, Inmobiliaria);
}

void Departamento::deseleccionarZonaActual() {
  this->zonaActual = nullptr;
}

void Departamento::aux__deseleccionarTodo(bool borrarCasa = false)
{
  if (this->getZonaActual() != nullptr) {
    this->getZonaActual()->aux__deseleccionarTodo(borrarCasa);
  }
  this->deseleccionarZonaActual();
}


void Departamento::zona__seleccionarEdificio(string nombre)
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->getZonaActual()->seleccionarEdificio(nombre);
}

void Departamento::edificio__agregarDatosApt(DtDatosApartamento datos, Usuario* inmobiliaria)
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->getZonaActual()->edificio__agregarDatosApt(datos, inmobiliaria);
}

DtDatos Departamento::zona__edificio__getDatosPropiedadNoSeleccionada(int codigo) {
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  try {
    return this->getZonaActual()->zona__edificio__getDatosPropiedadNoSeleccionada(codigo);
  } catch (const char* e) {
    throw e;
  }

}

DtDatos Departamento::zona__edificio__getDatosPropiedad()
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  try {
    return this->getZonaActual()->zona__edificio__getDatosPropiedad();
  } catch (const char* e) {
    throw e;
  }
}

ICollection* Departamento::chat__getUltimosMensajes(string email) {
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  try {
    return this->getZonaActual()->chat__getUltimosMensajes(email);
  } catch (const char* e) {
    throw e;
  }
}

void Departamento::zona__agregarDatosCasa(DtDatosCasa datos, Usuario* inmobiliaria)
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->getZonaActual()->agregarDatosCasa(datos, inmobiliaria);
}

Propiedad* Departamento::zona__edificio__darAlta()
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  } try {
    return this->getZonaActual()->zona__edificio__darAlta();
  } catch (const char* e) {
    throw e;
  }
}

void Departamento::zona__seleccionarPropiedad(int codigo)
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

bool Departamento::propiedad__isChatSeleccionado()
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  return this->getZonaActual()->propiedad__isChatSeleccionado();
}

void Departamento::propiedad__seleccionarChat(string email)
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->getZonaActual()->propiedad__seleccionarChat(email);
}

void Departamento::chat__addMensaje(DtMensaje mensaje)
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  this->zonaActual->chat__addMensaje(mensaje);
}

string Departamento::propiedad__getNombreInmobiliaria()
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  } 
  try{
    return this->getZonaActual()->propiedad__getNombreInmobiliaria();
  } catch (const char* e) {
    throw e;
  }
}

DtInfo* Departamento::propiedad__detallesPropiedad(int codigo, string email){
  if(zonaActual == nullptr){
    throw "No hay zona seleccionada";
  }
  try {
    return this->getZonaActual()->propiedad__detallesPropiedad(codigo, email);
  } catch (const char* e) {
    throw e;
  }
}

ICollection* Departamento::chat__getMensajes()
{
  if (this->getZonaActual() == nullptr) {
    throw "No hay zona seleccionada";
  }
  return this->getZonaActual()->chat__getMensajes();
}


bool Departamento::zona__eliminarPropiedad(int codigo){
  IIterator* it;
  try {
    bool encontrado = false;
    IIterator* it = this->zonas->getIterator();
    while (it->hasCurrent() && !encontrado) {
      Zona* zona = dynamic_cast<Zona*>(it->getCurrent());
      encontrado = zona->eliminarPropiedad(codigo);
      it->next();
    }
    delete it;
    return encontrado;
  } catch (const char* e) {
    delete it;
    throw e;
  }
}

Departamento::~Departamento()
{
  delete this->zonas;
}
