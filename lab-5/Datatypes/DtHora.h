#ifndef DTHORA_H
#define DTHORA_H

#include "../ICollection/interfaces/ICollectible.h"

class ICollectible;

struct DtHora : public ICollectible 
{
  private:
    int hora;
    int minuto;
    DtHora getHoraActual();

  public:
    DtHora();
    DtHora(int, int);
    int getHora();
    int getMinuto();

    ~DtHora();
};

#endif
