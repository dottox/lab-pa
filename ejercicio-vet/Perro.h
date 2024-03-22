#ifndef PERRO_H
#define PERRO_H

#include "Animal.h"

class Perro : public Animal {
    public:
        void imprimirConcreto();
        Perro(string);
};

#endif