#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include "Propiedad.h"
#include "Chat.h"
#include "Edificio.h"

#include "../Datatypes/DtDireccion.h"
#include "../Datatypes/DtFecha.h"

#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/IDictionary.h"


class Usuario;
class Propiedad;
class Chat;
class Edificio;
class IDictionary;
struct DtDireccion;

class Inmobiliaria : public Usuario {
  private:
    DtDireccion direccion;
    IDictionary* propiedades;
    IDictionary* edificios;

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

    // cu: alta edificio
    void addEdificio(Edificio*);

    // cu: Enviar mensaje inmo
    bool isChatSeleccionado();
    ICollection* getMensajesChatActual();
    void addMensajeChatActual(DtMensaje);

    // cu: Modificar Propiedad
    void modificarDatosCasa(DtDatosCasa, int);
    void edificio__modificarDatosApartamento(DtDatosApartamento,int);

    // Destructor
    ~Inmobiliaria();
};

#endif
