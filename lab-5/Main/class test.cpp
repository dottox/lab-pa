#include <iostream>
#include <string>

class A {
  public:
    A() {
      std::cout << "A" << std::endl;
    }
    virtual ~A() {
      std::cout << "~A" << std::endl;
    }
};


class B : public A {
  public:
    B() {
      std::cout << "B" << std::endl;
    }
    void greet() {
      std::cout << "Hello" << std::endl;
    }
    ~B() {
      std::cout << "~B" << std::endl;
    }
};

int fun(B* b) {
  b->greet();
  return 0;
}

int main() {
  A* a = new B();
  fun((B*)a);
}