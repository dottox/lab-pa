#ifndef EDIFICIO_H
#define EDIFICIO_H

#include "Apartamento.h" 
#include "Inmobiliaria.h"

#include "../Datatypes/DtInfo.h"
#include "../Datatypes/DtEdificio.h"
#include "../Datatypes/DtDatosApartamento.h"

#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/IDictionary.h"

#include <string>
using namespace std;

class Apartamento;
class ICollectible;
class IDictionary;
class Inmobiliaria;
struct DtInfo;
struct DtEdificio;
struct DtDatosApartamento;


class Edificio : public ICollectible {
  private:
    IDictionary* apartamentos;
    Propiedad* apartamentoActual = nullptr;
    Inmobiliaria* inmobiliaria;

    string nombre;
    int cantPisos;
    float gastosComunes;

  public:
    Edificio(string, int, float, Inmobiliaria*);
    
    // Getters
    string getNombre();
    int getCantPisos();
    float getGastosComunes();
    Propiedad* getPropiedadActual();

    // Setters
    void setNombre(string);
    void setCantPisos(int);
    void setGastosComunes(float);

    // Otros
    void seleccionarPropiedad(int);
    void deseleccionarPropiedad();

    DtDatos getDatosApartamento();

    DtEdificio getInfo();

    DtInfo getInfoPropiedad(int, string);

    ICollection* getInfoPropiedades(string);

    void agregarDatosApt(DtDatosApartamento, Usuario*);

    void seleccionarPago(string, float);
    void darAlta();

    void deseleccionarTodo(bool);

    // Destructor
    ~Edificio();
};

#endif
