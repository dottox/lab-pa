#ifndef C_H
#define C_H

#include "a.h"
#include "b.h"

class C{
  public:
    C(int x = 0, int y = 0){
      this->x = x;
      this->y = y;
    }

    

    int getX() { return this->x; }

    int getY() { return this->y; }

  private:
    int x;
    int y;
    A a;
    B b;
};

#endif