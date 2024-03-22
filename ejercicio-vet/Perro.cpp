#include "Perro.h"
#include <iostream>

void Perro::imprimirConcreto() {
    std::cout << "Soy un Perro de nombre: " << this->nombre << std::endl;
}

Perro::Perro(string nombre) : Animal(nombre) {}
