#include "Gato.h"
#include <iostream>

void Gato::imprimirConcreto() {
    std::cout << "Soy un Gato de nombre: " << this->nombre << std::endl;
}

Gato::Gato(string nombre) : Animal(nombre) {}
