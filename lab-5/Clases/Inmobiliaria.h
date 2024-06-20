#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include "Propiedad.h"
#include "Chat.h"

#include "../Datatypes/DtDireccion.h"
#include "../Datatypes/DtFecha.h"

#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/IDictionary.h"


class Usuario;
class Propiedad;
class Chat;
class IDictionary;
struct DtDireccion;

class Inmobiliaria : public Usuario {
  private:
    DtDireccion direccion;
    IDictionary* propiedades;
    IDictionary* edificios; // Deberíamos gestionarlos en una colección, pero de igual manera, puede estar sujeto a cambios, de momento no haré nada con esto.

    Chat* chatActual = nullptr;
  
  public:
    // Constructor
    Inmobiliaria(string, string, DtDireccion);

    // Otros
    void addPropiedad(Propiedad*);
    Propiedad* buscarPropiedad(int);
    string getTipoUsuario();

    // Getters
    IDictionary* getPropiedades();
    DtDireccion getDireccion();
    ICollection* propiedad__getConversaciones();
    void propiedad__seleccionarChatInmobiliaria(string, int);



    // Setters
    void setDireccion(DtDireccion);

    // cu EliminarPropiedad
    void eliminarPropiedad(int);

    // cu: Listar reporte de Inmobiliarias
    void listarReporte();

    // cu: Enviar mensaje inmo
    bool isChatSeleccionado();
    ICollection* getMensajesChatActual();
    void addMensajeChatActual(DtMensaje);
  
    // Destructor
    ~Inmobiliaria();
};

#endif
