#ifndef ZONA_H
#define ZONA_H

#include "Edificio.h"
#include "Propiedad.h" 

#include "../Datatypes/DtZona.h"
#include "../Datatypes/DtInfo.h"
#include "../Datatypes/DtEdificio.h"
#include "../Datatypes/DtDatosApartamento.h"
#include "../Datatypes/DtDatosCasa.h"

#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/ICollectible.h"

#include <string>
using namespace std;

class Edificio;
class Propiedad;
class ICollectible;
class IDictionary;
struct DtZona;
struct DtInfo;
struct DtEdificio;
struct DtDatosApartamento;
struct DtDatosCasa;

class Zona : public ICollectible {
  private:
    IDictionary* propiedades;
    IDictionary* edificios;
    Edificio* edificioActual = nullptr;
    Propiedad* propiedadActual = nullptr;
    
    int codigo;
    string nombre;
  
  public:
    Zona(int, string);
    
    // Getters
    int getCodigo();
    string getNombre();

    // Setters
    void setCodigo(int);
    void setNombre(string);

    // Otros
    void seleccionarEdificio(int);
    void seleccionarPropiedad(int);
    void deseleccionarEdificio();
    void deseleccionarPropiedad();

    DtZona getInfo();

    ICollection* getInfoPropiedades(string);
    ICollection* listarEdificios();

    void agregarDatosApt(DtDatosApartamento);
    void agregarDatosCasa(DtDatosCasa);

    void seleccionarPago(string, float);
    void darAlta();

    // Destructor
    ~Zona();
};

#endif
