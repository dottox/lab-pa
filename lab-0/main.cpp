// void agregarEmpleado(string ci, string nombre, string 
// apellido, Direccion dir) Crea un nuevo empleado en el sistema. En 
// caso de ya existir, levanta la excepción std::invalid_argument.

// void agregarEmpresa(DtEmpresa * empresa), Crea una nueva 
// empresa en el sistema. En caso de ya existir, levanta una excepción 
// std::invalid_argument.

// c) DtEmpleado** listarEmpleados(int &cantEmpleados)Retorna 
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

    // --- FUNCIONES AUXILIARES ---

    // Devuelve al empleado si existe, NULL en caso contrario.
    Empleado* buscarEmpleado(string ci) {
      for (int i = 0; i < cantEmpleados; i++) {
        if (empleados[i]->getCi() == ci) {
          return empleados[i];
        }
      }
      return NULL;
    }

    // Devuelve a la empresa si existe, NULL en caso contrario.
    Empresa* buscarEmpresa(string id) {
      for (int i = 0; i < cantEmpresas; i++) {
        if (empresas[i]->getId() == id) {
          return empresas[i];
        }
      }
      return NULL;
    }

    // Devuelve la relación laboral si existe, NULL en caso contrario.
    RelacionLaboral* buscarRelacionLaboral(string ciEmpleado, string idEmpresa) {
      for (int i = 0; i < cantRelacionesLaborales; i++) {
        if (relacionesLaborales[i]->getCiEmpleado() == ciEmpleado && relacionesLaborales[i]->getIdEmpresa() == idEmpresa) {
          return relacionesLaborales[i];
        }
      }
      return NULL;
    }

    // Devuelve true si el sistema está lleno de empleados.
    bool empleadosIsFull() {
      return cantEmpleados >= MAX_EMPLEADOS;
    }
    
    // Devuelve true si el sistema está lleno de empresas.
    bool empresasIsFull() {
      return cantEmpresas >= MAX_EMPRESAS;
    }

    // Devuelve true si el sistema está lleno de relaciones laborales.
    bool relacionesLaboralesIsFull() {
      return cantRelacionesLaborales >= MAX_RELACIONES_LABORALES;
    }

    // ----------------------------
   
    // Crea un nuevo empleado en el sistema. 
    // En caso de ya existir, levanta la excepción std::invalid_argument.
    void agregarEmpresa(DtEmpresa* emp) {
       if (buscarEmpresa(emp->getId()) != NULL) {
        throw std::invalid_argument("La empresa ya existe");
      }

      if (DtNacional* nacional = dynamic_cast<DtNacional*>(emp)) { // Es una empresa nacional
        EmpresaNacional* e = new EmpresaNacional(nacional->getId(), nacional->getDir(), nacional->getRut());
        this->empresas[cantEmpresas++] = e;
      } else if (DtExtranjera* extranjera = dynamic_cast<DtExtranjera*>(emp)) { // Es una empresa extranjera
        EmpresaExtranjera* e = new EmpresaExtranjera(extranjera->getId(), extranjera->getDir(), extranjera->getNombreFantasia());
        this->empresas[cantEmpresas++] = e;
      }
      delete emp;
    }

    // Crea una nueva empresa en el sistema. 
    // En caso de ya existir, levanta una excepción std::invalid_argument.
    void agregarEmpleado(string ci, string nombre, string apellido, Direccion dir) {
      if (buscarEmpleado(ci) != NULL) {
        throw std::invalid_argument("El empleado ya existe");
      }
      Empleado* e = new Empleado(ci, nombre, apellido, dir);
      empleados[cantEmpleados++] = e;
    }

    // Retorna un arreglo de DtEmpleado* con todos los empleados del sistema.
    // El largo del arreglo de empleados está dado por el parámetro cantEmpleados.
    DtEmpleado** listarEmpleados(int cantEmpleados) {
      DtEmpleado** empleados = new DtEmpleado*[cantEmpleados];
      for (int i = 0; i < cantEmpleados; i++) {
        Empleado* e = this->empleados[i];
        empleados[i] = new DtEmpleado(e->getCi(), e->getNombre(), e->getApellido(), e->getDireccion());
      }
      return empleados;
    }

    // Vincula un empleado con una empresa.
    // Si la empresa ya está dentro de las empresas que el empleado ha trabajado
    // o trabaja se levanta una excepción std::invalid_argument.
    void agregarRelacionLaboral(string ciEmpleado, string idEmpresa, float sueldo) {
      // 1. Si empleado existe
      if (buscarEmpleado(ciEmpleado) == NULL) {
        throw std::invalid_argument("El empleado no existe");
      }

      // 2. Si empresa existe
      if (buscarEmpresa(idEmpresa) == NULL) {
        throw std::invalid_argument("La empresa no existe");
      }

      // 3. Si el empleado no trabaja ya en la empresa
      if (buscarRelacionLaboral(ciEmpleado, idEmpresa) != NULL) {
        throw std::invalid_argument("El empleado ya trabaja o trabajo en la empresa");
      }

      // 4. Si rel lab no está lleno
      if (relacionesLaboralesIsFull()) {
        throw std::invalid_argument("No se pueden agregar mas relaciones laborales");
      }

      // Endpoint: Agregar la relacion laboral
      Empleado* empleado = buscarEmpleado(ciEmpleado);
      Empresa* empresa = buscarEmpresa(idEmpresa);
      Fecha f = Fecha(0, 0, 0);
      RelacionLaboral* rl = new RelacionLaboral(empresa, empleado, sueldo, f);
      relacionesLaborales[cantRelacionesLaborales++] = rl;
    }
    
    void finalizarRelacionLaboral(string ciEmpleado, string idEmpresa, Fecha desvinculacion) {
      // 1. Si empleado existe
      if (buscarEmpleado(ciEmpleado) == NULL) {
        throw std::invalid_argument("El empleado no existe");
      }

      // 2. Si empresa existe
      if (buscarEmpresa(idEmpresa) == NULL) {
        throw std::invalid_argument("La empresa no existe");
      }

      // 3. Si el empleado trabaja en la empresa
      RelacionLaboral* rl = buscarRelacionLaboral(ciEmpleado, idEmpresa);
      if (rl == NULL) {
        throw std::invalid_argument("El empleado no ha trabajado en la empresa");
      }

      // Endpoint: Actualizar la fecha de desvinculacion
      rl->setFechaDesvinculacion(desvinculacion);
      return;
    }

  // Retorna un arreglo con las empresas donde trabaja activamente el empleado. 
  // El largo del arreglo de empresas está dado por el parámetro cantEmpresas.
      DtEmpresa** obtenerInfoEmpresaPorEmpleado(string ciEmpleado, int & cantEmpres) {
       // 1. Si empleado existe.
      if (buscarEmpleado(ciEmpleado) == NULL) {
        throw std::invalid_argument("El empleado no existe");
      }
      
      // Lista a devolver.
      DtEmpresa** empresas = new DtEmpresa*[cantEmpres];

      int x = 0;
      // Iterar sobre las relaciones laborales y obtener las empresas.
      for (int i = 0; i < cantRelacionesLaborales; i++) {
        if (x >= cantEmpres) {
          break;
        }

        // Si la relacion laboral es del empleado.
        RelacionLaboral* rl = relacionesLaborales[i];
        if (rl->getCiEmpleado() == ciEmpleado) {

          Fecha aux = rl->getFechaDesvinculacion();
          // Si la relación ya terminó, pasamos a la siguiente relacion laboral.
          if (aux.getDia() != 0 && aux.getMes() != 0 && aux.getAnio() != 0) {
            continue;
          }

          // Agregar la empresa a la lista.
          string IdEmpresa = rl->getIdEmpresa();
          Empresa* e = buscarEmpresa(IdEmpresa);
          if (EmpresaNacional* nacional = dynamic_cast<EmpresaNacional*>(e)) { // Es una empresa nacional
            empresas[x++] = new DtNacional(nacional->getId(), nacional->getDireccion(), nacional->getRut());
          } else if (EmpresaExtranjera* extranjera = dynamic_cast<EmpresaExtranjera*>(e)) { // Es una empresa extranjera
            empresas[x++] = new DtExtranjera(extranjera->getId(), extranjera->getDireccion(), extranjera->getNombreFantasia());
          }
        }
      }

    }
    
    // Para mostrar empresas: i = 1
    // Para mostrar empleados: i = 2
    // Para mostrar rel. lab.: i = 3
    void mostrarInfo(int i){

      switch (i) {
        case 1:
          for (int i = 0; i < cantEmpresas; i++) {
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "ID: " << empresas[i]->getId() << endl;
            if (EmpresaNacional* nacional = dynamic_cast<EmpresaNacional*>(empresas[i])) { // Es una empresa nacional
                cout << "RUT: " << nacional->getRut() << endl;
            } else if (EmpresaExtranjera* extranjera = dynamic_cast<EmpresaExtranjera*>(empresas[i])) { // Es una empresa extranjera
                cout << "Nombre: " << extranjera->getNombreFantasia() << endl;
            }
           
          }
          break;
        case 2:
          for (int i = 0; i < cantEmpleados; i++) {
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "CI: " << empleados[i]->getCi() << endl;
            cout << "Nombre: " << empleados[i]->getNombre() << " " << empleados[i]->getApellido() << endl;
            cout << "Direccion: " << empleados[i]->getDireccion().getCalle() << " " << empleados[i]->getDireccion().getNumero() << " " << empleados[i]->getDireccion().getCiudad() << endl;
          }
          break;
        case 3:
          for (int i = 0; i < cantRelacionesLaborales; i++) {
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "CI: " << relacionesLaborales[i]->getCiEmpleado() << endl;
            cout << "ID: " << relacionesLaborales[i]->getIdEmpresa() << endl;
            cout << "Sueldo: " << relacionesLaborales[i]->getSueldoLiquido() << endl;
          }
          break;
      }
    }
};



Direccion newDireccion(string calle, int num, string ciu) {
  if ((calle == "") || (ciu == "")) {      
    throw invalid_argument("Esta direccion no es valida.");
  }
  return Direccion(calle, num, ciu);
}

Fecha newFecha(int dia, int mes, int anio) {
  // Para las fechas en caso de recibir dd > 31 o dd < 1 o mm > 12 o mm < 1 o aaaa < 1900, se debe levantar la excepcion std::invalid_argument.
  if ((dia < 1 || dia > 31) || (mes < 1 || mes > 12) || (anio < 1900) || (mes == 2 && dia > 29)){
    if (dia != 0 && mes != 0 && anio != 0) {
      throw std::invalid_argument("Esta fecha no es valida.");
    }
  }
  
  return Fecha(dia, mes, anio);
}



int main() {

  Direccion dir1 = newDireccion("Calle 1", 1234, "Montevideo");
  Direccion dir2 = newDireccion("Calle 321", 1234, "Nueva York");

  Fecha fecha1 = newFecha(8, 2, 2003); // <-- Viejo arrugado
  Fecha fecha2 = newFecha(1, 4, 2003); // <-- El del medio q nadie lo co
  Fecha fecha3 = newFecha(28, 9, 2004); // <-- El mas pendejo

  DtNacional* nacional1 = new DtNacional("1", dir1, "214789"); // <- Primera muerte
  DtNacional* nacional2 = new DtNacional("2", dir1, "03213219");
  DtNacional* nacional3 = new DtNacional("3", dir1, "413432432");

  DtExtranjera* extranjera1 = new DtExtranjera("4", dir2, "COCA COLA");
  DtExtranjera* extranjera2 = new DtExtranjera("5", dir1, "MC DONALDS");
  DtExtranjera* extranjera3 = new DtExtranjera("6", dir1, "HAMBURGUESA KING");

  Sistema* s = new Sistema();
  s->agregarEmpleado("1", "Juan", "Perez", dir1);
  s->agregarEmpleado("2", "Pedro", "Gonzalez", dir1);
  s->agregarEmpleado("3", "Maria", "Rodriguez", dir1);
  s->agregarEmpleado("4", "Ana", "Lopez", dir1);

  s->agregarEmpresa(nacional1);
  s->agregarEmpresa(nacional2);
  s->agregarEmpresa(nacional3);
  s->agregarEmpresa(extranjera1); 
  s->agregarEmpresa(extranjera2);
  s->agregarEmpresa(extranjera3);

  s->agregarRelacionLaboral("1", "1", 1123.513);
  s->agregarRelacionLaboral("2", "2", 420.6987);
  s->agregarRelacionLaboral("3", "3", 45000);
  s->agregarRelacionLaboral("4", "3", 125000);
  s->agregarRelacionLaboral("4", "5", 6000);


  
  try {
    s->agregarRelacionLaboral("1", "1", 1123.513);
  } catch (std::exception& e) {
      std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
  }

  s->finalizarRelacionLaboral("1", "1", fecha1);
  s->agregarRelacionLaboral("1", "1", 1123.513);

  // s->mostrarInfo(1);
  // s->mostrarInfo(2);
  // s->mostrarInfo(3);  
}