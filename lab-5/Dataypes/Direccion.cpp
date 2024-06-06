#include <string>

struct Direccion 
{
  private:
    string calle;
    string ciudad;
    int nro;

  public:
    Direccion(string ca, string ci, int n)
    {
      this->calle = ca;
      this->ciudad = ci;
      this->nro = n;
    };

    string getCalle()
    {
      return this->calle;
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
