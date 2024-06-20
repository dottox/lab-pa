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

  
  public:
    Departamento(char, string);
    void darAltaZona(int, string);
    
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
    virtual ICollection* getMensajes();
    void seleccionarPago(string, float);
    DtInfo* detallesPropiedad(int, string);

    DtDatos getDatosPropiedad();

    void seleccionarPropiedad(int);

    void seleccionarZona(int);

    bool isChatSeleccionado();
    void seleccionarChat(string);
    void addMensaje(DtMensaje);

    void deseleccionarZonaActual();
    void deseleccionarTodo(bool);
  
    // cu_AltaEdificio
    void darDeAltaEdificio(DtEdificio, Usuario*);

    // cu_AltaPropiedad
    void agregarDatosApt(DtDatosApartamento, Usuario*);
    void agregarDatosCasa(DtDatosCasa, Usuario*);
    void darAlta();
    int zona__generarCodigoPropiedad();
    ICollection* getUltimosMensajes(string);

    // cu Modificar propiedad
    void modificarDatosApartamento(DtDatosApartamento);
    void modificarDatosCasa(DtDatosCasa);

    // Destructor
    ~Departamento();
};

#endif
