#include "Empresa.h"


Empresa::Empresa(string id, Direccion dir){
    this->id = id;
    this->direccion = dir;
}

void Empresa::setDireccion(Direccion d){
    this->direccion = d;
}

Direccion Empresa::getDireccion(){
    return this->direccion;
}

string Empresa::getId(){
    return this->id;
}

Empresa::~Empresa() {}