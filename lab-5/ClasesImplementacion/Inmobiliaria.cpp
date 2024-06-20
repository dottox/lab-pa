#include "../Clases/Inmobiliaria.h"
#include "../ICollection/collections/List.h"

#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/Integer.h"
#include "../ICollection/String.h"

Inmobiliaria::Inmobiliaria(string email, string contrasenia, DtDireccion direccion) : Usuario::Usuario(email, contrasenia)
{
  this->direccion = direccion;
  this->propiedades = new OrderedDictionary();
}

void Inmobiliaria::addPropiedad(Propiedad* propiedad)
{
  IKey* key = new Integer(propiedad->getCodigo());
  this->propiedades->add(key, propiedad);
}

Propiedad* Inmobiliaria::buscarPropiedad(int codigo)
{
  IKey* key = new Integer(codigo);
  Propiedad* propiedad = dynamic_cast<Propiedad*>(this->propiedades->find(key));
  delete key;
  return propiedad;
}

void Inmobiliaria::eliminarPropiedad(int codigo)
{ // Aquí borro a la propiedad de la lista, luego de esto el objeto de la propiedad debe ser eliminado.
  Propiedad* propiedad = this->buscarPropiedad(codigo);
  if(propiedad == nullptr){
    throw "La propiedad no existe";
  }
  IKey* key = new Integer(codigo);
  this->propiedades->remove(key);
};


string Inmobiliaria::getTipoUsuario()
{
  return "Inmobiliaria";
}

IDictionary* Inmobiliaria::getPropiedades()
{
  // Debería retornar una lista de DtPropiedades.
  return this->propiedades;
}

DtDireccion Inmobiliaria::getDireccion()
{
  return DtDireccion(this->direccion);
}


ICollection* Inmobiliaria::propiedad__getConversaciones(){
  IIterator* it = this->propiedades->getIterator();
  ICollection* conversaciones = new List();
  
  while (it->hasCurrent()){
    Propiedad* propiedad = dynamic_cast<Propiedad*>(it->getCurrent());
    propiedad->getConversaciones(conversaciones);
    it->next();
  }
  delete it;
  return conversaciones;
}

void Inmobiliaria::propiedad__seleccionarChatInmobiliaria(string emailInteresado, int codigoPropiedad)
{
  IKey* key = new Integer(codigoPropiedad);
  Propiedad* propiedad = dynamic_cast<Propiedad*>(this->propiedades->find(key));
  delete key;

  if (propiedad != nullptr) {
    propiedad->seleccionarChat(emailInteresado);
    this->chatActual = propiedad->getChatActual();
  } else {
    throw "La propiedad no existe";
  }
}

bool Inmobiliaria::isChatSeleccionado()
{
  return this->chatActual != nullptr;
}

ICollection* Inmobiliaria::getMensajesChatActual()
{
  if (this->chatActual == nullptr) {
    throw "No hay chat seleccionado";
  }

  return this->chatActual->getMensajes();
}

void Inmobiliaria::addMensajeChatActual(DtMensaje mensaje)
{
  if (this->chatActual == nullptr) {
    throw "No hay chat seleccionado";
  }

  this->chatActual->addMensaje(mensaje);
}

#include <map>
#include <iostream>
using namespace std;

void Inmobiliaria::listarReporte() {
  map<char, map<int, int>> conteo;
  IIterator* it = this->propiedades->getIterator();
  while (it->hasCurrent()) {
    Propiedad* propiedad = dynamic_cast<Propiedad*>(it->getCurrent());
    char c = propiedad->getDepartamento();
    int z = propiedad->getZona();
    // if conteo[c] not in conteo, initialize [c][z] in 1.
    if (conteo.find(c) == conteo.end()) {
      conteo[c] = map<int, int>();
      conteo[c][z] = 1;
    } else {
      // if conteo[c][z] not in conteo, initialize [c][z] in 1.
      if (conteo[c].find(z) == conteo[c].end()) {
        conteo[c][z] = 1;
      } else {
        // increment conteo[c][z] by 1.
        conteo[c][z] += 1;
      }
    }
    it->next();
  
  }

  cout << "Inmobiliaria: " << this->getEmail() << endl;
  
  cout << "Direccion: " << this->direccion.getCalle() << " " << this->direccion.getNumero() << ", " << this->direccion.getCiudad() << endl;

  cout << "Propiedades: " << endl;

  for (const auto& department : conteo) {
    char departmentCode = department.first;
    cout << " Department: " << departmentCode << endl;
    
    for (const auto& zone : department.second) {
      int zoneCode = zone.first;
      int count = zone.second;
      cout << "   Zona: " << zoneCode << ", Count: " << count << endl;
    }
  }
  cout << endl;
}

void Inmobiliaria::setDireccion(DtDireccion direccion)
{
  this->direccion = direccion;
}

Inmobiliaria::~Inmobiliaria()
{
  delete this->propiedades;
}