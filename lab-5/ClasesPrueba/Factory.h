#ifndef FACTORY_H
#define FACTORY_H

#include "ISistema.h"
#include "Sistema.h"

class Factory {
    public:
        static ISistema * getSistema();
};

#endif