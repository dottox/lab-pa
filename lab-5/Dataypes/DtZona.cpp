struct DtZona {
  private:
    int codigo;
    string nombre;

  public:
    DtZona(int c, string n)
    {
      this->codigo = c;
      this->nombre = n;
    };

    int getCodigo()
    {
      return this->codigo;
    };

    string getNombre()
    {
      return this->nombre;
    };
};
