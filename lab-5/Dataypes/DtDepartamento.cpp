struct DtDepartamento {
  private:
    char codigo;
    string nombre;

  public:
    DtDepartamento(char c, string n)
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
