#include "Animal.h"
#include <cstdlib>

Animal::Animal (std::string nom) {
    this->nombre = nom;
    this->duenio = NULL;
    this->hambre = rand() % 10 + 1;
}


string Animal::getNombre() {
    return this->nombre;
}

int Animal::getHambre() {
    return this->hambre;
}

Persona * Animal::getDuenio() {
    return this->duenio;
}


void Animal::setNombre(string nom) {
    this->nombre = nom;
}

void Animal::agregarPersona (Persona * p) {
    this->duenio = p;
}


void Animal::imprimir() {
    this->imprimirConcreto();
    cout << "Mi duenio es: " << this->duenio->getNombre() << std::endl;
}

void Animal::alimentar() {
    if (this->hambre > 0) {
        this->hambre--;
    }
}

Animal::~Animal(){}