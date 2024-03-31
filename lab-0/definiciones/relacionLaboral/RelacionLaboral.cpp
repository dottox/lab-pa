#include "RelacionLaboral.h"

RelacionLaboral::RelacionLaboral(Empresa* empresa, Empleado* empleado, float sueldo, Fecha f){
  this->empleado = empleado;
  this->empresa = empresa;
  this->sueldo = sueldo;
  this->fechaDesvinculacion = f;
}

void RelacionLaboral::setSueldo(float sueldo){
  this->sueldo = sueldo;
}

void RelacionLaboral::setFechaDesvinculacion(Fecha fecha){
  this->fechaDesvinculacion = fecha;
}

float RelacionLaboral::getSueldoLiquido(){
  return (this->sueldo * (1 - this->empresa->getDescuento()));
};              

string RelacionLaboral::getIdEmpresa(){
  return this->empresa->getId();
};

string RelacionLaboral::getCiEmpleado(){
  return this->empleado->getCi();
};

Fecha RelacionLaboral::getFechaDesvinculacion(){
  return this->fechaDesvinculacion;
};

RelacionLaboral::~RelacionLaboral() {};