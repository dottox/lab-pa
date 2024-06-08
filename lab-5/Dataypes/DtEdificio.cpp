#include <string>

struct DtEdificio 
{
  private:
    string nombre;
    int cantPisos;
    float gastosComunes;

  public:
    DtEdificio(string n, int cp, float gc)
    {
      this->nombre = n;
      this->cantPisos = cp;
      this->gastosComunes = gc;
    };

    string getNombre()
    {
      return this->nombre;
    };

    string getCiudad()
    {
      return this->ciudad;
    };

    int getNro()
    {
      return this->nro;
    };
};
