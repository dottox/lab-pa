#ifndef PROPIEDAD_H
#define PROPIEDAD_H

#include "../Datatypes/DtDireccion.h"
#include "../Datatypes/DtInfo.h"
#include "../Datatypes/DtMensaje.h"
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
    

  public:
    Propiedad(int, int, int, int, bool, DtDireccion, float, float, string, float, Inmobiliaria*);
    
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

    virtual Chat* getChatActual();
    virtual IDictionary* getChats();
    virtual Inmobiliaria* getInmobiliaria();

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
    virtual void setDatos(DtDatos) = 0;

    // Otros
    virtual DtInfo getInfoPropiedad(string);
    virtual void seleccionarChat(string); 
    virtual void deseleccionarChat();
    virtual void addChat(Interesado*);
    virtual void addMensaje(DtMensaje);

    // Destructor
    virtual ~Propiedad();
};

#endif
