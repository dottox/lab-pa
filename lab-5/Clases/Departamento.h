#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include "Zona.h"
#include "Usuario.h"

#include "../Datatypes/DtDepartamento.h"
#include "../Datatypes/DtDatosCasa.h"
#include "../Datatypes/DtDatosApartamento.h"
#include "../Datatypes/DtMensaje.h"

#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/ICollectible.h"

#include <string>
using namespace std;

class Zona;
class Usuario;
class ICollectible;
class IDictionary;
struct DtDepartamento;
struct DtDatosCasa;
struct DtDatosApartamento;
struct DtMensaje;

class Departamento : public ICollectible {
  private:
    IDictionary* zonas;
    Zona* zonaActual = nullptr;
    
    char codigo;
    string nombre;

    Zona* getZonaActual();
    void comprobarZonaActual();
  
  public:
    Departamento(char, string);
    
    // Getters
    char getCodigo();
    string getNombre();


    // Setters
    void setCodigo(char);
    void setNombre(string);

    // Funciones de Zona
    void addChat(Usuario*);

    // Otros
    DtDepartamento getInfo();
    ICollection* getZonas();
    void buscarZona(int); // ??? <-- Explicate :s
    ICollection* getInfoPropiedades(string);
    void seleccionarTipoPropiedad(string);
    ICollection* listarEdificios();
    void seleccionarEdificio(string);
    void agregarDatosApt(DtDatosApartamento);
    void agregarDatosCasa(DtDatosCasa);
    void seleccionarPago(string, float);
    void darAlta();

    void seleccionarPropiedad(int);

    void seleccionarZona(int);

    void seleccionarChat(string);
    void addMensaje(DtMensaje);

    // Destructor
    ~Departamento();
};

#endif
