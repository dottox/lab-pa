#include "Persona.h"
#include <iostream>

void Persona::agregarMascota (Animal * a) {
    this->miMascota = a;
    a->agregarPersona(this);
}

Persona::Persona(string n) {
    this->nombre = n;
}

string Persona::getNombre() {
    return this->nombre;
}