#ifndef ZONA_H
#define ZONA_H

#include "Edificio.h"
#include "Usuario.h" 
#include "Interesado.h" 

#include "../Datatypes/DtZona.h"
#include "../Datatypes/DtInfo.h"
#include "../Datatypes/DtEdificio.h"
#include "../Datatypes/DtDatosApartamento.h"
#include "../Datatypes/DtDatosCasa.h"
#include "../Datatypes/DtMensaje.h"

#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/ICollectible.h"

#include <string>
using namespace std;

class Edificio;
class Usuario;
class Propiedad;
class ICollectible;
class IDictionary;
class String;
struct DtMensaje;
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
    string tipoPropiedadActual;
    
    int codigo;
    string nombre;
  
  public:
    Zona(int, string);
    
    // Getters
    int getCodigo();
    string getNombre();
    Edificio* getEdificioActual();
    Propiedad* getPropiedadActual();


    // Setters
    void setCodigo(int);
    void setNombre(string);

    // Funciones de propiedad
    void addChat(Usuario*);

    // Otros
    void seleccionarEdificio(string);
    void seleccionarPropiedad(int);
    void deseleccionarEdificio();
    void deseleccionarPropiedad();

    DtZona getInfo();
    DtDatos detallesPropiedad(int);

    ICollection* getInfoPropiedades(string);
    ICollection* listarEdificios();

    void agregarDatosApt(DtDatosApartamento);
    void agregarDatosCasa(DtDatosCasa);

    void seleccionarPago(string, float);
    void seleccionarTipoPropiedad(string);
    void darAlta();
    void removePropiedad(int);

    void addMensaje(DtMensaje);
    void seleccionarChat(string);

    void deseleccionarTodo();

    // Destructor
    ~Zona();
};

#endif
