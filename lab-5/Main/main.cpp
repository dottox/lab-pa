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
void mostrarListadoEdificios(ISistema*);
void mostrarListadoConversaciones(ISistema*);
void mostrarListadoMensajes(IIterator*);
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
    mostrarError(mensajeError);
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
        cout << "Saliendo del programa..." << endl;
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
    ICollection* zonas = sistema->departamento__listarZonas();
    IIterator* it = zonas->getIterator();
    while (it->hasCurrent()) {
      DtZona* zona = dynamic_cast<DtZona*>(it->getCurrent());
      cout << "\nZona: " << zona->getCodigo() << " | " << zona->getNombre() << endl;
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
    ICollection* propiedades = sistema->zona__listarPropiedades();
    ICollection* propiedadesEdificio = sistema->edificio__listarPropiedades();

    IIterator* it = propiedades->getIterator();
    while (it->hasCurrent()) {
      DtInfo * propiedad = dynamic_cast<DtInfo*>(it->getCurrent());
      cout << "Casa: " << propiedad->getCodigo() << " | Tipo : " << propiedad->getTipo() << " | Direccion : " << propiedad->getDireccion().getCalle() << " " << propiedad->getDireccion().getNumero() << ", " << propiedad->getDireccion().getCiudad() << endl;
      it->next();
    }
    delete it;

    IIterator* it2 = propiedadesEdificio->getIterator();
    while (it2->hasCurrent()) {
      DtInfo * propiedad = dynamic_cast<DtInfo*>(it2->getCurrent());
      cout << "Apartamento: " << propiedad->getCodigo() << " | Tipo : " << propiedad->getTipo() << " | Direccion : " << propiedad->getDireccion().getCalle() << " " << propiedad->getDireccion().getNumero() << " " << propiedad->getDireccion().getCiudad() << endl;
      it2->next();
    }
    delete it2;
  } catch (const char* e) {
    throw e;
  }
}

void mostrarListadoEdificios(ISistema* sistema) {
  limpiarPantalla();
  cout << "Seleccione un edificio: \n";
  try {
    ICollection* edificios = sistema->zona__listarEdificios();
    IIterator* it = edificios->getIterator();
    while (it->hasCurrent()) {
      DtEdificio* edificio = dynamic_cast<DtEdificio*>(it->getCurrent());
      cout << "-- Nombre Edificio: " << edificio->getNombre() << endl;
      cout << "Cant Pisos: " <<  edificio->getCantPisos() << endl; 
      cout << "Gastos comunes: " << edificio->getGastosComunes() << endl;
      it->next();
    }
  } catch (const char* e) {
    throw e;
  }
}

void mostrarListadoConversaciones(ISistema* sistema) {
  limpiarPantalla();
  cout << "Seleccione una conversacion: \n";
  try {
    ICollection* conversaciones = sistema->propiedad__listarConversaciones();
    IIterator* it = conversaciones->getIterator();
    while (it->hasCurrent()) {
      DtChat* chat = dynamic_cast<DtChat*>(it->getCurrent());
      cout << "\nPropiedad: " << chat->getPropiedad() << endl;
      cout << "Interesado: " << chat->getInteresado() << endl;
      cout << "Cantidad de mensajes: " << chat->getCantMensajes() << endl;
      it->next();
    }
  } catch (const char* e) {
    throw e;
  }
}

void mostrarListadoMensajes(IIterator* it) {
  while (it->hasCurrent()) {
    DtMensaje* mensaje = dynamic_cast<DtMensaje*>(it->getCurrent());
    cout << mensaje->getEmisor() << " | " << mensaje->getFecha().getDia() << " - " << mensaje->getFecha().getMes() << " - " << mensaje->getFecha().getAnio() << endl << " | " << mensaje->getHora().getHora() << " : " << mensaje->getHora().getMinuto() << " | " << mensaje->getTexto() << endl;
    it->next();
  }
  delete it;
}

void mostrarDetallesPropiedad(DtDatos prop, string inmobiliaria = "") {
  limpiarPantalla();
  cout << "Detalles de la propiedad: \n";
  cout << "Inmobiliaria: " << inmobiliaria << endl;
  cout << "Codigo: " << prop.getCodigo() << endl;
  cout << "Tipo: " << prop.getTipo() << endl;
  cout << "Direccion: " << prop.getDireccion().getCalle() << " " << prop.getDireccion().getNumero() << " " << prop.getDireccion().getCiudad() << endl;
  cout << "Metros cuadrados edificados: " << prop.getMtsCuadradosEdificados() << endl;
  cout << "Metros cuadrados totales: " << prop.getMtsCuadradosTotales() << endl;
  cout << "Precio: " << prop.getPrecio() << endl;
  cout << "Garaje: " << prop.getGaraje() << endl;
  cout << "Cantidad de ambientes: " << prop.getCantAmbientes() << endl;
  cout << "Cantidad de dormitorios: " << prop.getCantDormitorios() << endl;
  cout << "Cantidad de baños: " << prop.getCantBanios() << endl;
  
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
          cu_ConsultarPropiedad(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 2:
        try {
          cout << "consultarPropiedad" << endl;
          cu_EnviarMensajeInteresado(sistema);
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

    cout << "Seleccione una opcion\n\n 1.Alta Propiedad\n 2.Consultar Propiedad\n 3.Modificar Propiedad\n 4.Enviar Mensaje\n 5.Eliminar Propiedad\n 6.Cerrar Sesion" << endl;
    cin >> opcion;
    switch (opcion) {
      case 1:
        try {
          cu_AltaPropiedad(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 2:
        try {
          cu_ConsultarPropiedad(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 3:
        try {
          cu_ModificarPropiedad(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 4:
        try {
          cu_EnviarMensajeInmobiliaria(sistema);
        } catch (const char* e) {
          mensajeError = (char*)e;
        }
        break;
      case 5:
        try {
          cu_EliminarPropiedad(sistema);
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
    sistema->listarReporteInmobiliarias();
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
    sistema->departamento__seleccionarZona(stoi(codigoZona));
    mostrarListadoPropiedades(sistema);
    getline(cin, codigo);
    
    bool flag = false;
    try {
      sistema->zona__seleccionarPropiedad(stoi(codigo));
    } catch (const char* e) { 
      flag = true;
    }

    DtDatos propiedadDatos = sistema->zona__edificio__getDatosPropiedadSinActual(stoi(codigo));
    if (flag)
      mostrarDetallesPropiedad(propiedadDatos);
    else
      mostrarDetallesPropiedad(propiedadDatos, sistema->propiedad__getNombreInmobiliaria());
  } // Si algo falla, se deselecciona todo. 
  catch (const char* e) {
    sistema->aux__deseleccionarTodo(false);
    throw e;
  }
  sistema->aux__deseleccionarTodo(false);
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
    sistema->departamento__seleccionarZona(stoi(codigoZona));

    // Lista las propiedades de la zona seleccionada y selecciona una según input del usuario
    mostrarListadoPropiedades(sistema);
    getline(cin, codigo);
    sistema->zona__seleccionarPropiedad(stoi(codigo));

    
    // Se fija si existe el chat, si no existe entonces lo crea.
    sistema->propiedad__seleccionarChat();
    if (!sistema->propiedad__isChatSeleccionado()) {
      sistema->propiedad__addChat(sistema->getUsuarioActual());
      sistema->propiedad__seleccionarChat();
    }

    // Muestra los detalles de la propiedad seleccionada
    ICollection* mensajesConLaPropiedad = sistema->chat__getUltimosMensajesUsuarioActualPropiedadActual();
    
    IIterator* it = mensajesConLaPropiedad->getIterator();
    mostrarListadoMensajes(it);


    cout << "\nEscriba un mensaje para la propiedad: \n";
    getline(cin, texto);
    
    DtFecha fecha;
    DtHora hora;
    DtMensaje mensaje = DtMensaje(fecha,hora,texto,sistema->getEmailUsuarioActual());
    sistema->chat__guardarMensaje(mensaje);
    
  } // Si algo falla, se deselecciona todo. 
  catch (const char* e) {
    sistema->aux__deseleccionarTodo(false);
    throw e;
  }

  sistema->aux__deseleccionarTodo(false);
}

void cu_EnviarMensajeInmobiliaria(ISistema* sistema){
  limpiarPantalla();
  getchar();
  string codigo, email;
  
  try {
    mostrarListadoConversaciones(sistema);
    cout << "Escriba el código de la propiedad deseada: ";
    getline(cin, codigo);
    cout << "Escriba el mail de la persona con la que quiere hablar: ";
    getline(cin, email);
    sistema->propiedad__seleccionarChatInmobiliaria(email, stoi(codigo));

    if (!sistema->inmobiliaria__isChatSeleccionado()) {
      throw "No se pudo seleccionar el chat";
    }

    IIterator* it = sistema->inmobiliaria__getMensajesChatActual()->getIterator();
    mostrarListadoMensajes(it);

    string reply;
    cout << "\n¿Desea enviar un mensaje? (y/n): ";
    getline(cin, reply);

    if (reply == "y" || reply == "Y") {
      cout << "\nEscriba el mensaje: \n";
      string texto;
      getline(cin, texto);
      DtFecha fecha;
      DtHora hora;
      DtMensaje mensaje = DtMensaje(fecha, hora, texto, sistema->getEmailUsuarioActual());
      sistema->inmobiliaria__addMensajeChatActual(mensaje);
    }
  } catch (const char* e) {
    sistema->aux__deseleccionarTodo(false);
    throw e;
  }
  sistema->aux__deseleccionarTodo(false);

}

void cu_AltaEdificio(ISistema* sistema){
  limpiarPantalla();
  string nombre;
  string cantPisos;
  string gastosComunes;
  try {
    cout << "\nIngrese el nombre del edificio: ";
    getline(cin, nombre);
    cout << "\nIngrese la cantidad de pisos: ";
    getline(cin, cantPisos);
    cout << "\nIngrese los gastos comunes: ";
    getline(cin, gastosComunes);
    DtEdificio edificio = DtEdificio(nombre, stoi(cantPisos), stof(gastosComunes));
    sistema->zona__darDeAltaEdificio(edificio);
    cout << "Edificio creado con exito\n\nNombre: " << nombre << "\nCantidad de pisos: " << cantPisos << "\nGastos comunes: " << gastosComunes << endl;
    cout << "\nPulse cualquier tecla para continuar..." << endl;
    getchar();
  } // Si algo falla, se deselecciona todo. 
  catch (const char* e){
    throw e;
  }
}

void cu_AltaPropiedad(ISistema* sistema){
  limpiarPantalla();
  getchar();
  string cantAmbientes, cantDormitorios, cantBanios, garajeReply, calle, ciudad, numero, mtsCuadradosEdificados, mtsCuadradosTotales, precio, tipo, mtsCuadradosVerdes;  
  bool garaje = false;
  int codigo;
  string codigoDep,codigoZona,nombre,opcionEd;

  
  string opcionAP;
  try{
    mostrarListadoDepartamentos(sistema);
    getline(cin, codigoDep);
    string cantAmbientes, cantDormitorios, cantBanios, garajeReply, calle, ciudad, numero, mtsCuadradosEdificados, mtsCuadradosTotales, precio, tipo, mtsCuadradosVerdes;  
    sistema->seleccionarDepartamento(codigoDep[0]);

    limpiarPantalla();
    
    mostrarListadoZonas(sistema);
    getline(cin, codigoZona);
    sistema->departamento__seleccionarZona(stoi(codigoZona));


    do{
      limpiarPantalla();
      cout << "Ingrese el tipo de propiedad: \n 1.Apartamento\n 2.Casa\n" << endl;
      getline(cin, opcionAP);
      if (opcionAP == "1"){
        limpiarPantalla();
        
        // Muestra los edificios y deja al usuario seleccionar uno.
        mostrarListadoEdificios(sistema);
        cout << endl << "Seleccione el nombre del edificio, en caso de querer agregar uno nuevo, escriba: crear" << endl;
        cout << "Respuesta: ";
        getline(cin, opcionEd);
        
        if(opcionEd == "crear" || opcionEd == "Crear"){
          cu_AltaEdificio(sistema);
        } else {
          sistema->zona__seleccionarEdificio(opcionEd);
        }
        

        //Ingresa los datos del apartamento
        limpiarPantalla();
        cout << "Ingrese la cantidad de ambientes: ";
        getline(cin, cantAmbientes);
        limpiarPantalla();
        cout << "\nIngrese la cantidad de dormitorios: ";
        getline(cin, cantDormitorios);
        limpiarPantalla();
        cout << "\nIngrese la cantidad de baños: ";
        getline(cin, cantBanios);
        limpiarPantalla();
        cout << "\nIngrese si tiene garaje (y/n): ";
        getline(cin, garajeReply);
        if (garajeReply == "y" || garajeReply == "Y")
          garaje = true;
        limpiarPantalla();
        cout << "\nIngresar Direccion (calle): ";
        getline(cin, calle);
        limpiarPantalla();
        cout << "\nIngresar Direccion (ciudad): ";
        getline(cin, ciudad);
        limpiarPantalla();
        cout << "\nIngresar Direccion (numero): ";
        getline(cin, numero);
        limpiarPantalla();
        cout << "\nIngrese los metros cuadrados edificados: ";
        getline(cin, mtsCuadradosEdificados);
        limpiarPantalla();
        cout << "\nIngrese los metros cuadrados totales: ";
        getline(cin, mtsCuadradosTotales);
        limpiarPantalla();
        cout << "\nIngrese el tipo (alquiler/venta): ";
        getline(cin, tipo);
        limpiarPantalla();
        cout << "\nIngrese el precio: ";
        getline(cin, precio);
        
        codigo = sistema->generarCodigoPropiedad(); // Se obtiene un nuevo codigo incremental para la propiedad

        DtDireccion direccion = DtDireccion(calle, ciudad, stoi(numero));
        DtDatosApartamento datos = DtDatosApartamento(codigo, stoi(cantAmbientes),  stoi(cantDormitorios), stoi(cantBanios), garaje, direccion, stof(mtsCuadradosEdificados), stof(mtsCuadradosTotales), tipo, stof(precio));
        sistema->edificio__datosApt(datos);
        sistema->zona__edificio__darAlta();
        limpiarPantalla();
        cout << "Casa creada con exito:\n\nCodigo: " << codigo << "\nCantidad de ambientes: " << cantAmbientes << "\nCantidad de dormitorios: " << cantDormitorios << "\nCantidad de baños: " << cantBanios << "\nGaraje: " << garaje << "\nDireccion: " << calle << " " << numero << " " << ciudad << "\nMetros cuadrados edificados: " << mtsCuadradosEdificados << "\nMetros cuadrados totales: " << mtsCuadradosTotales << "\nTipo: " << tipo << "\nPrecio: " << precio << endl;
        cout << "\nPulse cualquier tecla para continuar..." << endl;
        getchar();
      }
      else if (opcionAP == "2"){
        limpiarPantalla();

        //Ingresa los datos del apartamento
        cout << "Ingrese la cantidad de ambientes: ";
        getline(cin, cantAmbientes);
        limpiarPantalla();
        cout << "\nIngrese la cantidad de dormitorios: ";
        getline(cin, cantDormitorios);
        limpiarPantalla();
        cout << "\nIngrese la cantidad de baños: ";
        getline(cin, cantBanios);
        limpiarPantalla();
        cout << "\nIngrese si tiene garaje: (y/n) ";
        getline(cin, garajeReply);
        if (garajeReply == "y" || garajeReply == "Y")
          garaje = true;
        limpiarPantalla();
        cout << "\nIngresar Direccion (calle): ";
        getline(cin, calle);
        limpiarPantalla();
        cout << "\nIngresar Direccion (ciudad): ";
        getline(cin, ciudad);
        limpiarPantalla();
        cout << "\nIngresar Direccion (numero): ";
        getline(cin, numero);
        limpiarPantalla();
        cout << "\nIngrese los metros cuadrados edificados: ";
        getline(cin, mtsCuadradosEdificados);
        limpiarPantalla();
        cout << "\nIngrese los metros cuadrados totales: ";
        getline(cin, mtsCuadradosTotales);
        limpiarPantalla();
        cout << "\nIngrese los metros cuadrados verdes: ";
        getline(cin, mtsCuadradosVerdes);
        limpiarPantalla();
        cout << "\nIngrese el tipo (alquier/venta): ";
        getline(cin, tipo);
        limpiarPantalla();
        cout << "\nIngrese el precio: ";
        getline(cin, precio);
  
        codigo = sistema->generarCodigoPropiedad(); // Se obtiene un nuevo codigo incremental para la propiedad
        DtDireccion direccion = DtDireccion(calle, ciudad, stoi(numero));
        DtDatosCasa datos = DtDatosCasa(codigo, stoi(cantAmbientes), stoi(cantDormitorios), stoi(cantBanios), garaje, direccion, stof(mtsCuadradosEdificados), stof(mtsCuadradosTotales), tipo, stof(precio), stof(mtsCuadradosVerdes));
        sistema->zona__datosCasa(datos);
        sistema->zona__edificio__darAlta();
        limpiarPantalla();
        cout << "Casa creada con exito:\n\nCodigo: " << codigo << "\nCantidad de ambientes: " << cantAmbientes << "\nCantidad de dormitorios: " << cantDormitorios << "\nCantidad de baños: " << cantBanios << "\nGaraje: " << garaje << "\nDireccion: " << calle << " " << numero << " " << ciudad << "\nMetros cuadrados edificados: " << mtsCuadradosEdificados << "\nMetros cuadrados totales: " << mtsCuadradosTotales << "\nTipo: " << tipo << "\nPrecio: " << precio << "\nMetros cuadrados verdes: " << mtsCuadradosVerdes << endl;
        cout << "\nPulse cualquier tecla para continuar..." << endl;
        getchar();
      }
      else{
        cout << "Opcion invalida" << endl;
      }
    }
    while(opcionAP != "1" && opcionAP != "2");
    
  }
  catch (const char* e){
    sistema->aux__deseleccionarTodo(true);
    throw e;
  }

  sistema->aux__deseleccionarTodo(false);
}

void cu_ModificarPropiedad(ISistema* sistema){
  limpiarPantalla();
  getchar();
  string codigoDepartamento,codigoZona,codigo;
  string cantAmbientes, cantDormitorios, cantBanios, garajeReply, calle, ciudad, numero, mtsCuadradosEdificados, mtsCuadradosTotales, precio, tipo, mtsCuadradosVerdes; 
  string opcionAP, opcionEd; 
  bool garaje = false;
  try {
    do{
      limpiarPantalla();
      cout << "Ingrese el tipo de propiedad: \n 1.Apartamento\n 2.Casa\n" << endl;
      getline(cin, opcionAP);
      if (opcionAP == "1"){
        limpiarPantalla();
        
        // Muestra los edificios y deja al usuario seleccionar uno.
        mostrarListadoEdificios(sistema);
        cout << endl << "Seleccione el nombre del edificio" << endl;
        cout << "Respuesta: ";
        getline(cin, opcionEd);

        sistema->zona__seleccionarEdificio(opcionEd);

        //Ingresa los datos del apartamento
        cout << "Ingrese la cantidad de ambientes: ";
        getline(cin, cantAmbientes);
        cout << "\nIngrese la cantidad de dormitorios: ";
        getline(cin, cantDormitorios);
        cout << "\nIngrese la cantidad de baños: ";
        getline(cin, cantBanios);
        cout << "\nIngrese si tiene garaje (y/n): ";
        getline(cin, garajeReply);
        if (garajeReply == "y" || garajeReply == "Y")
          garaje = true;
        cout << "\nIngresar Direccion (calle): ";
        getline(cin, calle);
        cout << "\nIngresar Direccion (ciudad): ";
        getline(cin, ciudad);
        cout << "\nIngresar Direccion (numero): ";
        getline(cin, numero);
        cout << "\nIngrese los metros cuadrados edificados: ";
        getline(cin, mtsCuadradosEdificados);
        cout << "\nIngrese los metros cuadrados totales: ";
        getline(cin, mtsCuadradosTotales);
        cout << "\nIngrese el tipo (alquiler/venta): ";
        getline(cin, tipo);
        cout << "\nIngrese el precio: ";
        getline(cin, precio);
        
        
        DtDireccion direccion = DtDireccion(calle, ciudad, stoi(numero));
        DtDatosApartamento datos = DtDatosApartamento( stoi(cantAmbientes),  stoi(cantDormitorios), stoi(cantBanios), garaje, direccion, stof(mtsCuadradosEdificados), stof(mtsCuadradosTotales), tipo, stof(precio));
        sistema->edificio__modificarDatosApartamento(datos);
        cout << "Apartamento modificada con exito:\n\nnCantidad de ambientes: " << cantAmbientes << "\nCantidad de dormitorios: " << cantDormitorios << "\nCantidad de baños: " << cantBanios << "\nGaraje: " << garaje << "\nDireccion: " << calle << " " << numero << " " << ciudad << "\nMetros cuadrados edificados: " << mtsCuadradosEdificados << "\nMetros cuadrados totales: " << mtsCuadradosTotales << "\nTipo: " << tipo << "\nPrecio: " << precio << "\nMetros cuadrados verdes: " << endl;
        cout << "\nPulse cualquier tecla para continuar..." << endl;
        getchar();
      }
      else if (opcionAP == "2"){
        limpiarPantalla();

        //Ingresa los datos del apartamento
        cout << "Ingrese la cantidad de ambientes: ";
        getline(cin, cantAmbientes);
        cout << "\nIngrese la cantidad de dormitorios: ";
        getline(cin, cantDormitorios);
        cout << "\nIngrese la cantidad de baños: ";
        getline(cin, cantBanios);
        cout << "\nIngrese si tiene garaje: (y/n) ";
        getline(cin, garajeReply);
        if (garajeReply == "y" || garajeReply == "Y")
          garaje = true;
        cout << "\nIngresar Direccion (calle): ";
        getline(cin, calle);
        cout << "\nIngresar Direccion (ciudad): ";
        getline(cin, ciudad);
        cout << "\nIngresar Direccion (numero): ";
        getline(cin, numero);
        cout << "\nIngrese los metros cuadrados edificados: ";
        getline(cin, mtsCuadradosEdificados);
        cout << "\nIngrese los metros cuadrados totales: ";
        getline(cin, mtsCuadradosTotales);
        cout << "\nIngrese los metros cuadrados verdes: ";
        getline(cin, mtsCuadradosVerdes);
        cout << "\nIngrese el tipo: (alquier/venta)";
        getline(cin, tipo);
        cout << "\nIngrese el precio: ";
        getline(cin, precio);
  
        DtDireccion direccion = DtDireccion(calle, ciudad, stoi(numero));
        DtDatosCasa datos = DtDatosCasa(stoi(cantAmbientes), stoi(cantDormitorios), stoi(cantBanios), garaje, direccion, stof(mtsCuadradosEdificados), stof(mtsCuadradosTotales), tipo, stof(precio), stof(mtsCuadradosVerdes));
        sistema->zona__modificarDatosCasa(datos);
        cout << "Casa modificada con exito:\n\nCantidad de ambientes: " << cantAmbientes << "\nCantidad de dormitorios: " << cantDormitorios << "\nCantidad de baños: " << cantBanios << "\nGaraje: " << garaje << "\nDireccion: " << calle << " " << numero << " " << ciudad << "\nMetros cuadrados edificados: " << mtsCuadradosEdificados << "\nMetros cuadrados totales: " << mtsCuadradosTotales << "\nTipo: " << tipo << "\nPrecio: " << precio << "\nMetros cuadrados verdes: " << mtsCuadradosVerdes << endl;
        cout << "\nPulse cualquier tecla para continuar..." << endl;
        getchar();
      }
      else{
        cout << "Opcion invalida" << endl;
      }
    }
    while(opcionAP != "1" && opcionAP != "2");
  }
  catch (const char* e){
    sistema->aux__deseleccionarTodo(true);
    throw e;
  }
}

void cu_EliminarPropiedad(ISistema* sistema){
  limpiarPantalla();
  getchar();
  string codigo;
  try {
    cout << "Ingrese el codigo de la propiedad a eliminar: \n" << endl;
    getline(cin, codigo);
    sistema->zona__eliminarPropiedad(stoi(codigo));
  } 
  catch (const char* e) {
    sistema->aux__deseleccionarTodo(false);
    throw e;
  }
}