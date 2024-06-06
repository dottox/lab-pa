#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
using namespace std;

#include "Animal.h"

class Animal;

class Persona {
    public:
        Persona (string);
        string getNombre(); 
        void imprimir();
        void agregarMascota(Animal *);
    private:
        string nombre;
        Animal * miMascota;
};

#endif
