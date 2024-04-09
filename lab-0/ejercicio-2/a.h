#ifndef A_H
#define A_H

#include "b.h"
#include "c.h"

class A{
  public:
    A(int x = 0, int y = 0){
      this->x = x;
      this->y = y;
    }

    int getX() { return this->x; }

    int getY() { return this->y; }

  private:
  int x;
    int y;
    B b;
    C c;
};

#endif