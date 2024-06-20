#include "../Clases/Propiedad.h"

#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/String.h"
#include "../ICollection/collections/OrderedDictionary.h"

#include <iostream>

Propiedad::Propiedad()
{
    this->codigo = 0;
    this->cantAmbientes = 0;
    this->cantDormitorios = 0;
    this->cantBanios = 0;
    this->garaje = false;
    this->mtsCuadradosEdificados = 0;
    this->mtsCuadradosTotales = 0;
    this->tipo = "";
    this->precio = 0;
    this->chats = new OrderedDictionary();
}

Propiedad::Propiedad(int codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garaje, DtDireccion direccion, float mtsCuadradosEdificados, float mtsCuadradosTotales, string tipo, float precio, Inmobiliaria* inmobiliaria)
{
    this->chats = new OrderedDictionary();
    this->inmobiliaria = inmobiliaria;

    this->codigo = codigo;
    this->cantAmbientes = cantAmbientes;
    this->cantDormitorios = cantDormitorios;
    this->cantBanios = cantBanios;
    this->garaje = garaje;
    this->direccion = direccion;
    this->mtsCuadradosEdificados = mtsCuadradosEdificados;
    this->mtsCuadradosTotales = mtsCuadradosTotales;
    this->tipo = tipo;
    this->precio = precio;
}

int Propiedad::getCodigo()
{
    return this->codigo;
}

int Propiedad::getCantAmbientes()
{
    return this->cantAmbientes;
}

int Propiedad::getCantDormitorios()
{
    return this->cantDormitorios;
}

int Propiedad::getCantBanios()
{
    return this->cantBanios;
}

bool Propiedad::getGaraje()
{
    return this->garaje;
}

DtDireccion Propiedad::getDireccion()
{
    return DtDireccion(this->direccion);
}

float Propiedad::getMtsCuadradosEdificados()
{
    return this->mtsCuadradosEdificados;
}

float Propiedad::getMtsCuadradosTotales()
{
    return this->mtsCuadradosTotales;
}

string Propiedad::getTipo()
{
    return this->tipo;
}

float Propiedad::getPrecio()
{
    return this->precio;
}

Chat *Propiedad::getChatActual()
{
    return this->chatActual;
}

IDictionary* Propiedad::getChats()
{
    return this->chats;
}

Inmobiliaria* Propiedad::getInmobiliaria()
{
    return this->inmobiliaria;
}


ICollection* Propiedad::getConversaciones(ICollection* conversaciones)
{
    IIterator* it = this->chats->getIterator();
    while (it->hasCurrent())
    {
        Chat* chat = dynamic_cast<Chat*>(it->getCurrent());
        
        conversaciones->add(chat);
        it->next();
    }
    delete it;
    return conversaciones;
}

void Propiedad::setCodigo(int codigo)
{
    this->codigo = codigo;
}

void Propiedad::setCantAmbientes(int cantAmbientes)
{
    this->cantAmbientes = cantAmbientes;
}

void Propiedad::setCantDormitorios(int cantDormitorios)
{
    this->cantDormitorios = cantDormitorios;
}

void Propiedad::setCantBanios(int cantBanios)
{
    this->cantBanios = cantBanios;
}

void Propiedad::setGaraje(bool garaje)
{
    this->garaje = garaje;
}

void Propiedad::setDireccion(DtDireccion direccion)
{
    this->direccion = direccion;
}

void Propiedad::setMtsCuadradosEdificados(float mtsCuadradosEdificados)
{
    this->mtsCuadradosEdificados = mtsCuadradosEdificados;
}

void Propiedad::setMtsCuadradosTotales(float mtsCuadradosTotales)
{
    this->mtsCuadradosTotales = mtsCuadradosTotales;
}

void Propiedad::setTipo(string tipo)
{
    this->tipo = tipo;
}

void Propiedad::setPrecio(float precio)
{
    this->precio = precio;
}

void Propiedad::setInmobiliaria(Inmobiliaria *inmobiliaria)
{
    this->inmobiliaria = inmobiliaria;
}

ICollection* Propiedad::chat__getUltimosMensajes(string email)
{
    if (this->chatActual == nullptr) {
        throw "No hay chat seleccionado";
    }

    const char* e = email.c_str();
    IKey* key = new String(e);
    ICollectible* c = this->chats->find(key);
    Chat* chat = dynamic_cast<Chat*>(c);
    delete key;
    if (chat == NULL) {
        throw "No se encontro el chat";
    }
    try {
        return chat->getUltimosMensajes();
    } catch (const char* e) {
        throw e;
    }
}

DtInfo Propiedad::getInfoPropiedad(string email)
{
    const char* e = email.c_str();
    IKey* key = new String(e);
    ICollectible* c = this->chats->find(key);
    Chat* chat = dynamic_cast<Chat*>(c);
    delete key;
    if (chat == NULL) {
        return DtInfo(this->codigo, 0, this->direccion);
    }
    return DtInfo(this->codigo, chat->getMensajes()->getSize(), this->direccion);
}

string Propiedad::getNombreInmobiliaria()
{
    return this->getInmobiliaria()->getEmail();
}

void Propiedad::seleccionarChat(string email)
{
    IKey* key = new String((char*)email.c_str());
    Chat* chat = dynamic_cast<Chat*>(this->chats->find(key));
    delete key;
    this->chatActual = chat;
}

void Propiedad::deseleccionarChat()
{
    this->chatActual = nullptr;
}

void Propiedad::addChat(Usuario* usuario)
{   
    Interesado* interesado = (Interesado*)usuario;
    IKey* key = new String((char*)interesado->getEmail().c_str());
    if (key == NULL) {
        delete key;
        throw "No se pudo crear la clave";
    }

    Chat* chat = new Chat(this->getInmobiliaria(), interesado);

    this->chats->add(key, chat);
}

void Propiedad::chat__addMensaje(DtMensaje mensaje)
{
    if (this->getChatActual() == nullptr) {
        throw "No hay chat seleccionado";
    }
    this->getChatActual()->addMensaje(mensaje);
}


void Propiedad::aux__deseleccionarTodo() {
    this->deseleccionarChat();
}

bool Propiedad::isChatSeleccionado(){
    return this->getChatActual() != nullptr;
}

ICollection* Propiedad::chat__getMensajes()
{
    if (this->getChatActual() == nullptr) {
        throw "No hay chat seleccionado";
    }
    return this->getChatActual()->getMensajes();
}

Propiedad::~Propiedad()
{
    delete this->chats;
}