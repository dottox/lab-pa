#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;



struct DtNacional{
  string rut;
};

struct DtExtranjera{
  string nombreFantasia;
};

struct DtEmpresa : public DtNacional, DtExtranjera {
  string id;
};


void test(DtEmpresa** lista, DtEmpresa* a, int &cant) { // DtEmpresa asd
  lista[cant++] = a;
}


int main(){
  DtEmpresa** lista = new DtEmpresa*[3];
  int cant = 0;

  DtEmpresa* asd;
  asd->id = "1";
  asd->rut = "2";
  test(lista, asd, cant);

  cout << lista[0]->id << endl;
  cout << lista[0]->rut << endl;
  return 0;
}