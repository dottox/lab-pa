#ifndef SISTEMAFABRICA_H
#define SISTEMAFABRICA_H

#include "Sistema.h"
#include "ISistema.h"

class SistemaFabrica {
public:
  static ISistema *getSistema();
};

#endif