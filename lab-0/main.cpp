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

class Sistema {
  private:
    Empleado** empleados;
    int cantEmpleados;

    EmpresaNacional** empresasN;
    EmpresaExtranjera** empresasE;
    int cantEmpresasN;
    int cantEmpresasE;

    RelacionLaboral** relacionesLaborales;
    int cantRelacionesLaborales;

  public:
    void agregarEmpleado(string ci, string nombre, string apellido, Direccion dir) {
      Empleado* e = new Empleado(ci, nombre, apellido, dir);
      empleados[cantEmpleados++] = e;
    }

    void agregarEmpresa(DtNacional* empresa) {
      EmpresaNacional* e = new EmpresaNacional(empresa->id, empresa->direccion, empresa->rut);
      empresasN[cantEmpresasN++] = e;
    }

    void agregarEmpresa(DtExtranjera* empresa) {
      EmpresaExtranjera* e = new EmpresaExtranjera(empresa->id, empresa->direccion, empresa->nombreFantasia);
      empresasE[cantEmpresasE++] = e;
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
      //
      
    }
};

DtNacional* getDtNacional(string id, Direccion direccion, string rut) {
  DtNacional* nacional = new DtNacional();
  nacional->id = id;
  nacional->direccion = direccion;
  nacional->rut = rut;
  return nacional;
}

DtExtranjera* getDtExtranjera(string id, Direccion direccion, string nombreFantasia) {
  DtExtranjera* extranjera = new DtExtranjera();
  extranjera->id = id;
  extranjera->direccion = direccion;
  extranjera->nombreFantasia = nombreFantasia;
  return extranjera;
}

int main() {

  DtNacional* nacional1 = getDtNacional("1", {"Calle 1", 1, "Montevideo"}, "1");
  DtNacional* nacional2 = getDtNacional("2", {"Calle 2", 2, "Montevideo"}, "2");
  DtNacional* nacional3 = getDtNacional("3", {"Calle 3", 3, "Montevideo"}, "3");
  
  DtExtranjera* extranjera1 = getDtExtranjera("2", {"Calle 2", 2, "Montevideo"}, "Empresa 1");
  DtExtranjera* extranjera2 = getDtExtranjera("3", {"Calle 3", 3, "Montevideo"}, "Empresa 2");
  DtExtranjera* extranjera3 = getDtExtranjera("4", {"Calle 4", 4, "Montevideo"}, "Empresa 3");

  DtEmpleado* empleado1 = new DtEmpleado{"1", "Juan", "Perez", {"Calle 1", 1, "Montevideo"}, 1000};
  DtEmpleado* empleado2 = new DtEmpleado{"2", "Pedro", "Gonzalez", {"Calle 2", 2, "Montevideo"}, 2000};
  DtEmpleado* empleado3 = new DtEmpleado{"3", "Maria", "Rodriguez", {"Calle 3", 3, "Montevideo"}, 3000};
  DtEmpleado* empleado4 = new DtEmpleado{"4", "Ana", "Lopez", {"Calle 4", 4, "Montevideo"}, 4000};


  
  Sistema* s = new Sistema();

  
  s->agregarEmpresa(nacional1);
  s->agregarEmpresa(extranjera1);
  s->agregarEmpresa(extranjera2);

  cout << "Hola Mundo! c:" << endl;

  return 0;
}