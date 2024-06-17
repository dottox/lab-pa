#ifndef EDIFICIO_H
#define EDIFICIO_H

#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/interfaces/ICollectible.h"

#include <string>
using namespace std;

class ICollectible;
class IDictionary;
class Inmobiliaria;

class Edificio : public ICollectible {
  private:
    IDictionary* apartamentos;
    

    string nombre;
    int cantPisos;
    float gastosComunes;

  public:
    Edificio(string, int, float, Inmboliaria*);
    
    // Getters
    string getNombre();
    int getCantPisos();
    float getGastosComunes();

    // Setters
    void setNombre(string);
    void setCantPisos(int);
    void setGastosComunes(float);

    // Destructor
    ~Edificio();
};

#endif
