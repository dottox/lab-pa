#ifndef MENSAJE_H
#define MENSAJE_H

#include "../Datatypes/DtFecha.cpp"
#include "../Datatypes/DtHora.cpp"
#include "../Datatypes/DtMensaje.cpp"

class Mensaje {
  private:
    DtFecha fecha;
    DtFecha hora;
    string texto;
  
  public:
    Mensaje(DtFecha, DtHora, string);
    DtMensaje getMensaje();
    ~Mensaje();
};

#endif
