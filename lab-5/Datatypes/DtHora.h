#ifndef DTHORA_H
#define DTHORA_H

struct DtHora {
  private:
    int hora;
    int minuto;

  public:
    DtHora();
    DtHora(int, int);
    int getHora();
    int getMinuto();
};

#endif
