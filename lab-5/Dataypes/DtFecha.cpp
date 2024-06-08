struct Fecha {
  private:
    int dia;
    int mes;
    int anio;

  public:
    Fecha(int d, int m, int a)
    {
      this->dia = d;
      this->mes = m;
      this->anio = a;
    };
    
    int getDia()
    {
      return this->dia;
    };

    int getMes()
    {
      return this->mes;
    };

    int getAnio()
    {
      return this->anio;
    };
};
