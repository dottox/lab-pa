#ifndef PROPIEDAD_H
#define PROPIEDAD_H

#include "../Datatypes/DtDireccion.h"
#include "../Datatypes/DtInfo.h"
#include "../Datatypes/DtMensaje.h"
#include "../Datatypes/DtDatosApartamento.h"
#include "../Datatypes/DtDatosCasa.h"
#include "../Datatypes/DtChat.h"

#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/IDictionary.h"

#include "Inmobiliaria.h"
#include "Chat.h"
#include "Interesado.h"

#include <string>
using namespace std;

class Inmobiliaria;
class Chat;
class Interesado;
class IDictionary;
class ICollectible;
struct DtChat;
struct DtDatosApartamento;
struct DtDatosCasa;
struct DtDireccion;
struct DtInfo;
struct DtDatos;
struct DtMensaje;


class Propiedad : public ICollectible {
  protected:
    IDictionary* chats;
    Chat* chatActual = nullptr;
    Inmobiliaria* inmobiliaria;

    int codigo;
    int cantAmbientes;
    int cantDormitorios;
    int cantBanios;
    bool garaje;
    DtDireccion direccion;
    float mtsCuadradosEdificados;
    float mtsCuadradosTotales;
    string tipo;
    float precio;
    
    int miZona;
    char miDepartamento;

  public:
    Propiedad();
    Propiedad(int, int, int, int, bool, DtDireccion, float, float, string, float, Inmobiliaria*, int, char);
    
    // Getters
    virtual int getCodigo();
    virtual int getCantAmbientes();
    virtual int getCantDormitorios();
    virtual int getCantBanios();
    virtual bool getGaraje();
    virtual DtDireccion getDireccion();
    virtual float getMtsCuadradosEdificados();
    virtual float getMtsCuadradosTotales();
    virtual string getTipo();
    virtual float getPrecio();
    virtual int getZona();
    virtual char getDepartamento();

    virtual string getNombreInmobiliaria();
    virtual Chat* getChatActual();
    virtual IDictionary* getChats();
    virtual Inmobiliaria* getInmobiliaria();
    virtual ICollection* chat__getMensajes();

    // Setters
    virtual void setCodigo(int);
    virtual void setCantAmbientes(int);
    virtual void setCantDormitorios(int);
    virtual void setCantBanios(int);
    virtual void setGaraje(bool);
    virtual void setDireccion(DtDireccion);
    virtual void setMtsCuadradosEdificados(float);
    virtual void setMtsCuadradosTotales(float);
    virtual void setTipo(string);
    virtual void setPrecio(float);
    virtual void setInmobiliaria(Inmobiliaria*);

    // Otros
    virtual DtInfo getInfoPropiedad(string); // Este se utiliza para obtener info de la propiedad con los mensajes.
    virtual DtDatos getDatos() = 0; // Este se utiliza para obtener los datos detallados de la propiedad junto a su inmobiliaria.
    virtual void seleccionarChat(string); 
    virtual bool isChatSeleccionado();
    virtual void deseleccionarChat();
    virtual void addChat(Usuario*);
    virtual void chat__addMensaje(DtMensaje);
    virtual void getConversaciones(ICollection*);
    virtual ICollection* chat__getUltimosMensajes(string);

    virtual void aux__deseleccionarTodo();


    // Destructor
    virtual ~Propiedad();
};

#endif
