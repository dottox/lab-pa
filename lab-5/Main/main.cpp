#include "Includes.cpp"
#include <iostream>

using namespace std;

int main() {
  ICollection* myList = new List();
  ICollectible* myInt = new Integer(5);
  ICollectible* myString = new String("Hello, World!");

  myList->add(myInt);
  myList->add(myString);

  // Iterar sobre la colección
  IIterator* it = myList->getIterator();
  while (it->hasCurrent()) {
    ICollectible* current = it->getCurrent();
    
    // Dynamic cast to integer or string
    Integer* intPtr = dynamic_cast<Integer*>(current);
    String* strPtr = dynamic_cast<String*>(current);
    if (intPtr != nullptr) {
      cout << intPtr->getValue() << endl;
    } else if (strPtr != nullptr) {
      cout << strPtr->getValue() << endl;
    }
    it->next();
  }

  delete myList;
  delete myInt;
  delete myString;
}