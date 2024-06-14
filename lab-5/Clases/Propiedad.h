#ifndef PROPIEDAD_H
#define PROPIEDAD_H

#include "../Datatypes/DtDireccion.h"
#include "../Datatypes/DtInfo.h"
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

class Propiedad : public ICollectible {
  private:
    IDictionary* chats;
    Chat* chatActual;
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
    int getCodigo();
    int getCantAmbientes();
    int getCantDormitorios();
    int getCantBanios();
    bool getGaraje();
    DtDireccion getDireccion();
    float getMtsCuadradosEdificados();
    float getMtsCuadradosTotales();
    string getTipo();
    float getPrecio();

    Chat* getChatActual();
    IDictionary* getChats();
    Inmobiliaria* getInmobiliaria();

    // Setters
    void setCodigo(int);
    void setCantAmbientes(int);
    void setCantDormitorios(int);
    void setCantBanios(int);
    void setGaraje(bool);
    void setDireccion(DtDireccion);
    void setMtsCuadradosEdificados(float);
    void setMtsCuadradosTotales(float);
    void setTipo(string);
    void setPrecio(float);
    void setInmobiliaria(Inmobiliaria*);

    // Otros
    Chat* createChat(Interesado*);
    DtInfo* getInfoPropiedad(string);
    void setChatActual(string);
    void addChat(ICollectible*);

    // Destructor
    ~Propiedad();
};

#endif
