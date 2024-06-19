#include "../Clases/Sistema.h"

#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/collections/List.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/Integer.h"
#include "../ICollection/String.h"


Sistema* Sistema::instancia = nullptr;


Sistema::Sistema() {
  this->usuarios = new OrderedDictionary();
  this->departamentos = new OrderedDictionary();

  Usuario* usuario = new Administrador("admin", "admin");
  IKey* key = new String((char*)usuario->getEmail().c_str());
  this->usuarios->add(key, usuario);
}

Sistema* Sistema::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Sistema();
  }
  return instancia;
};

Usuario* Sistema::getUsuarioActual() {
  return this->usuarioActual;
}

Departamento* Sistema::getDepartamentoActual() {
  return this->departamentoActual;
}

void Sistema::seleccionarUsuarioActual(string email) {
  IKey* key = new String((char*)email.c_str());
  this->usuarioActual = dynamic_cast<Usuario*>(this->usuarios->find(key));
  delete key;
  
  if (this->usuarioActual == nullptr) {
    throw "No existe usuario";
  }
}

void Sistema::seleccionarDepartamentoActual(char codigo) {
  char* c = new char(codigo);
  IKey* key = new String(c);
  delete c;
  this->departamentoActual = dynamic_cast<Departamento*>(this->departamentos->find(key));
  delete key;
}

void Sistema::deseleccionarUsuarioActual() {
  this->usuarioActual = nullptr;
}

void Sistema::deseleccionarDepartamentoActual() {
  this->departamentoActual = nullptr;
}

ICollection* Sistema::listarPropiedades() {
  if (this->departamentoActual == nullptr) {
    throw "No hay departamento seleccionado";
  } else if (this->usuarioActual == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  string mailUsuario = this->usuarioActual->getEmail();
  return this->departamentoActual->getInfoPropiedades(mailUsuario);
}

bool Sistema::verificarUsuario(string email) {
  IKey* key = new String((char*)email.c_str());
  Usuario* usuario = dynamic_cast<Usuario*>(this->usuarios->find(key));
  delete key;
  return usuario != nullptr;
}

void Sistema::guardarMensaje(DtMensaje mensaje) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  this->getDepartamentoActual()->addMensaje(mensaje);
}

void Sistema::seleccionarChat(string email) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  this->getDepartamentoActual()->seleccionarChat(this->getUsuarioActual()->getEmail());
}

void Sistema::crearConversacion() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamen to seleccionado";
  } else if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  this->getDepartamentoActual()->addChat(this->getUsuarioActual());
}

void Sistema::seleccionarPropiedad(int codigo) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  this->getDepartamentoActual()->seleccionarPropiedad(codigo);
}

void Sistema::darAlta() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  this->getDepartamentoActual()->darAlta();
}

void Sistema::seleccionarPago(string metodo, float monto) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  this->getDepartamentoActual()->seleccionarPago(metodo, monto);
}

void Sistema::datosCasa(DtDatosCasa datos) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  this->getDepartamentoActual()->agregarDatosCasa(datos);
}

void Sistema::datosApt(DtDatosApartamento datos) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  this->getDepartamentoActual()->agregarDatosApt(datos);
}

void Sistema::seleccionarEdificio(string nombre) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  this->getDepartamentoActual()->seleccionarEdificio(nombre);
}

ICollection* Sistema::listarEdificios() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  return this->getDepartamentoActual()->listarEdificios();
}

void Sistema::seleccionarTipoPropiedad(string tipo) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  this->getDepartamentoActual()->seleccionarTipoPropiedad(tipo);
}

void Sistema::seleccionarZona(int codigo) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  this->getDepartamentoActual()->seleccionarZona(codigo);
}

ICollection* Sistema::listarZonas() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  return this->getDepartamentoActual()->getZonas();
}

void Sistema::seleccionarDepartamento(char codigo) {
  char* c = new char(codigo);
  IKey* key = new String(c);
  delete c;
  Departamento* dep = dynamic_cast<Departamento*>(this->departamentos->find(key));
  delete key;
  if (dep == nullptr) {
    throw "No existe departamento";
  }
  this->departamentoActual = dep;
}

ICollection* Sistema::listarDepartamentos() {
  ICollection* ret = new List();
  IIterator* it = this->departamentos->getIterator();
  while (it->hasCurrent()) {
    Departamento* dep = dynamic_cast<Departamento*>(it->getCurrent());
    DtDepartamento data = dep->getInfo();
    DtDepartamento* info = new DtDepartamento(data.getCodigo(), data.getNombre());
    ret->add(info); 
    it->next();
  }
  delete it;
  return ret;
}

void Sistema::deseleccionarTodo() {

  if (this->getDepartamentoActual() != nullptr) {
    this->getDepartamentoActual()->deseleccionarTodo();
  }
  this->deseleccionarDepartamentoActual();
}

void Sistema::iniciarSesion(string email, string contrasenia) {
  IKey* key = new String((char*)email.c_str());
  Usuario* usuario = dynamic_cast<Usuario*>(this->usuarios->find(key));
  delete key;
  if (usuario == nullptr) {
    throw "No existe usuario";
  }
  if (usuario->getContrasenia() != contrasenia) {
    throw "Contrasenia incorrecta";
  }
  this->usuarioActual = usuario;
}

void Sistema::cerrarSesion(){
  this->usuarioActual = nullptr;
}

void Sistema::cancelarInicio() {
  deseleccionarUsuarioActual();
  deseleccionarDepartamentoActual();
}


bool Sistema::registrarContrasenia(string contrasenia) {
  // ????
  return true;
}

bool Sistema::validarContrasenia(string contrasenia) {
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }

  return this->getUsuarioActual()->getContrasenia() == contrasenia;
}

void Sistema::darDeAltaInmobiliaria(string email, string contrasenia, DtDireccion direccion) {
  if (this->verificarUsuario(email)) {
    throw "Inmobiliaria ya registrada";
  }

  Inmobiliaria* inmobiliaria = new Inmobiliaria(email, contrasenia, direccion);
  IKey* key = new String((char*)email.c_str());
  this->usuarios->add(key, inmobiliaria);
}

void Sistema::darDeAltaInteresado(string email, string contrasenia, string nombre, string apellido, DtFecha edad) {
  if (this->verificarUsuario(email)) {
    throw "Inmobiliaria ya registrada";
  }

  Interesado* interesado = new Interesado(email, contrasenia, nombre, apellido, edad);
  IKey* key = new String((char*)email.c_str());
  this->usuarios->add(key, interesado);
}

bool Sistema::isLogueado(){
  return this->getUsuarioActual() != nullptr;
}

ICollection* Sistema::listarInmobiliarias(){
  ICollection* ret = new List();
  IIterator* it = this->usuarios->getIterator();
  while (it->hasCurrent()) {
    Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(it->getCurrent());
  
    if (inmo != nullptr) {
      DtInmobiliaria* info = new DtInmobiliaria(inmo->getEmail(), inmo->getDireccion());
      ret->add(info); 
    }

    it->next();
  }
  delete it;
  return ret;
}

DtDatos Sistema::detallesPropiedad(int codigo){
  if(this->departamentoActual == nullptr){
    throw "No hay departamento seleccionado";
  }
  this->getDepartamentoActual()->detallesPropiedad(codigo);
}


ICollection* Sistema::listarConversaciones(){
  ICollection* ret = new List();
  
  if (getUsuarioActual()->getTipoUsuario() != "Inmobiliaria") {
    throw "El usuario no es una inmobiliaria"
  }
  IIterator* it = this->getUsuarioActual->getIterator();
  while (it->hasCurrent()) {
    Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(it->getCurrent());
    ICollection* ret = new List();
    IIterator* it = this->usuarios->getIterator();
    inmo->getPropiedades()
    if (inmo != nullptr) {
      inmo->
      DtInmobiliaria* info = new DtInmobiliaria(inmo->getEmail(), inmo->getDireccion());
      ret->add(info); 
    }

    it->next();
  }
  delete it;
  return ret;
}

Sistema::~Sistema() {
  delete this->usuarios;
  delete this->departamentos;
}