#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;



struct DtEmpresa{
  string id;

  //  ~~~~~ EXPLICACION DEL VIRTUAL. ~~~~~
  // In C++, the virtual keyword is used to allow derived classes to override a function of the base class. 
  // This is a key part of the concept of polymorphism in object-oriented programming.

  // A class is considered polymorphic in C++ if it has at least one virtual function. 
  // This is because without a virtual function, there's no way for a base class pointer 
  // or reference to call a function in a derived class, which is the essence of polymorphism.
  virtual ~DtEmpresa() {}

  virtual void foo() {
    cout << "Test" << endl;
  }
};

struct DtNacional : DtEmpresa{
  string rut;

  //  ~~~~~ EXPLICACION DEL OVERRIDE. ~~~~~
  // The override keyword in C++ is used to specify that a virtual function 
  // is intended to override a function in a base class. 
  // When you declare a function as override, the compiler will check that 
  // a function with the same signature exists in the base class, 
  // and that it is declared as virtual. 

  // If no such function exists, the compiler will give an error.
  // The override keyword helps prevent bugs in your code. 
  // For example, if you misspell the function name 
  // or get the parameters wrong in the derived class, 
  // the compiler will give an error because the function does not override anything 
  // in the base class.

  // void foo() override {
  //   cout << "Test override" << endl;
  // }

  // En mi G++ no compila, necesito una versión más nueva.

  ~DtNacional() {}
};

struct DtExtranjera : DtEmpresa{
  string nombreFantasia;

  //  ~~~~~ EXPLICACION DEL DESTRUCTOR. ~~~~~
  // In the destructors of DtNacional and DtExtranjera, you should clean up any resources that are allocated within those classes.
  // However, since string automatically manages its own memory,
  // you don't need to do anything special in this case.

  // No, you should not put 'delete this'; inside the destructor. 
  // The destructor is automatically called when an object is being deleted.
  // If you put delete this; inside the destructor, it will cause the destructor to be called again,
  // leading to undefined behavior and likely a program crash.

  // When you delete an object through a pointer, like delete ptr;, the following happens:

  //    1. The object's destructor is called to clean up its resources.
  //    2. The memory for the object is deallocated.

  // So, you don't need to (and should not) manually call delete this; inside the destructor. The memory deallocation is automatically handled for you after the destructor is called.

  // If you have dynamically allocated memory inside your objects (like raw pointers to other objects), you should delete that memory in the destructor.
  ~DtExtranjera() {}
};

void test(DtNacional* &emp) {
  cout << emp->rut << endl;
}

void test(DtExtranjera* &emp) {
  cout << emp->nombreFantasia << endl;
}


int main(){

  DtEmpresa* lista[2];

  lista[0] = new DtNacional();
  lista[1] = new DtExtranjera();

  //  ~~~~~ EXPLICACION DEL TYPECASTING. ~~~~~
  // The typecasting in these lines is necessary because lista is an array of pointers
  // to DtEmpresa, the base class. The base class DtEmpresa does not have the members rut or nombreFantasia.
  // These members are specific to the derived classes DtNacional and DtExtranjera.
  // This typecasting is safe in this case because you know that lista[0]
  // actually points to a DtNacional object and lista[1] actually points to a DtExtranjera object.
  // If this were not the case, the typecasting could lead to undefined behavior.
  ((DtNacional*)lista[0])->rut = "123";
  ((DtExtranjera*)lista[1])->nombreFantasia = "Fantasia";

  //  ~~~~~ EXPLICACION DEL DYNAMIC CASTING. ~~~~~
  // If you want to keep the test function outside of the classes,
  // you can use dynamic casting to determine the actual type of the object
  // at runtime. In this code, dynamic_cast is used to try to cast the DtEmpresa pointer to a DtNacional pointer
  // and a DtExtranjera pointer. If the cast is successful, the corresponding test function is called.
  // If the cast fails for some reason, the pointer is set to nullptr.
  // Please note that for dynamic_cast to work,
  // the base class (DtEmpresa in this case) must have at least one virtual function.
  // You can add a virtual destructor to DtEmpresa to satisfy this requirement:
  for (int i = 0; i < 2; i++) {
    if (DtNacional* emp = dynamic_cast<DtNacional*>(lista[i])) {
      test(emp);
    } else if (DtExtranjera* emp = dynamic_cast<DtExtranjera*>(lista[i])) {
      test(emp);
    }
  }

  //  ~~~~~ EXPLICACION DEL LLAMADO A DELETE. ~~~~~
  // When you delete a pointer, the appropriate destructor is automatically 
  // called based on the actual type of the object, provided that the base class
  // destructor is declared as virtual.
  delete lista[0];
  delete lista[1];

  return 0;
}