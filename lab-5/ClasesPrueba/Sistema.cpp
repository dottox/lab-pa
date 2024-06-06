#include "Sistema.h"

Sistema * Sistema::instance = NULL;

Sistema::Sistema(){

}

Sistema::~Sistema() {

}

Sistema * Sistema::getInstance() {
    if (instance == NULL)
        instance = new Sistema();
    return instance;
}

void Sistema::agregarPersona (string s) {
    this->socio = new Persona(s);
}

string Sistema::getNombreSocio() {
    if (this->socio != NULL)
        return this->socio->getNombre();
    return "ERROR. NO HAY SOCIO ASOCIADO";
}