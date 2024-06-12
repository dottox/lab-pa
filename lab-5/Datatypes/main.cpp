// TESTEOS

#include <iostream>
using namespace std;

#include "DtDatosApartamento.h"
#include "DtDatosCasa.h"
#include "DtDepartamento.h"
#include "DtDireccion.h"
#include "DtEdificio.h"
#include "DtFecha.h"
#include "DtHora.h"
#include "DtInfoApartamento.h"
#include "DtInfoCasa.h"
#include "DtInfoCasa.h"
#include "DtMensaje.h"
#include "DtZona.h"
#include "../Clases/Mensaje.h"


int main() {
  DtFecha f(1, 2, 3);
  DtHora h(4, 5);
  DtDireccion d("Calle", "Ciudad", 6);
  DtDepartamento dep('A', "Departamento");
  DtZona z(7, "Zona");
  DtEdificio e("Hola", 24, 23);
  DtMensaje m(f, h, "Texto");
  DtInfoApartamento ia(8, 9, 10, 11, true, d, 14, 15, "ala", 18);
  DtInfoCasa ic(8, 9, 10, 11, true, d, 15, 16, "ala", 18, 19);
  DtDatosApartamento da(8, 9, 10, 11, true, d, 14, 15, "ala", 18);
  DtDatosCasa dc(8, 9, 10, 11, true, d, 15, 16, "ala", 18, 19);

  Mensaje* m2 = new Mensaje(f, h, "Banana");

  // Print m2 attribs
  cout << "Texto: " << m2->getMensaje().getTexto() << endl;
  cout << "AFecha: " << m2->getMensaje().getFecha().getDia() << "/" << m2->getMensaje().getFecha().getMes() << "/" << m2->getMensaje().getFecha().getAnio() << endl;
  
  cout << "Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
  cout << "Hora: " << h.getHora() << ":" << h.getMinuto() << endl;
  cout << "Direccion: " << d.getCalle() << " " << d.getNro() << ", " << d.getCiudad() << endl;
  cout << "Departamento: " << dep.getCodigo() << " " << dep.getNombre() << endl;
  cout << "Zona: " << z.getCodigo() << " " << z.getNombre() << endl;
  cout << "Edificio: " << e.getNombre() << " " << e.getCantPisos() << " " << e.getGastosComunes() << endl;
  cout << "Mensaje: " << m.getFecha().getDia() << "/" << m.getFecha().getMes() << "/" << m.getFecha().getAnio() << " " << m.getHora().getHora() << ":" << m.getHora().getMinuto() << " " << m.getTexto() << endl;
  
  // DtInfoApartamento(int, int, int, int, bool, DtDireccion, float, float, string, float);
  // DtInfoCasa(int, int, int, int, bool, DtDireccion, float, float, string, float, float);
  // DtDatosApartamento(int, int, int, int, bool, DtDireccion, float, float, string, float);
  // DtDatosCasa(int, int, int, int, bool, DtDireccion, float, float, string, float, float);

  cout << "InfoApartamento: " << ia.getCodigo() << " " << ia.getCantAmbientes() << " " << ia.getCantDormitorios() << " " << ia.getCantBanios() << " " << ia.getGaraje() << " " << ia.getDireccion().getCalle() << " " << ia.getMtsCuadradosEdificados() << " " << ia.getMtsCuadradosTotales() << " " << ia.getTipo() << " " << ia.getPrecio() << endl;
  cout << "InfoCasa: " << ic.getCodigo() << " " << ic.getCantAmbientes() << " " << ic.getCantDormitorios() << " " << ic.getCantBanios() << " " << ic.getGaraje() << " " << ic.getDireccion().getCalle() << " " << ic.getMtsCuadradosEdificados() << " " << ic.getMtsCuadradosTotales() << " " << ic.getTipo() << " " << ic.getPrecio() << " " << ic.getMtsCuadradosVerdes() << endl;
  cout << "DatosApartamento: " << da.getCodigo() << " " << da.getCantAmbientes() << " " << da.getCantDormitorios() << " " << da.getCantBanios() << " " << da.getGaraje() << " " << da.getDireccion().getCalle() << " " << da.getMtsCuadradosEdificados() << " " << da.getMtsCuadradosTotales() << " " << da.getTipo() << " " << da.getPrecio() << endl;
  cout << "DatosCasa: " << dc.getCodigo() << " " << dc.getCantAmbientes() << " " << dc.getCantDormitorios() << " " << dc.getCantBanios() << " " << dc.getGaraje() << " " << dc.getDireccion().getCalle() << " " << dc.getMtsCuadradosEdificados() << " " << dc.getMtsCuadradosTotales() << " " << dc.getTipo() << " " << dc.getPrecio() << " " << dc.getMtsCuadradosVerdes() << endl;
}