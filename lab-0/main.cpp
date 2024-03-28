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

void mostrarInfo(DtEmpresa* empresa){
  cout << "------------------------------------------------------------------------------------" << endl;
    if (DtNacional* nacional = dynamic_cast<DtNacional*>(empresa)) { // Es una empresa nacional
        cout << "RUT: " << nacional->getRut() << endl;
    } else if (DtExtranjera* extranjera = dynamic_cast<DtExtranjera*>(empresa)) { // Es una empresa extranjera
        cout << "Nombre: " << extranjera->getNombreFantasia() << endl;
    }

  cout << "Direccion: " << empresa->getDir().getCalle() << " " << empresa->getDir().getNumero() << " " << empresa->getDir().getCiudad() << endl;
}

/*
DtNacional * den = dynamic_cast <DtNacional *> (DtEmpresa);

if(den != NULL){
  empresas[cantidadEmpresas] = new EmpresaNacional(
    den->getId(),
    den->getDireccion(),
    den->getRut()
  );
}else{
    DtExtranjera * den = dynamic_cast <DtExtranjeta *> (DtEmpresa);
    empresas[cantidadEmpresas] = new EmpresaExtranjera(
    den->getId(),
    den->getDireccion(),
    den->getNombreFantasia()
  );
}
cantidadEmpresas++;*/

int main() {

  Direccion dir1 = Direccion("Calle 1", 1234, "Montevideo");
  Direccion dir2 = Direccion("Calle 321", 1234, "Nueva York");
  DtNacional* nacional1 = new DtNacional("1", dir1, "214789");
  // DtNacional* nacional2 = new DtNacional("2", dir1, "2");
  // DtNacional* nacional3 = new DtNacional("3", dir1, "3");
  
  DtExtranjera* extranjera1 = new DtExtranjera("2", dir2, "COCA COLA");
  // DtExtranjera* extranjera2 = new DtExtranjera("3", dir1, "Empresa 2");
  // DtExtranjera* extranjera3 = new DtExtranjera("4", dir1, "Empresa 3");

  DtEmpleado* empleado1 =  new DtEmpleado("1", "Juan", "Perez", dir1);
  // DtEmpleado* empleado2 = new DtEmpleado("2", "Pedro", "Gonzalez", dir1);
  // DtEmpleado* empleado3 = new DtEmpleado("3", "Maria", "Rodriguez", dir1);
  // DtEmpleado* empleado4 = new DtEmpleado("4", "Ana", "Lopez", dir1);


  
  Sistema* s = new Sistema();

  
  // s->agregarEmpresa(nacional1);
  // s->agregarEmpresa(extranjera1);
  // s->agregarEmpresa(extranjera2);

  mostrarInfo(nacional1);
  mostrarInfo(extranjera1);

  return 0;
}