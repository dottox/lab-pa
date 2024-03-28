#ifndef DATATYPES_H
#define DATATYPES_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Fecha {
  int dia;
  int mes;
  int anio;
};

struct Direccion {
  string calle;
  int numero;
  string ciudad;
};
 
struct DtEmpleado {
  string ci;
  string nombre;
  string apellido;
  Direccion direccion;
  float sueldoLiquido;
};

struct DtEmpresa{
  string id;
  Direccion direccion;
};

struct DtNacional : public DtEmpresa {
  string rut;
};

struct DtExtranjera : public DtEmpresa {
  string nombreFantasia;
};

#endif 