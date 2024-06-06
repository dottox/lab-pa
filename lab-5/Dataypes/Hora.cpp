struct Hora {
  private:
    int hora;
    int minuto;

  public:
    Hora(int h, int m)
    {
      this->hora = h;
      this->minuto = m;
    };

    int getHora()
    {
      return this->hora;
    };

    int getMinuto()
    {
      return this->minuto;
    };
};
