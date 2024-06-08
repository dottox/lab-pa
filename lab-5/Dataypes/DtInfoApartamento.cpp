#include "DtDirecion.cpp"

struct DtInfoApartamento {
  private:
    int codigo;
    int cantAmbientes;
    int cantDOrmitorios;
    int cantBanios;
    bool garaje;
    DtDireccion direccion;
    float mtsCuadradosEdificados;
    float mtsCuadradosTotales;
    float mtsCuadradosVerdes;
    string tipo;
    float precio;

  public:
    DtInfoApartamento(int, int, int, int, bool, DtDireccion, float, float, float, string, float);

    int getCodigo();
    int getCantAmbientes();
    int getCantDormitorios();
    int getCantBanios();
    float getMtsCuadradosEdificados();
    float getMtsCuadradosTotales();
    string getTipo();
    float getPrecio();
    DtDireccion getDireccion();
    bool getGaraje();
};

DtDatosCasa::DtDatosCasa(int codigo, int cantAmbientes, int cantDOrmitorios, int cantBanios, bool garaje, DtDireccion direccion, float mtsCuadradosEdificados, float mtsCuadradosTotales, float mtsCuadradosVerdes, string tipo, float precio) {
  this->codigo = codigo;
  this->cantAmbientes = cantAmbientes;
  this->cantDOrmitorios = cantDOrmitorios;
  this->cantBanios = cantBanios;
  this->garaje = garaje;
  this->direccion = direccion;
  this->mtsCuadradosEdificados = mtsCuadradosEdificados;
  this->mtsCuadradosTotales = mtsCuadradosTotales;
  this->mtsCuadradosVerdes = mtsCuadradosVerdes;
  this->tipo = tipo;
  this->precio = precio;
}

int DtDatosCasa::getCodigo() {
  return this->codigo;
}

int DtDatosCasa::getCantAmbientes() {
  return this->cantAmbientes;
}

int DtDatosCasa::getCantDormitorios() {
  return this->cantDOrmitorios;
}

int DtDatosCasa::getCantBanios() {
  return this->cantBanios;
}

float DtDatosCasa::getMtsCuadradosEdificados() {
  return this->mtsCuadradosEdificados;
}

float DtDatosCasa::getMtsCuadradosTotales() {
  return this->mtsCuadradosTotales;
}

string DtDatosCasa::getTipo() {
  return this->tipo;
}

float DtDatosCasa::getPrecio() {
  return this->precio;
}

DtDireccion DtDatosCasa::getDireccion() {
  return this->direccion;
}

bool DtDatosCasa::getGaraje() {
  return this->garaje;
}
