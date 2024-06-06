#ifndef ISISTEMA_H
#define ISISTEMA_H

#include <iostream>
using namespace std;

class ISistema {
    public:
        virtual void agregarPersona (string) = 0;
        virtual string getNombreSocio () = 0;
        ~ISistema();
};

#endif