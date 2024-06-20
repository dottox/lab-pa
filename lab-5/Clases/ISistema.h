#ifndef ISISTEMA_H
#define ISISTEMA_H

#include "Usuario.h"
#include "Departamento.h"

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

class ISistema {
  public:
  
    // Getters
    virtual Usuario* getUsuarioActual() = 0;
    virtual Departamento* getDepartamentoActual() = 0;
  
    // Setters
    virtual void seleccionarUsuarioActual(string) = 0;
    virtual void seleccionarDepartamento(char) = 0;

    virtual void deseleccionarUsuarioActual() = 0;
    virtual void deseleccionarDepartamentoActual() = 0;

    // Otros
    virtual DtDatos zona__edificio__getDatosPropiedad() = 0;
    virtual DtDatos zona__edificio__getDatosPropiedadSinActual(int) = 0;
    virtual ICollection* zona__listarPropiedades() = 0;
    virtual ICollection* edificio__listarPropiedades() = 0;
    virtual ICollection* propiedad__listarConversaciones() = 0;
    virtual ICollection* listarInmobiliarias() = 0;
    virtual void listarReporteInmobiliarias() = 0;
    virtual ICollection* listarDepartamentos() = 0;
    virtual ICollection* zona__listarEdificios() = 0;
    virtual ICollection* departamento__listarZonas() = 0;
    virtual ICollection* chat__getMensajes() = 0;

    virtual void propiedad__addChat(Usuario*) = 0;

    virtual void chat__guardarMensaje(DtMensaje) = 0;
    virtual void propiedad__crearConversacion() = 0;
    virtual void aux__deseleccionarTodo(bool) = 0;
    virtual void zona__seleccionarPropiedad(int) = 0;
    virtual void zona__seleccionarEdificio(string) = 0;
    virtual void departamento__seleccionarZona(int) = 0;
    virtual void propiedad__seleccionarChat() = 0;
    virtual void cancelarInicio() = 0;
    virtual void iniciarSesion(string, string) = 0;
    virtual void cerrarSesion() = 0;

    virtual bool verificarUsuario(string) = 0;
    virtual bool isLogueado() = 0;
    virtual bool validarContrasenia(string) = 0;
    virtual bool propiedad__isChatSeleccionado() = 0;

    virtual DtInfo* propiedad__detallesPropiedad(int) = 0;
    virtual string getEmailUsuarioActual() = 0;

    // cu: Alta Inmobiliaria
    virtual void darDeAltaInmobiliaria(string, string, DtDireccion) = 0;

    // cu: Alta Interesado
    virtual void darDeAltaInteresado(string, string, string, string, DtFecha) = 0;

    // cu: Consultar propiedad
    virtual string propiedad__getNombreInmobiliaria() = 0;

    // cu: Enviar Mensaje Interesado
    virtual ICollection* chat__getUltimosMensajesUsuarioActualPropiedadActual() = 0;

    // cu: Enviar Mensaje Inmobiliaria
    virtual void propiedad__seleccionarChatInmobiliaria(string, int) = 0;
    virtual bool inmobiliaria__isChatSeleccionado() = 0;
    virtual ICollection* inmobiliaria__getMensajesChatActual() = 0;
    virtual void inmobiliaria__addMensajeChatActual(DtMensaje) = 0;

    // cu: Alta Edificio
    virtual void zona__darDeAltaEdificio(DtEdificio) = 0;
    
    // cu: Modificar Propiedad
    virtual void inmobiliaria__modificarPropiedadCasa(DtDatosCasa,int) = 0;
    virtual void inmobiliaria__modificarPropiedadApartamento(DtDatosApartamento,int) = 0;

    // cu: Alta Propiedad
    virtual void zona__datosCasa(DtDatosCasa) = 0;
    virtual void edificio__datosApt(DtDatosApartamento) = 0;
    virtual void zona__edificio__darAlta() = 0;
    virtual int generarCodigoPropiedad() = 0;

    // cu: Eliminar Propiedad
    virtual void zona__eliminarPropiedad(int) = 0; 

    // Destructor
    virtual ~ISistema();
};

#endif
