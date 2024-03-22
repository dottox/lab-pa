#ifndef ANIMAL_H
#define ANIMAL_H

#include "Persona.h"
#include <cstdlib>
#include <string>

class Persona;

class Animal {
    protected:
        Persona * duenio;
        string nombre;
        int hambre;

    public:
        Animal(string);

        string getNombre();
        int getHambre();
        Persona * getDuenio();

        void setNombre(string);
        void agregarPersona(Persona *);

        virtual void imprimirConcreto() = 0;
        void imprimir();

        void alimentar();

        virtual ~Animal();
};

#endif
