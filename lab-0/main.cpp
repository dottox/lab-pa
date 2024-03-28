// void agregarEmpleado(string ci, string nombre, string 
// apellido, Direccion dir) Crea un nuevo empleado en el sistema. En 
// caso de ya existir, levanta la excepción std::invalid_argument.

// void agregarEmpresa(DtEmpresa * empresa), Crea una nueva 
// empresa en el sistema. En caso de ya existir, levanta una excepción 
// std::invalid_argument.

// c) DtEmpleado** listarEmpleados(int & cantEmpleados)Retorna 
// un arreglo de DtEmpleado* con todos los empleados del sistema. El largo 
// del arreglo de empleados está dado por el parámetro cantEmpleados.

// d) void agregarRelacionLaboral(String ciEmpleado, string 
// idEmpresa, float sueldo)Vincula un empleado con una empresa. Si la 
// empresa ya está dentro de las empresas que el empleado ha trabajado o 
// trabaja se levanta una excepción std::invalid_argument.

// e) void finalizarRelacionLaboral(string ciEmpleado, string 
// idEmpresa, Fecha desvinculación)Desvincula al empleado de la 
// empresa, registrando la fecha en que terminó el vinculo.

// f) DtEmpresa** obtenerInfoEmpresaPorEmpleado(string 
// ciEmpleado, int & cantEmpresas) Retorna un arreglo con las 
// empresas donde trabaja activamente el empleado. El largo del arreglo de 
// empresas está dado por el parámetro cantEmpresas.

#include "definiciones/empresa/Empresa.h"
#include "definiciones/empresaNacional/EmpresaNacional.h"
#include "definiciones/empresaExtranjera/EmpresaExtranjera.h"
#include "definiciones/empleado/Empleado.h"
#include "definiciones/relacionLaboral/RelacionLaboral.h"

#define MAX_EMPLEADOS 10
#define MAX_EMPRESAS 20
#define MAX_RELACIONES_LABORALES (MAX_EMPLEADOS * MAX_EMPRESAS)

class Sistema {
  private:
    Empleado** empleados;
    int cantEmpleados;

    Empresa** empresas;
    int cantEmpresas;

    RelacionLaboral** relacionesLaborales;
    int cantRelacionesLaborales;

  public:

    Sistema() {
      empleados = new Empleado*[MAX_EMPLEADOS];
      cantEmpleados = 0;

      empresas = new Empresa*[MAX_EMPRESAS];
      cantEmpresas = 0;

      relacionesLaborales = new RelacionLaboral*[MAX_RELACIONES_LABORALES];
      cantRelacionesLaborales = 0;
    }

    ~Sistema() {
      delete[] empleados;
      delete[] empresas;
      delete[] relacionesLaborales;
    }

    void agregarEmpresa(DtEmpresa* emp) {
      if (DtNacional* nacional = dynamic_cast<DtNacional*>(emp)) { // Es una empresa nacional
        EmpresaNacional* e = new EmpresaNacional(nacional->getId(), nacional->getDir(), nacional->getRut());
        this->empresas[cantEmpresas++] = e;
      } else if (DtExtranjera* extranjera = dynamic_cast<DtExtranjera*>(emp)) { // Es una empresa extranjera
        EmpresaExtranjera* e = new EmpresaExtranjera(extranjera->getId(), extranjera->getDir(), extranjera->getNombreFantasia());
        this->empresas[cantEmpresas++] = e;
      }

      delete emp;
    }

    void agregarEmpleado(DtEmpleado* emp) {
      Empleado* e = new Empleado(emp->getCi(), emp->getNombre(), emp->getApellido(), emp->getDireccion());
      empleados[cantEmpleados++] = e;

      delete emp;
    }

    void agregarRelacionLaboral(string ciEmpleado, string idEmpresa, float sueldo) {
      //e->agregarRelacionLaboral(emp, sueldo);
    }
    
    void finalizarRelacionLaboral(string ciEmpleado, string idEmpresa, Fecha desvinculacion) {
      //
    }

    void listarEmpleados(int cantEmpleados) {
      Empleado** empleados = new Empleado*[cantEmpleados];
      for (int i = 0; i < cantEmpleados; i++) {
        cout << "Empleado: " << empleados[i]->getNombre() << " " << empleados[i]->getApellido() << " c:" << endl;
      }
    }

    DtEmpresa** obtenerInfoEmpresaPorEmpleado(string ciEmpleado, int cantEmpresas) {
      cout << "incoming";
    }
    
    void mostrarInfoEmpresa(){
      for (int i = 0; i < cantEmpresas; i++) {
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << "ID: " << empresas[i]->getId() << endl;
        if (EmpresaNacional* nacional = dynamic_cast<EmpresaNacional*>(empresas[i])) { // Es una empresa nacional
            cout << "RUT: " << nacional->getRut() << endl;
        } else if (EmpresaExtranjera* extranjera = dynamic_cast<EmpresaExtranjera*>(empresas[i])) { // Es una empresa extranjera
            cout << "Nombre: " << extranjera->getNombreFantasia() << endl;
        }
        cout << "Direccion: " << empresas[i]->getDireccion().getCalle() << " " << empresas[i]->getDireccion().getNumero() << " " << empresas[i]->getDireccion().getCiudad() << endl;
      }
    }
};


int main() {

  Direccion dir1 = Direccion("Calle 1", 1234, "Montevideo");
  Direccion dir2 = Direccion("Calle 321", 1234, "Nueva York");
  DtNacional* nacional1 = new DtNacional("1", dir1, "214789");
  DtNacional* nacional2 = new DtNacional("2", dir1, "03213219");
  DtNacional* nacional3 = new DtNacional("3", dir1, "413432432");
  
  DtExtranjera* extranjera1 = new DtExtranjera("4", dir2, "COCA COLA");
  DtExtranjera* extranjera2 = new DtExtranjera("5", dir1, "MC DONALDS");
  DtExtranjera* extranjera3 = new DtExtranjera("6", dir1, "HAMBURGUESA KING");

  DtEmpleado* empleado1 =  new DtEmpleado("1", "Juan", "Perez", dir1);
  DtEmpleado* empleado2 = new DtEmpleado("2", "Pedro", "Gonzalez", dir1);
  DtEmpleado* empleado3 = new DtEmpleado("3", "Maria", "Rodriguez", dir1);
  DtEmpleado* empleado4 = new DtEmpleado("4", "Ana", "Lopez", dir1);
  
  Sistema* s = new Sistema();
  s->agregarEmpleado(empleado1);
  s->agregarEmpleado(empleado2);
  s->agregarEmpleado(empleado3);
  s->agregarEmpleado(empleado4);
  
  s->agregarEmpresa(nacional1);
  s->agregarEmpresa(nacional2);
  s->agregarEmpresa(nacional3);
  s->agregarEmpresa(extranjera1); 
  s->agregarEmpresa(extranjera2);
  s->agregarEmpresa(extranjera3);

  s->mostrarInfoEmpresa();

}