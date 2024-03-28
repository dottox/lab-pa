#include "Empleado.h"

// void agregarEmpleado(string ci, string nombre, string  apellido, Direccion dir) Crea un nuevo empleado en el sistema. 
//En caso de ya existir, levanta la excepción std::invalid_argument
Empleado::Empleado(string ci, string nom, string apell, Direccion d)
{
  this->ci = ci;
  this->nombre = nom;
  this->apellido = apell;
  this->direccion = d;
}

void Empleado::setCi(string ci) { this->ci = ci; }

void Empleado::setNombre(string nom) { this->nombre = nom; }

void Empleado::setApellido(string apell) { this->apellido = apell; }

void Empleado::setDireccion(Direccion d) { this->direccion = d; }

string Empleado::getNombre() { return this->nombre; }

string Empleado::getApellido() { return this->apellido; }

string Empleado::getCi() { return this->ci; }

Direccion Empleado::getDireccion() { return this->direccion; }

Empleado::~Empleado() {}
