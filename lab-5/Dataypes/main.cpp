// TESTEOS

#include <iostream>
using namespace std;

#include "Fecha.cpp"
#include "Hora.cpp"
#include "Direccion.cpp"

int main() {
  Fecha f(1, 2, 3);
  Hora h(4, 5);
  Direccion d("Calle", "Ciudad", 6);
  
  cout << "Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
  cout << "Hora: " << h.getHora() << ":" << h.getMinuto() << endl;
  cout << "Direccion: " << d.getCalle() << " " << d.getNro() << ", " << d.getCiudad() << endl;
}