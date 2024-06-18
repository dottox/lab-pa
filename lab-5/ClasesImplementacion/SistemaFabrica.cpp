#include "../Clases/SistemaFabrica.h"

ISistema* SistemaFabrica::getSistema()
{
  return Sistema::getInstancia();
}