#ifndef SISTEMA_H
#define SISTEMA_H

#include "../Clases/Usuario.h"
#include "../Clases/Departamento.h"
#include "../Clases/ISistema.h"

#include "../Datatypes/DtDepartamento.h"
#include "../Datatypes/DtDatosCasa.h"
#include "../Datatypes/DtDatosApartamento.h"

#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/ICollectible.h"

#include <string>
using namespace std;

class Zona;
class ICollectible;
class IDictionary;

class Sistema : public ISistema {
  private:
    IDictionary* departamentos;
    Departamento* departamentoActual = nullptr;
    
    IDictionary* usuarios;
    Usuario* usuarioActual = nullptr;

    static Sistema* instancia; // Aquí no se inicializa la variable, se debe hacer en el .cpp con "Sistema* Sistema::instancia = nullptr;"

    Sistema();
    Usuario* getUsuarioActual();
    Departamento* getDepartamentoActual();

  public:
    // Getters
    static Sistema* getInstancia();

    // Setters
    void seleccionarUsuarioActual(string);
    void seleccionarDepartamentoActual(char);

    void deseleccionarUsuarioActual();
    void deseleccionarDepartamentoActual();

    // Otros
    ICollection* listarPropiedades();
    bool verificarUsuario(string);
    void guardarMensaje(DtMensaje);
    void seleccionarChat(string);
    void crearConversacion();
    void seleccionarPropiedad(int);
    void darAlta();
    void seleccionarPago(string, float);
    void datosCasa(DtDatosCasa);
    void datosApt(DtDatosApartamento);
    void seleccionarEdificio(string);
    ICollection* listarEdificios();
    void seleccionarTipoPropiedad(string);
    void seleccionarZona(int);
    ICollection* listarZonas();
    void seleccionarDepartamento(char);
    ICollection* listarDepartamentos();
    void cancelarInicio();
    void iniciarSesion(string, string);
    void registrarUsuario(string, string, string);
    bool registrarContrasenia(string);
    bool validarContrasenia(string);
    void darDeAltaInmobiliaria(string, string, DtDireccion);

    // Destructor
    ~Sistema();
};

#endif
