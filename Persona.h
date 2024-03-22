#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
using namespace std;

#include "Animal.h"


class Animal;

class Persona {
    public:
        Persona(string);
        string getNombre(); 
        void setNombre(string); 
        void imprimir();
        void agregarMascota(Animal *);
        Animal * getMascota();
    private:
        string nombre;
        Animal * miMascota;
};

#endif
