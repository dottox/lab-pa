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

    // Funciones de propiedad
    void propiedad__addChat(Usuario*);

    // Otros
    DtDepartamento getInfo();
    ICollection* getZonas();
    ICollection* zona__getInfoPropiedades(string);
    ICollection* zona__listarEdificios();
    void zona__seleccionarEdificio(string);
    virtual ICollection* chat__getMensajes();
    DtInfo* propiedad__detallesPropiedad(int, string);

    DtDatos zona__edificio__getDatosPropiedad();
    DtDatos zona__edificio__getDatosPropiedadNoSeleccionada(int);

    void zona__seleccionarPropiedad(int);

    void seleccionarZona(int);

    bool propiedad__isChatSeleccionado();
    void propiedad__seleccionarChat(string);
    void chat__addMensaje(DtMensaje);

    void deseleccionarZonaActual();
    void aux__deseleccionarTodo(bool);
  
    // cu_AltaEdificio
    void zona__darDeAltaEdificio(DtEdificio, Usuario*);

    // cu_AltaPropiedad
    void edificio__agregarDatosApt(DtDatosApartamento, Usuario*);
    void zona__agregarDatosCasa(DtDatosCasa, Usuario*);
    Propiedad* zona__edificio__darAlta();
    ICollection* chat__getUltimosMensajes(string);

    // cu: Consultar propiedad
    string propiedad__getNombreInmobiliaria();
    ICollection* edificio__getInfoPropiedades(string);

    // cu Modificar propiedad
    void edificio__modificarDatosApartamento(DtDatosApartamento);
    void zona__modificarDatosCasa(DtDatosCasa);

    // cu Eliminar propiedad
    bool zona__eliminarPropiedad(int);

    // Destructor
    ~Departamento();
};

#endif
