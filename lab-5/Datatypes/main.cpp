// TESTEOS

#include <iostream>
using namespace std;

// #include "DtDatosApartamento.h"
// #include "DtDatosCasa.h"
// #include "DtDepartamento.h"
// #include "DtDireccion.h"
// #include "DtEdificio.h"
// #include "DtFecha.h"
// #include "DtHora.h"
// #include "DtInfoApartamento.h"
// #include "DtInfoCasa.h"
// #include "DtInfoCasa.h"
// #include "DtMensaje.h"
// #include "DtZona.h"

#include "DtFecha.h"
#include "DtHora.h"
#include "DtDireccion.h"


int main() {
  DtFecha f(1, 2, 3);
  DtHora h(4, 5);
  DtDireccion d("Calle", "Ciudad", 6);
  
  cout << "Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
  cout << "Hora: " << h.getHora() << ":" << h.getMinuto() << endl;
  cout << "Direccion: " << d.getCalle() << " " << d.getNro() << ", " << d.getCiudad() << endl;
}