#ifndef DTFECHA_H
#define DTFECHA_H

struct DtFecha {
  private:
    int dia;
    int mes;
    int anio;

  public:
    DtFecha();
    DtFecha(int, int, int);
    int getDia();
    int getMes();
    int getAnio();
};

#endif