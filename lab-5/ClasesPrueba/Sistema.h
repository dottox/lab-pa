#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "ISistema.h"
#include "Persona.h"

class Sistema : public ISistema {
    private:
        Sistema();
        static Sistema * instance;
        Persona * socio;
    public:
        ~Sistema();
        static Sistema * getInstance();
        void agregarPersona (string);
        string getNombreSocio ();
};

#endif