#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include "Zona.h"
#include "Interesado.h"

#include "../Datatypes/DtDepartamento.h"
#include "../Datatypes/DtDatosCasa.h"
#include "../Datatypes/DtDatosApt.h"

#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/ICollectible.h"

#include <string>
using namespace std;

class Zona;
class ICollectible;
class IDictionary;

class Departamento : public ICollectible {
  private:
    IDictionary* zonas;
    Zona* zonaActual = nullptr;
    
    char codigo;
    string nombre;
  
  public:
    Departamento(char, string);
    
    // Getters
    char getCodigo();
    string getNombre();

    // Setters
    void setCodigo(char);
    void setNombre(string);

    // Funciones de Zona
    void addChat(Interesado*);

    // Otros
    DtDepartamento getInfo();
    ICollection* getZonas();
    void buscarZona(int); // ???
    ICollection* getInfoPropiedades(string);
    void seleccionarTipoPropiedad(string);
    ICollection* listarEdificios();
    void seleccionarEdificio(int);
    void agregarDatosApt(DtDatosApartamento);
    void agregarDatosCasa(DtDatosCasa);
    void seleccionarPago(string, float);
    void darAlta();

    // Destructor
    ~Departamento();
};

#endif
