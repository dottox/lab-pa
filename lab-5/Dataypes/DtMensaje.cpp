#include "Fecha.cpp"
#include "Hora.cpp"

struct DtMensaje
{
  private:
    Fecha fecha;
    Hora hora;
    string texto;

  public:
    DtMensaje(Fecha f, Hora h, string t)
    {
      this->fecha = f;
      this->hora = h;
      this->texto = t;
    };

    Fecha getFecha()
    {
      return this->fecha;
    };

    Hora getHora()
    {
      return this->hora;
    };

    string getTexto()
    {
      return this->texto;
    };
};
