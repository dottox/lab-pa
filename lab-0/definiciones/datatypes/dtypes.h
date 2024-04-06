#ifndef DATATYPES_H
#define DATATYPES_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
using namespace std;

struct Fecha{
  public:
    Fecha(int dia = 0, int mes = 0, int anio = 0){
      this->dia = dia;
      this->mes = mes;
      this->anio = anio;
    }

    int getDia() { return this->dia; }

    int getMes() { return this->mes; }

    int getAnio() { return this->anio; }

  private:
    int dia;
    int mes;
    int anio;
};

struct Direccion{
public:
  Direccion(string calle = "", int numero = 0, string ciudad = "") {
    this->calle = calle;
    this->numero = numero;
    this->ciudad = ciudad;
  }

  string getCalle() { return this->calle; }

  int getNumero() { return this->numero; }

  string getCiudad() { return this->ciudad; }

private:
  string calle;
  int numero;
  string ciudad;
};

struct DtEmpleado{
public:
  DtEmpleado(string ci, string nom, string apell, Direccion d)
  {
    this->ci = ci;
    this->nombre = nom;
    this->apellido = apell;
    this->direccion = d;
  }

  string getCi() { return this->ci; }

  string getNombre() { return this->nombre; }

  string getApellido() { return this->apellido; }

  Direccion getDireccion() { return this->direccion; }

private:
  string ci;
  string nombre;
  string apellido;
  Direccion direccion;
};

struct DtEmpresa
{
public:
  virtual string getId() { return this->id; }

  virtual Direccion getDir() { return this->direccion; }

  virtual string print() = 0;

  virtual ~DtEmpresa(){};

protected:
  string id;
  Direccion direccion;
};

struct DtNacional : DtEmpresa
{
public:
  DtNacional(string id, Direccion dir, string rut)
  {
    this->id = id;
    this->direccion = dir;
    this->rut = rut;
  }

  string getRut() { return this->rut; }

  string print() {
    string var = "ID: " + this->id + "\nDireccion: " + this->direccion.getCalle() + " " + to_string(this->direccion.getNumero()) + ", " + this->direccion.getCiudad() + "\nRUT: " + this->rut;
    return var;
  }

  ~DtNacional(){};

private:
  string rut;
};

struct DtExtranjera : DtEmpresa
{
public:
  DtExtranjera(string id, Direccion dir, string nombreFantasia)
  {
    this->id = id;
    this->direccion = dir;
    this->nombreFantasia = nombreFantasia;
  }

  string getNombreFantasia() { return this->nombreFantasia; }

  
  string print() {
    string var = "ID: " + this->id + "\nDireccion: " + this->direccion.getCalle() + " " + to_string(this->direccion.getNumero()) + ", " + this->direccion.getCiudad() + "\nNombre Fantasia: " + this->nombreFantasia;
    return var;
  }

  ~DtExtranjera(){};

private:
  string nombreFantasia;
};

#endif