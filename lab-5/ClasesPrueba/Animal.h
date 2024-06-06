#ifndef ANIMAL_H
#define ANIMAL_H
#include "Persona.h"

class Persona;

class Animal {
    public:
        virtual void imprimirConcreto() = 0;
        void imprimir();
        void agregarPersona (Persona *);
        virtual ~Animal();
    protected:
        Persona * duenio;
};

#endif
