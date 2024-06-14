#ifndef CHAT_H
#define CHAT_H

#include "../Datatypes/DtMensaje.h"

#include "Inmobiliaria.h"
#include "Interesado.h"
#include "Mensaje.h"

#include "../ICollection/interfaces/ICollectible.h"

#include <string>
#include <vector>
using namespace std;

class Inmobiliaria;
class Interesado;
class Mensaje;
class ICollectible;
class ICollection;

class Chat : public ICollectible {
  private:
    ICollection* mensajes;
    Inmobiliaria* inmobiliaria;
    Interesado* interesado;
  
  public:
    Chat(Inmobiliaria*, Interesado*);
    
    // Getters
    ICollection* getMensajes();
    Inmobiliaria* getInmobiliaria();
    Interesado* getInteresado();

    // Setters
    void setInmobiliaria(Inmobiliaria*);
    void setInteresado(Interesado*);

    // Otros
    void addMensaje(ICollectible*);
    Mensaje* createMensaje(string, string);
    void deleteMensajes();

    // Funciones de los casos de uso
    ICollection* seleccionarConversacion();

    // Destructor
    ~Chat();
};

#endif
