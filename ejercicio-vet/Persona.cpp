#include "Persona.h"
#include <iostream>

void Persona::agregarMascota (Animal * a) {
    this->miMascota = a;
    a->agregarPersona(this);
}

Persona::Persona(string n) {
    this->nombre = n;
}

void Persona::setNombre(string nom) {
    this->nombre = nom;
} 

string Persona::getNombre() {
    return this->nombre;
}

Animal * Persona::getMascota(){
    return this->miMascota;
}