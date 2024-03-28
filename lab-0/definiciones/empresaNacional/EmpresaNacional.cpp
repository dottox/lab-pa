#include "EmpresaNacional.h"

EmpresaNacional::EmpresaNacional(string id, Direccion d, string rut) : Empresa::Empresa(id, d) {
  this->rut = rut;
}

void EmpresaNacional::setRut(string rut){
  this->rut = rut;
}

string EmpresaNacional::getRut(){
  return this->rut;
}

float EmpresaNacional::getDescuento(){
  return 0.35;
}

EmpresaNacional::~EmpresaNacional() {}
