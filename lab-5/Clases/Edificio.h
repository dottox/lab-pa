#ifndef EDIFICIO_H
#define EDIFICIO_H

#include "Propiedad.h" 

#include "../Datatypes/DtInfo.h"
#include "../Datatypes/DtEdificio.h"
#include "../Datatypes/DtDatosApartamento.h"

#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/IDictionary.h"

#include <string>
using namespace std;

class Propiedad;
class ICollectible;
class IDictionary;
struct DtInfo;
struct DtEdificio;
struct DtDatosApartamento;


class Edificio : public ICollectible {
  private:
    IDictionary* apartamentos;

    Propiedad* apartamentoActual = nullptr;


    

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

    // Otros
    void seleccionarPropiedad(int);
    void deseleccionarPropiedad();

    DtEdificio getInfo();

    ICollection* getInfoPropiedad(string);

    void agregarDatosApt(DtDatosApartamento);

    void seleccionarPago(string, float);
    void darAlta(int);


    // Destructor
    ~Edificio();
};

#endif
