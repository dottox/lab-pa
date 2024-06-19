#include "../Clases/Sistema.h"

#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/Integer.h"
#include "../ICollection/String.h"

Sistema* Sistema::instancia = nullptr;

Sistema::Sistema() {
  this->usuarios = new OrderedDictionary();
  this->departamentos = new OrderedDictionary();
}

Sistema* Sistema::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Sistema();
  }
  return instancia;
};

void Sistema::seleccionarUsuarioActual(string email) {
  IKey* key = new String((char*)email.c_str());
  this->usuarioActual = dynamic_cast<Usuario*>(this->usuarios->find(key));
  delete key;
}

void Sistema::seleccionarDepartamentoActual(char codigo) {
  IKey* key = new String((char*)codigo);
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
  if (this->departamentoActual == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  this->departamentoActual->addMensaje(mensaje);
}

void Sistema::seleccionarChat(string email) {
  if (this->departamentoActual == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  this->departamentoActual->seleccionarChat(email);
}