#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;


struct DtEmpresa{
  protected:
    string id;
    string direccion;

  public:
    virtual string getId() {
      return this->id;
    }

    virtual string getDir(){
      return this->direccion;
    }
    
    virtual ~DtEmpresa() {};
};

struct DtNacional : DtEmpresa {
  public:
    DtNacional(string id, string dir, string rut){
      this->id = id;
      this->direccion = dir;
      this->rut = rut;
    }
    
    string getRut(){
      return this->rut;
    }
  
    ~DtNacional() {}
  private:
    string rut;
  
};

int main() {
  DtNacional* dt = new DtNacional("1", "2", "3");
  cout << dt->getId() << endl;
  cout << dt->getDir() << endl;
  cout << dt->getRut() << endl;
  delete dt;
}