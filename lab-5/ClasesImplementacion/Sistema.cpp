#include "../Clases/Sistema.h"

#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/collections/List.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/Integer.h"
#include "../ICollection/String.h"


Sistema* Sistema::instancia = nullptr;


Sistema::Sistema() {
  this->usuarios = new OrderedDictionary();
  this->departamentos = new OrderedDictionary();

  Usuario* usuario = new Administrador("admin", "admin");
  IKey* key = new String((char*)usuario->getEmail().c_str());
  this->usuarios->add(key, usuario);
  
  this->darDeAltaInmobiliaria("Pedro", "pedrito", DtDireccion("Calle 1", "Ciudad 1", 1));
  this->darDeAltaInmobiliaria("Juan", "juanito", DtDireccion("Calle 2", "Ciudad 2", 2));
  this->darDeAltaInmobiliaria("Nicolas", "escobar", DtDireccion("Calle 3", "Ciudad 3", 3));
  this->darDeAltaInmobiliaria("Artigas", "jose", DtDireccion("Calle 3", "Ciudad 3", 3));
  this->darDeAltaInmobiliaria("goncho", "goncho", DtDireccion("Calle 4", "Ciudad 4", 4));
  this->darDeAltaInteresado("Jose", "josecito", "Jose", "Perez", DtFecha(1, 1, 2000));
  this->darDeAltaInteresado("Maria", "mariquita", "Maria", "Gomez", DtFecha(2, 2, 2000));
  this->darDeAltaInteresado("Ana", "anita", "Ana", "Rodriguez", DtFecha(3, 3, 2000));
  this->darDeAltaInteresado("Carlos", "carlitos", "Carlos", "Fernandez", DtFecha(4, 4, 2000));
  this->aux__deseleccionarTodo(false);
  
  /* *** Carga de datos en Montevideo *** */
  this->darAltaDepartamento('A', "Montevideo");
  this->seleccionarDepartamento('A');
  this->departamento__darAltaZona(1, "Centro");
  this->departamento__darAltaZona(2, "Cordon");

  // Dando de alta una casa, un edificio y un apartamento
  this->departamento__seleccionarZona(1);
  this->seleccionarUsuarioActual("Pedro");
  this->zona__datosCasa(DtDatosCasa(this->generarCodigoPropiedad(), 2, 3, 4, true, DtDireccion("Calle 1", "Ciudad 1", 1), 5, 6, "alquiler", 7, 8));
  this->zona__edificio__darAlta();
  this->zona__datosCasa(DtDatosCasa(this->generarCodigoPropiedad(), 2, 3, 4, true, DtDireccion("Calle 2", "Ciudad 2", 2), 5, 6, "venta", 7, 8));
  this->zona__edificio__darAlta();
  this->zona__datosCasa(DtDatosCasa(this->generarCodigoPropiedad(), 2, 3, 4, true, DtDireccion("Calle 3", "Ciudad 3", 3), 5, 6, "alquiler", 7, 8));
  this->zona__edificio__darAlta();
  this->zona__darDeAltaEdificio(DtEdificio("Edificio 1", 10, 11));
  this->zona__darDeAltaEdificio(DtEdificio("Edificio 2", 12, 13));
  this->zona__darDeAltaEdificio(DtEdificio("Edificio 3", 14, 15));
  this->aux__deseleccionarTodo(false);
  /* ------------------------------------ */

  /* *** Carga de datos en Canelones *** */
  this->darAltaDepartamento('B', "Canelones");
  this->seleccionarDepartamento('B');
  this->departamento__darAltaZona(1, "Santa Lucia");
  this->departamento__darAltaZona(2, "Las Piedras");
  this->departamento__darAltaZona(3, "Progreso");

  // Dando de alta una casa, un edificio y un apartamento
  this->departamento__seleccionarZona(3);
  this->seleccionarUsuarioActual("Juan");
  this->zona__datosCasa(DtDatosCasa(this->generarCodigoPropiedad(), 2, 3, 4, true, DtDireccion("Calle 4", "Ciudad 4", 4), 5, 6, "Casa", 7, 8));
  this->zona__edificio__darAlta();
  this->zona__datosCasa(DtDatosCasa(this->generarCodigoPropiedad(), 2, 3, 4, true, DtDireccion("Calle 5", "Ciudad 5", 5), 5, 6, "Casa", 7, 8));
  this->zona__edificio__darAlta();
  this->zona__datosCasa(DtDatosCasa(this->generarCodigoPropiedad(), 2, 3, 4, true, DtDireccion("Calle 6", "Ciudad 6", 6), 5, 6, "Casa", 7, 8));
  this->zona__edificio__darAlta();
  this->zona__darDeAltaEdificio(DtEdificio("Edificio 4", 16, 17));
  this->zona__darDeAltaEdificio(DtEdificio("Edificio 5", 18, 19));
  this->zona__darDeAltaEdificio(DtEdificio("Edificio 6", 20, 21));
  this->aux__deseleccionarTodo(false);
  /* ------------------------------------ */

  this->darAltaDepartamento('C', "Maldonado");
  this->seleccionarDepartamento('C');
  this->departamento__darAltaZona(1, "Punta del Este");
  this->departamento__darAltaZona(2, "Piriapolis");
  this->aux__deseleccionarTodo(false);

  this->darAltaDepartamento('D', "Rocha");
  this->seleccionarDepartamento('D');
  this->departamento__darAltaZona(1, "La Paloma");
  this->departamento__darAltaZona(2, "Cabo Polonio");
  this->aux__deseleccionarTodo(false);

  this->darAltaDepartamento('E', "Colonia");
  this->darAltaDepartamento('F', "San Jose");
  this->darAltaDepartamento('G', "Soriano");
  this->darAltaDepartamento('H', "Paysandu");
  this->darAltaDepartamento('I', "Rio Negro");
  this->darAltaDepartamento('J', "Artigas");
  
  this->aux__deseleccionarTodo(false);
}

void Sistema::darAltaDepartamento(char codigo,string nombre){
  string c(1, codigo);
  IKey* key = new String(c);
  String* strKey = dynamic_cast<String*>(key); 
  Departamento* departamento = new Departamento(codigo, nombre);
  this->departamentos->add(key, departamento);
}


void Sistema::departamento__darAltaZona(int codigo, string nombre) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->darAltaZona(codigo, nombre);
  } catch (const char* e) {
    throw e;
  }
}

Sistema* Sistema::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Sistema();
  }
  return instancia;
};

Usuario* Sistema::getUsuarioActual() {
  return this->usuarioActual;
}

Departamento* Sistema::getDepartamentoActual() {
  return this->departamentoActual;
}

void Sistema::seleccionarUsuarioActual(string email) {
  IKey* key = new String((char*)email.c_str());
  this->usuarioActual = dynamic_cast<Usuario*>(this->usuarios->find(key));
  delete key;
  
  if (this->usuarioActual == nullptr) {
    throw "No existe usuario";
  }
}

void Sistema::deseleccionarUsuarioActual() {
  this->usuarioActual = nullptr;
}

void Sistema::deseleccionarDepartamentoActual() {
  this->departamentoActual = nullptr;
}

ICollection* Sistema::zona__listarPropiedades() {
  if (this->departamentoActual == nullptr) {
    throw "No hay departamento seleccionado";
  } else if (this->usuarioActual == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  try {
    string mailUsuario = this->usuarioActual->getEmail();
    return this->departamentoActual->zona__getInfoPropiedades(mailUsuario);
  } catch (const char* e) {
    throw e;
  }
}

ICollection* Sistema::edificio__listarPropiedades() {
  if (this->departamentoActual == nullptr) {
    throw "No hay departamento seleccionado";
  } else if (this->usuarioActual == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  try {
    string mailUsuario = this->usuarioActual->getEmail();
    return this->departamentoActual->edificio__getInfoPropiedades(mailUsuario);
  } catch (const char* e) {
    throw e;
  }

}

bool Sistema::verificarUsuario(string email) {
  IKey* key = new String((char*)email.c_str());
  Usuario* usuario = dynamic_cast<Usuario*>(this->usuarios->find(key));
  delete key;
  return usuario != nullptr;
}

void Sistema::chat__guardarMensaje(DtMensaje mensaje) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->chat__addMensaje(mensaje);
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::propiedad__seleccionarChat() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->propiedad__seleccionarChat(this->getUsuarioActual()->getEmail());
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::propiedad__seleccionarChatInmobiliaria(string email, int codigo) {
  try {
    Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(this->getUsuarioActual());
    inmo->propiedad__seleccionarChatInmobiliaria(email, codigo);
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::propiedad__crearConversacion() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamen to seleccionado";
  } else if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->propiedad__addChat(this->getUsuarioActual());
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::zona__seleccionarPropiedad(int codigo) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->zona__seleccionarPropiedad(codigo);
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::zona__edificio__darAlta() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    Propiedad* prop = this->getDepartamentoActual()->zona__edificio__darAlta();
    Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(this->getUsuarioActual());
    inmo->addPropiedad(prop);
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::zona__datosCasa(DtDatosCasa datos) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->zona__agregarDatosCasa(datos, this->getUsuarioActual());
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::inmobiliaria__modificarPropiedadCasa(DtDatosCasa datos,int codigo) {
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  try {
    Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(this->getUsuarioActual());
    inmo->modificarDatosCasa(datos, codigo);
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::inmobiliaria__modificarPropiedadApartamento(DtDatosApartamento datos,int codigo) {
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  try {
    Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(this->getUsuarioActual());
    inmo->edificio__modificarDatosApartamento(datos, codigo);
  } catch (const char* e) {
    throw e;
  }
}




void Sistema::edificio__datosApt(DtDatosApartamento datos) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->edificio__agregarDatosApt(datos, this->getUsuarioActual());
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::zona__seleccionarEdificio(string nombre) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->zona__seleccionarEdificio(nombre);
  } catch (const char* e) {
    throw e;
  }
}

int Sistema::generarCodigoPropiedad() {
  return this->autoincrementalCodigoPropiedad++;
}

ICollection* Sistema::zona__listarEdificios() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    return this->getDepartamentoActual()->zona__listarEdificios();
  } catch (const char* e) {
    throw e;
  }
}

ICollection* Sistema::chat__getUltimosMensajesUsuarioActualPropiedadActual() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  } 
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  try {
    string email = this->getUsuarioActual()->getEmail();
    return this->getDepartamentoActual()->chat__getUltimosMensajes(email);
  } catch (const char* e) {
    throw e;
  }
}

DtDatos Sistema::zona__edificio__getDatosPropiedad() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    return this->getDepartamentoActual()->zona__edificio__getDatosPropiedad();
  } catch (const char* e) {
    throw e;
  }
}

DtDatos Sistema::zona__edificio__getDatosPropiedadSinActual(int codigo) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    return this->getDepartamentoActual()->zona__edificio__getDatosPropiedadNoSeleccionada(codigo);
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::departamento__seleccionarZona(int codigo) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->seleccionarZona(codigo);
  } catch (const char* e) {
    throw e;
  }
}

ICollection* Sistema::departamento__listarZonas() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  try {
    return this->getDepartamentoActual()->getZonas();
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::seleccionarDepartamento(char codigo) {
  string c(1, codigo);
  IKey* key = new String(c);
  Departamento* dep = dynamic_cast<Departamento*>(this->departamentos->find(key));
  delete key;
  if (dep == nullptr) {
    throw "No existe departamento";
  }
  this->departamentoActual = dep;
}

ICollection* Sistema::listarDepartamentos() {
  ICollection* ret = new List();
  IIterator* it = this->departamentos->getIterator();
  while (it->hasCurrent()) {
    Departamento* dep = dynamic_cast<Departamento*>(it->getCurrent());
    DtDepartamento data = dep->getInfo();
    DtDepartamento* info = new DtDepartamento(data.getCodigo(), data.getNombre());
    ret->add(info); 
    it->next();
  }
  delete it;
  return ret;
}

void Sistema::aux__deseleccionarTodo(bool borrarCasa = false) {

  if (this->getDepartamentoActual() != nullptr) {
    this->getDepartamentoActual()->aux__deseleccionarTodo(borrarCasa);
  }
  this->deseleccionarDepartamentoActual();
}

void Sistema::iniciarSesion(string email, string contrasenia) {
  IKey* key = new String((char*)email.c_str());
  Usuario* usuario = dynamic_cast<Usuario*>(this->usuarios->find(key));
  delete key;
  if (usuario == nullptr) {
    throw "No existe usuario";
  }
  if (usuario->getContrasenia() != contrasenia) {
    throw "Contrasenia incorrecta";
  }
  this->usuarioActual = usuario;
}

void Sistema::cerrarSesion(){
  this->usuarioActual = nullptr;
}

void Sistema::cancelarInicio() {
  deseleccionarUsuarioActual();
  deseleccionarDepartamentoActual();
}

bool Sistema::propiedad__isChatSeleccionado() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  return this->getDepartamentoActual()->propiedad__isChatSeleccionado();
}

bool Sistema::inmobiliaria__isChatSeleccionado() {
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }

  Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(this->getUsuarioActual());
  return inmo->isChatSeleccionado();
}

ICollection* Sistema::inmobiliaria__getMensajesChatActual() {
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }

  Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(this->getUsuarioActual());
  return inmo->getMensajesChatActual();

}

void Sistema::inmobiliaria__addMensajeChatActual(DtMensaje mensaje) {
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }

  Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(this->getUsuarioActual());
  inmo->addMensajeChatActual(mensaje);
}

bool Sistema::validarContrasenia(string contrasenia) {
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }

  return this->getUsuarioActual()->getContrasenia() == contrasenia;
}

void Sistema::darDeAltaInmobiliaria(string email, string contrasenia, DtDireccion direccion) {
  if (this->verificarUsuario(email)) {
    throw "Inmobiliaria ya registrada";
  }

  Inmobiliaria* inmobiliaria = new Inmobiliaria(email, contrasenia, direccion);
  IKey* key = new String((char*)email.c_str());
  this->usuarios->add(key, inmobiliaria);
}

void Sistema::darDeAltaInteresado(string email, string contrasenia, string nombre, string apellido, DtFecha edad) {
  if (this->verificarUsuario(email)) {
    throw "Inmobiliaria ya registrada";
  }

  Interesado* interesado = new Interesado(email, contrasenia, nombre, apellido, edad);
  IKey* key = new String((char*)email.c_str());
  this->usuarios->add(key, interesado);
}

bool Sistema::isLogueado(){
  return this->getUsuarioActual() != nullptr;
}

ICollection* Sistema::listarInmobiliarias(){
  ICollection* ret = new List();
  IIterator* it = this->usuarios->getIterator();
  while (it->hasCurrent()) {
    Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(it->getCurrent());
  
    if (inmo != nullptr) {
      DtInmobiliaria* info = new DtInmobiliaria(inmo->getEmail(), inmo->getDireccion());
      ret->add(info); 
    }

    it->next();
  }
  delete it;
  return ret;
}

void Sistema::listarReporteInmobiliarias(){
  IIterator* it = this->usuarios->getIterator();
  while (it->hasCurrent()) {
    Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(it->getCurrent());
    if (inmo != nullptr) {
      inmo->listarReporte();
    }
    it->next();
  }
  delete it;
}

DtInfo* Sistema::propiedad__detallesPropiedad(int codigo){
  if(this->departamentoActual == nullptr){
    throw "No hay departamento seleccionado";
  }
  try {
    if (this->getUsuarioActual() == nullptr) {
      throw "No hay usuario seleccionado";
    }
    string email = this->getUsuarioActual()->getEmail();
    return this->getDepartamentoActual()->propiedad__detallesPropiedad(codigo, email);
  } catch (const char* e) {
    throw e;
  }
}

string Sistema::propiedad__getNombreInmobiliaria(){
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  try {
    return this->getDepartamentoActual()->propiedad__getNombreInmobiliaria();
  } catch (const char* e) {
    throw e;
  }
}

string Sistema::getEmailUsuarioActual(){
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  return this->getUsuarioActual()->getEmail();
}

ICollection* Sistema::propiedad__listarConversaciones(){ 
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  if (getUsuarioActual()->getTipoUsuario() != "Inmobiliaria") {
    throw "El usuario no es una inmobiliaria";
  }
  Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(this->getUsuarioActual());
  
  try {
    return inmo->propiedad__getConversaciones();
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::propiedad__addChat(Usuario* usuario){
  if(this->departamentoActual == nullptr){
    throw "No hay departamento seleccionado";
  }
  try {
    this->getDepartamentoActual()->propiedad__addChat(usuario);
  } catch (const char* e) {
    throw e;
  }
}

ICollection* Sistema::chat__getMensajes(){
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  try {
    return this->getDepartamentoActual()->chat__getMensajes();
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::zona__darDeAltaEdificio(DtEdificio edificio){
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  } 
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  try {
    this->getDepartamentoActual()->zona__darDeAltaEdificio(edificio, this->getUsuarioActual());
  } catch (const char* e) {
    throw e;
  }
}

// NO ESTA HECHO
void Sistema::zona__eliminarPropiedad(int codigo){
  IIterator* it;
  try {
    bool find = false;
    IIterator* it = this->departamentos->getIterator();
    while (it->hasCurrent() && !find) {
      Departamento* dep = dynamic_cast<Departamento*>(it->getCurrent());
      find = dep->zona__eliminarPropiedad(codigo);
      it->next();
    }
    delete it;
  } catch (const char* e) {
    delete it;
    throw e;
  }
}

Sistema::~Sistema() {
  delete this->usuarios;
  delete this->departamentos;
}