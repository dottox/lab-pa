#include "Includes.cpp"
#include <iostream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void limpiarPantalla();
void mostrarCredenciales(ISistema*);
void pantallaBienvenida(ISistema*);
void logearse(ISistema*);
void consultarPropiedad(ISistema*);
void menuInteresado(ISistema*);
void menuAdmin(ISistema*);
void menuInmobiliaria(ISistema*);
void menu(ISistema*);
void registrarUsuario(ISistema*);

void mostrarListadoDepartamentos(ISistema*);
void mostrarListadoZonas(ISistema*);
void mostrarDetallesPropiedad(DtInfo*);

// ****** CU de Administrador ******
void cu_IniciarSesion(ISistema*);
void cu_AltaInmobiliaria(ISistema*);
void cu_AltaInteresado(ISistema*);
void cu_ObtenerReporteInmobiliarias(ISistema*);
void cu_CerrarSesion(ISistema*);
// *********************************

// ****** CU de Interesado ******
// cu_IniciarSesion()
// cu_CerrarSesion()
void cu_ConsultarPropiedad(ISistema*);
void cu_EnviarMensajeInteresado(ISistema*);
// ******************************

// ****** CU de Inmobiliaria ******
// cu_IniciarSesion()
// cu_CerrarSesion()
void cu_AltaEdificio(ISistema*);
void cu_AltaPropiedad(ISistema*);
// cu_ConsultarPropiedad()
void cu_ModificarPropiedad(ISistema*);
void cu_EliminarPropiedad(ISistema*);
void cu_EnviarMensajeInmobiliaria(ISistema*);
// *********************************

int main() {
  // Crea el sistema
  ISistema* sistema = Sistema::getInstancia();
  
  // Muestra la pantalla de inicio que lleva al menu
  // En caso de que el usuario cierre sesión: se vuelve a la pantalla de inicio
  do {
    pantallaBienvenida(sistema);

    if (sistema->isLogueado()) {
      menu(sistema);
    } else {
      break;
    }
  } while (true);

  delete sistema;
  return 0;
}

void mostrarCredenciales(ISistema* sistema) {
  cout << "Usuario: " << sistema->getUsuarioActual()->getEmail() << " | " << "Pass: " << sistema->getUsuarioActual()->getContrasenia() << endl;
  cout << "Tipo: " << sistema->getUsuarioActual()->getTipoUsuario() << endl << endl;
}

void mostrarError(char* mensajeError) {
  if (mensajeError != "") {
    cout << "ERROR: " << mensajeError << endl;
    mensajeError = "";
  }
}

void limpiarPantalla() {
  system("clear");
}

void pantallaBienvenida(ISistema* sistema) {
  char* mensajeError = "";
  int opcion;
  do {
    limpiarPantalla();
    if (mensajeError != "") {
      cout << mensajeError << endl;
      mensajeError = "";
    }
    cout << "Bienvenido al sistema \nSeleccione una opcion \n\n 1.Loguearse \n 2.Salir del programa\n\n";
    cin >> opcion;
    switch (opcion) {
      case 1:
        try {
          cu_IniciarSesion(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 2:
        cout << "Saliendo del programa...";
        break;
      default:
        cout << "Opcion invalida" << endl;
        break;
    }
  } while (!sistema->isLogueado() && opcion != 2);
}

void mostrarListadoDepartamentos(ISistema* sistema) {
  limpiarPantalla();
  cout << "Seleccione un departamento: \n";
  try {
    ICollection* departamentos = sistema->listarDepartamentos();
    IIterator* it = departamentos->getIterator();
    while (it->hasCurrent()) {
      DtDepartamento* depto = dynamic_cast<DtDepartamento*>(it->getCurrent());
      cout << "Departamento: " << depto->getCodigo() << " | " << depto->getNombre() << endl;
      it->next();
    }
  } catch (const char* e) {
    throw e;
  }
}

void mostrarListadoZonas(ISistema* sistema) {
  limpiarPantalla();
  cout << "Seleccione una zona: \n";
  try {
    ICollection* zonas = sistema->listarZonas();
    IIterator* it = zonas->getIterator();
    while (it->hasCurrent()) {
      DtZona* zona = dynamic_cast<DtZona*>(it->getCurrent());
      cout << "Zona: " << zona->getCodigo() << " | " << zona->getNombre() << endl;
      it->next();
    }
  } catch (const char* e) {
    throw e;
  }
}

void mostrarListadoPropiedades(ISistema* sistema) {
  limpiarPantalla();
  cout << "Seleccione una propiedad: \n";
  try
  {
    ICollection* propiedades = sistema->listarPropiedades();
    IIterator* it = propiedades->getIterator();
    while (it->hasCurrent()) {
    DtInfo * propiedad = dynamic_cast<DtInfo*>(it->getCurrent());
    cout << "Propiedad: " << propiedad->getCodigo() << " | " << propiedad->getTipo() << " | " << propiedad->getDireccion().getCalle() << " " << propiedad->getDireccion().getNumero() << " " << propiedad->getDireccion().getCiudad() << endl;
    it->next();
  }
  } catch (const char* e) {
    throw e;
  }
}

void mostrarDetallesPropiedad(DtInfo* prop) {
  limpiarPantalla();
  cout << "Detalles de la propiedad: \n";
  cout << "Codigo: " << prop->getCodigo() << endl;
  if (prop->getCantMensajes() != -1)
    cout << "Cantidad de mensajes: " << prop->getCantMensajes() << endl;
  if (prop->getTipo() != "")
    cout << "Tipo: " << prop->getTipo() << endl;
  cout << "Direccion: " << prop->getDireccion().getCalle() << " " << prop->getDireccion().getNumero() << " " << prop->getDireccion().getCiudad() << endl;
  cout << "Pulse cualquier tecla para continuar..." << endl;
  getchar();
}

void menuInteresado(ISistema* sistema){
  char* mensajeError = "";
  int opcion;
  do {
    limpiarPantalla();
    mostrarError(mensajeError);
    mostrarCredenciales(sistema);
    cout << "Seleccione una opcion\n\n 1.Consultar Propiedad\n 2.Enviar Mensaje\n 3.Cerrar Sesion\n" << endl;
    cin >> opcion;
    switch (opcion) {
      case 1:
        try {
          cout << "consultarPropiedad" << endl;
          //consultarPropiedad(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 2:
        try {
          cout << "consultarPropiedad" << endl;
          //enviarMensaje(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 3:
        try {
          cu_CerrarSesion(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      default:
        cout << "Opcion invalida" << endl;
        break;
    }
  } while (sistema->isLogueado());
}

void menuAdmin(ISistema* sistema){
  char* mensajeError = "";
  int opcion;
  do {
    limpiarPantalla();
    mostrarError(mensajeError);
    mostrarCredenciales(sistema);

    cout << "Seleccione una opcion\n\n 1.Alta Inmobiliaria\n 2.Alta Interesado\n 3.Obtener Reporte de Inmobiliarias\n 4.Cerrar Sesion\n" << endl;
    cin >> opcion;
    switch (opcion) {
      case 1:
        try {
          cu_AltaInmobiliaria(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 2:
        try {
          cu_AltaInteresado(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 3:
        try {
          cu_ObtenerReporteInmobiliarias(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 4:
        try {
          cu_CerrarSesion(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      default:
        cout << "Opcion invalida" << endl;
        break;
    }
  } while (sistema->isLogueado());
  
}

void menuInmobiliaria(ISistema* sistema){
  char* mensajeError = "";
  int opcion;
  do {
    limpiarPantalla();
    mostrarError(mensajeError);
    mostrarCredenciales(sistema);

    cout << "Seleccione una opcion\n\n 1.Alta Edificio\n 2.Alta Propiedad\n 3.Consultar Propiedad\n 4.Modificar Propiedad\n 5.Enviar Mensaje\n 6.Eliminar Propiedad\n 7.Cerrar Sesion" << endl;
    cin >> opcion;
    switch (opcion) {
      case 1:
        try {
          cout << "Está comentado... pelotudo .o." << endl;
          getchar();
          // cu_AltaPropiedad(sistema); 
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 2:
        try {
          //cu_ConsultarPropiedad(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 3:
        try {
          // cu_ModificarPropiedad(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 4:
        try {
          // cu_EnviarMensajeInmobiliaria(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 5:
        try {
          // cu_EliminarPropiedad(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 6:
        try {
          cu_CerrarSesion(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      default:
        cout << "Opcion invalida" << endl;
        break;
    }
  } while (sistema->isLogueado());
  
}

void menu(ISistema* sistema) {
  limpiarPantalla();
  string tipo = sistema->getUsuarioActual()->getTipoUsuario();
  if (tipo == "Interesado") {
    menuInteresado(sistema);
  } else if (tipo == "Inmobiliaria") {
    menuInmobiliaria(sistema);
  } else if (tipo == "Administrador") {
    menuAdmin(sistema);
  } else {
    sistema->deseleccionarUsuarioActual();
    cout << "Tipo de usuario no reconocido" << endl;
  }
}

void cu_IniciarSesion(ISistema* sistema) {
  limpiarPantalla();
  getchar();
  string email;
  string password;
  cout << "Ingrese su email: ";
  getline(cin, email);
  cout << "Ingrese su contrasenia: ";
  getline(cin, password);
  try {
    sistema->iniciarSesion(email, password);
  } catch (const char* e) {
    throw e;
  }
}

void cu_CerrarSesion(ISistema* sistema) {
  getchar();
  sistema->cerrarSesion();
}

void cu_AltaInmobiliaria(ISistema* sistema){
  limpiarPantalla();
  getchar();
  try {
    string email;
    string password;
    string calle;
    string ciudad;
    string numero;

    cout << "Dando de alta un usuario Inmobiliaria...\n\nIngresar Email: ";
    getline(cin, email);
    cout << "\nIngresar Password: ";
    getline(cin, password);
    cout << "\nIngresar Direccion (calle): ";
    getline(cin, calle);
    cout << "\nIngresar Direccion (ciudad): ";
    getline(cin, ciudad);
    cout << "\nIngresar Direccion (numero): ";
    getline(cin, numero);
    DtDireccion direccion = DtDireccion(calle, ciudad, stoi(numero));

    sistema->darDeAltaInmobiliaria(email, password, direccion);
    limpiarPantalla();
    cout << "Usuario Inmobiliaria creado con exito\n\nEmail: " << email << "\nContrasenia: " << password << "\nDireccion: \n -Calle: " << calle << "\n -Ciudad: " << ciudad << "\n -Numero: " << numero << endl;
    cout << "\nPulse cualquier tecla para continuar..." << endl;
    getchar();
  } catch (const char* e) {
    throw e;
  }
}

void cu_AltaInteresado(ISistema* sistema){
  limpiarPantalla();
  getchar();
  try {
    string email;
    string password;
    string nombre;
    string apellido;
    string dia;
    string mes;
    string anio;

    cout << "Dando de alta un usuario Interesado...\n\nIngresar Email: ";
    getline(cin, email);
    cout << "\nIngresar Password: ";
    getline(cin, password);
    cout << "\nIngresar Nombre: ";
    getline(cin, nombre);
    cout << "\nIngresar Apellido: ";
    getline(cin, apellido);
    cout << "\nIngresar Fecha (dia): ";
    getline(cin, dia);
    cout << "\nIngresar Fecha (mes): ";
    getline(cin, mes);
    cout << "\nIngresar Fecha (anio): ";
    getline(cin, anio);
    DtFecha edad = DtFecha(stoi(dia), stoi(mes), stoi(anio));

    sistema->darDeAltaInteresado(email, password, nombre, apellido, edad);
    cout << "Usuario Interesado creado con exito\n\nEmail: " << email << "\nContrasenia: " << password << "\nNombre: " << nombre << "\nApellido: " << apellido << "\nFecha de nacimiento: " << dia << "/" << mes << "/" << anio << endl;
    cout << "\nPulse cualquier tecla para continuar..." << endl;
    getchar();
  } catch (const char* e) {
    throw e;
  }
}

void cu_ObtenerReporteInmobiliarias(ISistema* sistema){
  limpiarPantalla();
  getchar();
  try {
    ICollection* inmos = sistema->listarInmobiliarias();
    IIterator* it = sistema->listarInmobiliarias()->getIterator();
    while (it->hasCurrent()) {
      DtInmobiliaria* inmo = dynamic_cast<DtInmobiliaria*>(it->getCurrent());
      cout << "Inmobiliaria: " << inmo->getEmail() << " | " << inmo->getDireccion().getCalle() << " " << inmo->getDireccion().getNumero() << " " << inmo->getDireccion().getCiudad() << endl;
      it->next();
    }
    delete it;
    delete inmos;
    cout << "\nPulse cualquier tecla para continuar..." << endl;
    getchar();
  } catch (const char* e) {
    throw e;
  }
}

void cu_ConsultarPropiedad(ISistema* sistema){ // return DtInfo de propiedad
  limpiarPantalla();
  getchar();
  string codigo;
  string codigoZona;
  
  try {
    mostrarListadoDepartamentos(sistema);
    getline(cin, codigo);
    sistema->seleccionarDepartamento(codigo[0]);
    mostrarListadoZonas(sistema);
    getline(cin, codigoZona);
    sistema->seleccionarZona(stoi(codigoZona));
    mostrarListadoPropiedades(sistema);
    getline(cin, codigo);
    DtInfo* propiedad = sistema->detallesPropiedad(stoi(codigo));
    mostrarDetallesPropiedad(propiedad);
    delete propiedad;
  } // Si algo falla, se deselecciona todo. 
  catch (const char* e) {
    sistema->deseleccionarTodo(false);
    throw e;
  }
  
}

void cu_EnviarMensajeInteresado(ISistema* sistema) {
  limpiarPantalla();
  getchar();
  string codigo;
  string codigoZona;
  string texto;
  
  try {
    // Lista los departamentos y selecciona según input del usuario
    mostrarListadoDepartamentos(sistema);
    getline(cin, codigo);
    sistema->seleccionarDepartamento(codigo[0]);

    // Lista las zonas del departamento seleccionado y selecciona una según input del usuario.
    mostrarListadoZonas(sistema);
    getline(cin, codigoZona);
    sistema->seleccionarZona(stoi(codigoZona));

    // Lista las propiedades de la zona seleccionada y selecciona una según input del usuario
    mostrarListadoPropiedades(sistema);
    getline(cin, codigo);
    sistema->seleccionarPropiedad(stoi(codigo));

    
    // Se fija si existe el chat, si no existe entonces lo crea.
    sistema->seleccionarChat();
    if (sistema->isChatSeleccionado()) {
      sistema->addChat(sistema->getUsuarioActual());
      sistema->seleccionarChat();
    }

    // Muestra los detalles de la propiedad seleccionada
    ICollection* mensajesConLaPropiedad = sistema->getUltimosMensajesUsuarioActualPropiedadActual();
    // TODO Iterador y mostrar los mensajes


    cout << "Escriba un mensaje para la propiedad: \n";
    getline(cin, texto);
    
    DtFecha fecha;
    DtHora hora;
    DtMensaje mensaje = DtMensaje(fecha,hora,texto,sistema->getEmailUsuarioActual());
    sistema->guardarMensaje(mensaje);
    
  } // Si algo falla, se deselecciona todo. 
  catch (const char* e) {
    sistema->deseleccionarTodo(false);
    throw e;
  }
}

void cu_EnviarMensajeInmobiliaria(ISistema* sistema){
    sistema->listarConversaciones();
    cout << "Seleccione una conversacion: ";
    sistema->seleccionarChat();

    if (sistema->isChatSeleccionado()) {
      sistema->addChat(sistema->getUsuarioActual());
      sistema->seleccionarChat();
    }

    IIterator * it = sistema->getMensajes()->getIterator();
    int x = 5;
    while (it->hasCurrent() && x-- > 0) {
      DtMensaje* mensaje = dynamic_cast<DtMensaje*>(it->getCurrent());
      cout << mensaje->getEmisor() << " | " << mensaje->getFecha().getDia() << " - " << mensaje->getFecha().getMes() << " - " << mensaje->getFecha().getAnio() << endl << " | " << mensaje->getHora().getHora() << " : " << mensaje->getHora().getMinuto() << " | " << mensaje->getTexto() << endl;
      it->next();
    }
}

void cu_AltaEdificio(ISistema* sistema){
    limpiarPantalla();
    getchar();
    string nombre;
    string cantPisos;
    string gastosComunes;
    try {
      cout << "Ingrese el nombre del edificio: \n" << endl;
      getline(cin, nombre);
      cout << "Ingrese la cantidad de pisos: \n" << endl;
      getline(cin, cantPisos);
      cout << "Ingrese los gastos comunes: \n" << endl;
      getline(cin, gastosComunes);
      DtEdificio edificio = DtEdificio(nombre, stoi(cantPisos), stof(gastosComunes));
      sistema->darDeAltaEdificio(edificio);
      cout << "Edificio creado con exito\n\nNombre: " << nombre << "\nCantidad de pisos: " << cantPisos << "\nGastos comunes: " << gastosComunes << endl;
      cout << "\nPulse cualquier tecla para continuar..." << endl;
      getchar();
    } // Si algo falla, se deselecciona todo. 
    catch (const char* e){
      sistema->deseleccionarTodo(true);
    throw e;
  }
}

void cu_AltaPropiedad(ISistema* sistema){
  limpiarPantalla();
  getchar();
  string cantAmbientes;
  string codigo;
  string codigoZona;
  string tipo;
  int opcionAP;
  try{
    mostrarListadoDepartamentos(sistema);
    getline(cin, codigo);
    sistema->seleccionarDepartamento(codigo[0]);

    limpiarPantalla();
    mostrarListadoZonas(sistema);
    getline(cin, codigoZona);
    sistema->seleccionarZona(stoi(codigoZona));

    do{
      limpiarPantalla();
      cout << "Ingrese el tipo de propiedad: \n 1.Apartamento\n 2.Casa\n" << endl;
      cin >> opcionAP;
      switch (opcionAP)
      {
      case 1:
        tipo = "Apartamento";
        break;
      case 2:
        tipo = "Casa";
        break;
      default:
        cout << "Debes elegir una opcion valida...";
        getchar();
        break;
      }
    }
    while(opcionAP != 1 && opcionAP != 2);

    

  }
  catch (const char* e){
    sistema->deseleccionarTodo(true);
    throw e;
  }
}