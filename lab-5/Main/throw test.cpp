#include <iostream>
#include <string>

void fun();

int main() {
  try {
    fun();
  }
  catch (std::string e) {
    std::cout << "Error: " << e << std::endl;
  }

  std::cout << "Hola" << std::endl;
}

void fun() {
  throw (std::string)"holaa";
}