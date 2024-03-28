 #include "EmpresaExtranjera.h"

EmpresaExtranjera::EmpresaExtranjera(string id, Direccion d, string nombreFantasia) : Empresa::Empresa(id, d) {
  this->nombreFantasia = nombreFantasia;
}

void EmpresaExtranjera::setNombreFantasia(string nombreFantasia){
  this->nombreFantasia = nombreFantasia;
}

string EmpresaExtranjera::getNombreFantasia(){
  return this->nombreFantasia;
}

float EmpresaExtranjera::getDescuento(){
  return 0.2;
}

EmpresaExtranjera::~EmpresaExtranjera() {}

