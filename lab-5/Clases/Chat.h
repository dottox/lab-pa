#ifndef CHAT_H
#define CHAT_H

#include "../Datatypes/DtMensaje.h"

#include "Inmobiliaria.h"
#include "Interesado.h"

#include "../ICollection/interfaces/ICollection.h"

#include <string>
using namespace std;

class Chat : public ICollection {
  private:
    ICollection* mensajes;
    Inmobiliaria* inmobiliaria;
    Interesado* interesado;
    int cantMensajes;
  
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

    // Destructor
    ~Chat();
};

#endif
