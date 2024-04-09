#ifndef B_H
#define B_H

#include "a.h"
#include "c.h"

class B {
  public:
    B(int x = 0, int y = 0){
      this->x = x;
      this->y = y;
    }

    int getX() { return this->x; }

    int getY() { return this->y; }

  private:
  int x;
    int y;
    A a;
    C c;
};

#endif