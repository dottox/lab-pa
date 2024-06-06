#include "Animal.h"

Animal::~Animal(){}

void Animal::imprimir() {
    this->imprimirConcreto();
    std::cout << "Mi duenio: " << this->duenio->getNombre() << std::endl;
}

void Animal::agregarPersona (Persona * p) {
    this->duenio = p;
}
