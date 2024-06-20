#ifndef SISTEMA_H
#define SISTEMA_H

#include "../Clases/Usuario.h"
#include "../Clases/Departamento.h"
#include "../Clases/ISistema.h"
#include "../Clases/Administrador.h"
#include "../Clases/Interesado.h"
#include "../Clases/Inmobiliaria.h"

#include "../Datatypes/DtDepartamento.h"
#include "../Datatypes/DtDatosCasa.h"
#include "../Datatypes/DtDatosApartamento.h"
#include "../Datatypes/DtInmobiliaria.h"

#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/ICollectible.h"

#include <string>
using namespace std;

class Zona;
class Usuario;
class Departamento;
class ISistema;
class Inmobiliaria;
class Interesado;
class Administraor;
struct DtDepartamento;
struct DtDatosCasa;
struct DtDatosApartamento;
struct DtInmobiliaria;
struct DtEdificio;
class ICollection;
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
    void darAltaDepartamento(char, string);
    void darAltaZona(int, string);


  public:

    // Getters
    static Sistema* getInstancia();
    Usuario* getUsuarioActual();
    Departamento* getDepartamentoActual();

    // Setters
    void seleccionarUsuarioActual(string);
    void seleccionarDepartamentoActual(char);

    void deseleccionarUsuarioActual();
    void deseleccionarDepartamentoActual();

    // Otros
    ICollection* listarPropiedades();
    ICollection* listarConversaciones();
    ICollection* listarDepartamentos();
    ICollection* listarEdificios();
    ICollection* listarZonas();
    ICollection* getMensajes();

    void guardarMensaje(DtMensaje);
    void crearConversacion();
    void darAlta();
    void datosCasa(DtDatosCasa);
    void datosApt(DtDatosApartamento);

    void seleccionarPago(string, float);
    void seleccionarEdificio(string);
    void seleccionarTipoPropiedad(string);
    void seleccionarChat();
    
    bool verificarUsuario(string);
    void cancelarInicio();
    void iniciarSesion(string, string);
    bool registrarContrasenia(string);
    void cerrarSesion();
    bool isLogueado();
    bool isChatSeleccionado();
    void addChat(Usuario*);

    bool validarContrasenia(string);
    
    string getEmailUsuarioActual();
    DtDatos getDatosPropiedad();

    // cu: Alta Inmobiliaria
    void darDeAltaInmobiliaria(string, string, DtDireccion);

    // cu: Alta Interesado
    void darDeAltaInteresado(string, string, string, string, DtFecha);

    // cu: Obtener Reporte Inmobiliarias
    ICollection* listarInmobiliarias();

    // cu: Consultar propiedad
    void seleccionarDepartamento(char);
    void seleccionarZona(int);
    void seleccionarPropiedad(int);
    DtInfo* detallesPropiedad(int);
    void deseleccionarTodo(bool);

    // cu: Enviar Mensaje Interesado
    // seleccionarDepartamento
    // seleccionarZona
    // seleccionarPropiedad
    ICollection* getUltimosMensajesUsuarioActualPropiedadActual();
   
    // cu: Alta Edificio
    void darDeAltaEdificio(DtEdificio);

    // Destructor
    ~Sistema();
};

#endif
