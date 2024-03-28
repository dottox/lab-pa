#ifndef EMPRESA_H
#define EMPRESA_H

#include "../datatypes/dtypes.h"

class Empleado;

class Empresa {
    public:
        Empresa(string,Direccion);

        // SETTERS
        void setDireccion(Direccion);

        // GETTERS
        string getId();
        Direccion getDireccion();
        virtual float getDescuento() = 0;

        virtual ~Empresa();

    protected:
        string id;
        Direccion direccion;
};

#endif