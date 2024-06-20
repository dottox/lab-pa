#ifndef SISTEMA_H
#define SISTEMA_H

#include "../Clases/Usuario.h"
#include "../Clases/Departamento.h"
#include "../Clases/ISistema.h"
#include "../Clases/Administrador.h"
#include "../Clases/Interesado.h"
#include "../Clases/Inmobiliaria.h"
#include "../Clases/Chat.h"

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
class Administrador;
class Chat;
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

    int autoincrementalCodigoPropiedad = 1;

    static Sistema* instancia; // Aquí no se inicializa la variable, se debe hacer en el .cpp con "Sistema* Sistema::instancia = nullptr;"

    Sistema();
    void darAltaDepartamento(char, string);
    void departamento__darAltaZona(int, string);


  public:

    // Getters
    static Sistema* getInstancia();
    Usuario* getUsuarioActual();
    Departamento* getDepartamentoActual();

    // Setters
    void seleccionarUsuarioActual(string);

    void deseleccionarUsuarioActual();
    void deseleccionarDepartamentoActual();

    // Otros 
    ICollection* zona__listarPropiedades();
    ICollection* edificio__listarPropiedades();
    ICollection* propiedad__listarConversaciones();
    ICollection* listarDepartamentos();
    ICollection* zona__listarEdificios();
    ICollection* departamento__listarZonas();
    ICollection* chat__getMensajes();

    void chat__guardarMensaje(DtMensaje);
    void propiedad__crearConversacion();

    void zona__seleccionarEdificio(string);
    void propiedad__seleccionarChat();
    
    bool verificarUsuario(string);
    void cancelarInicio();
    void iniciarSesion(string, string);
    void cerrarSesion();
    bool isLogueado();
    bool propiedad__isChatSeleccionado();
    void propiedad__addChat(Usuario*);

    bool validarContrasenia(string);
    
    string getEmailUsuarioActual();
    DtDatos zona__edificio__getDatosPropiedad();
    DtDatos zona__edificio__getDatosPropiedadSinActual(int);

    // cu: Alta Inmobiliaria
    void darDeAltaInmobiliaria(string, string, DtDireccion);

    // cu: Alta Interesado
    void darDeAltaInteresado(string, string, string, string, DtFecha);

    // cu: Obtener Reporte Inmobiliarias
    ICollection* listarInmobiliarias();
    void listarReporteInmobiliarias();

    // cu: Consultar propiedad
    void seleccionarDepartamento(char);
    void departamento__seleccionarZona(int);
    void zona__seleccionarPropiedad(int);
    DtInfo* propiedad__detallesPropiedad(int);
    void aux__deseleccionarTodo(bool);
    string propiedad__getNombreInmobiliaria();

    // cu: Enviar Mensaje Interesado
    // seleccionarDepartamento
    // seleccionarZona
    // seleccionarPropiedad
    ICollection* chat__getUltimosMensajesUsuarioActualPropiedadActual();
   
    // cu: Alta Edificio
    void zona__darDeAltaEdificio(DtEdificio);

    // cu: Alta Propiedad
    void zona__datosCasa(DtDatosCasa);
    void edificio__datosApt(DtDatosApartamento);
    void zona__edificio__darAlta();
    int generarCodigoPropiedad();

    //cu: Enviar mensaje inmobiliaria
    void propiedad__seleccionarChatInmobiliaria(string, int);
    bool inmobiliaria__isChatSeleccionado();
    ICollection* inmobiliaria__getMensajesChatActual();
    void inmobiliaria__addMensajeChatActual(DtMensaje);

    //cu: Modificar propiedad
    void inmobiliaria__modificarPropiedadApartamento(DtDatosApartamento,int);
    void inmobiliaria__modificarPropiedadCasa(DtDatosCasa,int);

    // cu: eliminar propiedad
    void zona__eliminarPropiedad(int);

    // Destructor
    ~Sistema();
};

#endif
