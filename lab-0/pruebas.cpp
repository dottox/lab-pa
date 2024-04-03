#include <iostream>
using namespace std;

struct test {
  public:
    void mytest() {
      cout << "Holaaa" << endl;
      cout << "Chauu" << endl;
    }
};


ostream& operator<<(ostream& os, test& t) {
  t.mytest();
  return os;
}


int main() {
  test t;
  cout << t << endl;
  return 0;
}