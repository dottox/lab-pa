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
  this->deseleccionarTodo(false);
  
  this->darAltaDepartamento('A', "Montevideo");
  this->seleccionarDepartamento('A');
  this->darAltaZona(1, "Centro");
  this->darAltaZona(2, "Cordon");
  this->deseleccionarTodo(false);

  this->darAltaDepartamento('B', "Canelones");
  this->seleccionarDepartamento('B');
  this->darAltaZona(1, "Santa Lucia");
  this->darAltaZona(2, "Las Piedras");
  this->darAltaZona(3, "Progreso");
  this->deseleccionarTodo(false);

  this->darAltaDepartamento('C', "Maldonado");
  this->seleccionarDepartamento('C');
  this->darAltaZona(1, "Punta del Este");
  this->darAltaZona(2, "Piriapolis");
  this->deseleccionarTodo(false);

  this->darAltaDepartamento('D', "Rocha");
  this->seleccionarDepartamento('D');
  this->darAltaZona(1, "La Paloma");
  this->darAltaZona(2, "Cabo Polonio");
  this->deseleccionarTodo(false);

  // this->darAltaDepartamento('E', "Colonia");
  // this->darAltaDepartamento('F', "San Jose");
  // this->darAltaDepartamento('G', "Soriano");
  // this->darAltaDepartamento('H', "Paysandu");
  // this->darAltaDepartamento('I', "Rio Negro");
  // this->darAltaDepartamento('J', "Artigas");


  // this->deseleccionarTodo();
}

void Sistema::darAltaDepartamento(char codigo,string nombre){
  string c(1, codigo);
  IKey* key = new String(c);
  String* strKey = dynamic_cast<String*>(key); 
  Departamento* departamento = new Departamento(codigo, nombre);
  this->departamentos->add(key, departamento);
}


void Sistema::darAltaZona(int codigo, string nombre) {
  if (this->departamentoActual == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    this->departamentoActual->darAltaZona(codigo, nombre);
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

ICollection* Sistema::listarPropiedades() {
  if (this->departamentoActual == nullptr) {
    throw "No hay departamento seleccionado";
  } else if (this->usuarioActual == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  try {
    string mailUsuario = this->usuarioActual->getEmail();
    return this->departamentoActual->getInfoPropiedades(mailUsuario);
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

void Sistema::guardarMensaje(DtMensaje mensaje) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->addMensaje(mensaje);
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::seleccionarChat() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->seleccionarChat(this->getUsuarioActual()->getEmail());
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::crearConversacion() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamen to seleccionado";
  } else if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->addChat(this->getUsuarioActual());
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::seleccionarPropiedad(int codigo) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->seleccionarPropiedad(codigo);
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::darAlta() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->darAlta();
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::seleccionarPago(string metodo, float monto) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->seleccionarPago(metodo, monto);
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::datosCasa(DtDatosCasa datos) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->agregarDatosCasa(datos, this->getUsuarioActual());
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::modificarDatosCasa(DtDatosCasa datos); {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->modificarDatosCasa(datos, this->getUsuarioActual());
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::modificarDatosApt(DtDatosApartamento datos) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  try {
    //this->getDepartamentoActual()->agregarDatosApartamento(datos, this->getUsuarioActual());
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::darAltaModificacion(DtDatosCasa datos) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->agregarDatosCasa(datos, this->getUsuarioActual());
  } catch (const char* e) {
    throw e;
  }
}


void Sistema::datosApt(DtDatosApartamento datos) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->agregarDatosApt(datos, this->getUsuarioActual());
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::seleccionarEdificio(string nombre) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->seleccionarEdificio(nombre);
  } catch (const char* e) {
    throw e;
  }
}

int Sistema::zona__generarCodigoPropiedad() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    return this->getDepartamentoActual()->zona__generarCodigoPropiedad();
  } catch (const char* e) {
    throw e;
  }

}

ICollection* Sistema::listarEdificios() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    return this->getDepartamentoActual()->listarEdificios();
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::seleccionarTipoPropiedad(string tipo) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->seleccionarTipoPropiedad(tipo);
  } catch (const char* e) {
    throw e;
  }
}

ICollection* Sistema::getUltimosMensajesUsuarioActualPropiedadActual() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  } 
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  try {
    string email = this->getUsuarioActual()->getEmail();
    return this->getDepartamentoActual()->getUltimosMensajes(email);
  } catch (const char* e) {
    throw e;
  }
}

DtDatos Sistema::getDatosPropiedad() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    return this->getDepartamentoActual()->getDatosPropiedad();
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::seleccionarZona(int codigo) {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  
  try {
    this->getDepartamentoActual()->seleccionarZona(codigo);
  } catch (const char* e) {
    throw e;
  }
}

ICollection* Sistema::listarZonas() {
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

void Sistema::deseleccionarTodo(bool borrarCasa = false) {

  if (this->getDepartamentoActual() != nullptr) {
    this->getDepartamentoActual()->deseleccionarTodo(borrarCasa);
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


bool Sistema::registrarContrasenia(string contrasenia) {
  // ????
  return true;
}

bool Sistema::isChatSeleccionado() {
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  return this->getDepartamentoActual()->isChatSeleccionado();
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

DtInfo* Sistema::detallesPropiedad(int codigo){
  if(this->departamentoActual == nullptr){
    throw "No hay departamento seleccionado";
  }
  try {
    if (this->getUsuarioActual() == nullptr) {
      throw "No hay usuario seleccionado";
    }
    string email = this->getUsuarioActual()->getEmail();
    return this->getDepartamentoActual()->detallesPropiedad(codigo, email);
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

ICollection* Sistema::listarConversaciones(){
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  if (getUsuarioActual()->getTipoUsuario() != "Inmobiliaria") {
    throw "El usuario no es una inmobiliaria";
  }
  Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(this->getUsuarioActual());
  
  try {
    return inmo->getConversaciones();
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::addChat(Usuario* usuario){
  if(this->departamentoActual == nullptr){
    throw "No hay departamento seleccionado";
  }
  try {
    this->getDepartamentoActual()->addChat(usuario);
  } catch (const char* e) {
    throw e;
  }
}

ICollection* Sistema::getMensajes(){
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  }
  try {
    return this->getDepartamentoActual()->getMensajes();
  } catch (const char* e) {
    throw e;
  }
}

void Sistema::darDeAltaEdificio(DtEdificio edificio){
  if (this->getDepartamentoActual() == nullptr) {
    throw "No hay departamento seleccionado";
  } 
  if (this->getUsuarioActual() == nullptr) {
    throw "No hay usuario seleccionado";
  }
  try {
    this->getDepartamentoActual()->darDeAltaEdificio(edificio, this->getUsuarioActual());
  } catch (const char* e) {
    throw e;
  }
}

Sistema::~Sistema() {
  delete this->usuarios;
  delete this->departamentos;
  }