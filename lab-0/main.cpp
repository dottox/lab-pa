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
      cout << "Sistema eliminado correctamente." << endl;
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
      // 1. Si empleado existe
      if (buscarEmpleado(ciEmpleado) == NULL) {
        throw invalid_argument("El empleado '" + ciEmpleado + "' no existe");
      }

      // 2. Si empresa existe
      if (buscarEmpresa(idEmpresa) == NULL) {
        throw invalid_argument("La empresa con id '" + idEmpresa + "' no existe");
      }
      
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
        throw invalid_argument("La empresa ya existe");
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
        throw invalid_argument("El empleado '" + ci + "' ya existe");
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

      // 1. Si el empleado ya trabaja  en la empresa
      if (buscarRelacionLaboral(ciEmpleado, idEmpresa) != NULL) {
        throw invalid_argument("El empleado '" + ciEmpleado + "' ya trabaja en la empresa '" + idEmpresa + "'");
      }

      // 2. Si rel lab no está lleno
      if (relacionesLaboralesIsFull()) {
        throw invalid_argument("No se pueden agregar mas relaciones laborales");
      }

      // Endpoint: Agregar la relacion laboral
      Empleado* empleado = buscarEmpleado(ciEmpleado);
      Empresa* empresa = buscarEmpresa(idEmpresa);
      Fecha f = Fecha(0, 0, 0);
      RelacionLaboral* rl = new RelacionLaboral(empresa, empleado, sueldo, f);
      relacionesLaborales[cantRelacionesLaborales++] = rl;
    }
    
    void finalizarRelacionLaboral(string ciEmpleado, string idEmpresa, Fecha desvinculacion) {
      
      // 1. Si el empleado no trabaja en la empresa
      RelacionLaboral* rl = buscarRelacionLaboral(ciEmpleado, idEmpresa);
      if (rl == NULL) {
        throw invalid_argument("El empleado '" + ciEmpleado + "' no ha trabajado en la empresa '" + idEmpresa + "'");
      }

      //2. Si el empleado ya fue desvinculado
      if (rl->getFechaDesvinculacion().getDia() != 0 && rl->getFechaDesvinculacion().getMes() != 0 && rl->getFechaDesvinculacion().getAnio() != 0) {
        throw invalid_argument("El empleado '" + ciEmpleado + "' ya fue desvinculado de la empresa '" + idEmpresa + "'");
      } 

      // Endpoint: Actualizar la fecha de desvinculacion
      rl->setFechaDesvinculacion(desvinculacion);
      return;
    }

  // Retorna un arreglo con las empresas donde trabaja activamente el empleado. 
  // El largo del arreglo de empresas está dado por el parámetro cantEmpresas.
      DtEmpresa** obtenerInfoEmpresaPorEmpleado(string ciEmpleado, int cantEmpres) {
       // 1. Si empleado existe.
      if (buscarEmpleado(ciEmpleado) == NULL) {
        throw invalid_argument("El empleado '" + ciEmpleado +"' no existe");
      }
      
      // 2. Coommprpbar que cantEmpres sea mayor a 0 y menor a cantEmpresas
      if (cantEmpres <= 0 || cantEmpres > cantEmpresas) {
        throw invalid_argument("El valor de '" + to_string(cantEmpres) + "' no es valido");      }
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

      return empresas;

    }
    
    void mostrarInfo(int i){
      switch (i) {
        case 1:
          for (int i = 0; i < cantEmpresas; i++) {
            cout << "--------------------------------------------------------------------------------" << endl;
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
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "CI: " << empleados[i]->getCi() << endl;
            cout << "Nombre: " << empleados[i]->getNombre() << " " << empleados[i]->getApellido() << endl;
            cout << "Direccion: " << empleados[i]->getDireccion().getCalle() << " " << empleados[i]->getDireccion().getNumero() << " " << empleados[i]->getDireccion().getCiudad() << endl;
          }
          break;
        case 3:
          for (int i = 0; i < cantRelacionesLaborales; i++) {
            cout << "--------------------------------------------------------------------------------" << endl;
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
    throw invalid_argument("La direccion " + calle + ", " + to_string(num) + ", " + ciu + " no es valida.");
  }
  return Direccion(calle, num, ciu);
}

Fecha newFecha(int dia, int mes, int anio) {
  // Para las fechas en caso de recibir dd > 31 o dd < 1 o mm > 12 o mm < 1 o aaaa < 1900, se debe levantar la excepcion std::invalid_argument.
  if ((dia < 1 || dia > 31) || (mes < 1 || mes > 12) || (anio < 1900) || (mes == 2 && dia > 29)){
    if (dia != 0 && mes != 0 && anio != 0) {
      throw std::invalid_argument("La fecha " + to_string(dia) + "-" + to_string(mes) + "-" + to_string(anio) + " no es valida.");
    }
  }
  
  return Fecha(dia, mes, anio);
}


void TestCases(Sistema* &s) {

  Fecha fecha1 = newFecha(8, 2, 2003);
  Direccion dir1 = newDireccion("Calle 1", 87, "San Jose");

  
  /* TESTCASE DE AGREGAR EMPLEADO */
  try {
    s->agregarEmpleado("12313", "Juan", "Perez", dir1);
    s->agregarEmpleado("12313", "Pedro", "Gonzalez", dir1);
  } catch (exception& e) {
    cerr << "Se ha producido una excepcion: " << e.what() << endl;
  }
  
  /* TESTCASE DE AGREGAR EMPRESA */
  try { // Agregar la misma empresa dos veces
    DtNacional* nacional1 = new DtNacional("1", dir1, "214789");
    DtNacional* nacional2 = new DtNacional("1", dir1, "214789");
    s->agregarEmpresa(nacional1);
    s->agregarEmpresa(nacional2);
  } catch (exception& e) {
    cerr << "Se ha producido una excepcion: " << e.what() << endl;
  }
  
  /* TESTCASE DE AGREGAR RELACION LABORAL*/
  try { // Agregar dos relaciones laborles iguales
    s->agregarRelacionLaboral("1", "1", 1123.513);
    s->agregarRelacionLaboral("1", "1", 1123.513);
  } catch (exception& e) {
      cerr << "Se ha producido una excepcion: " << e.what() << endl;
  }

  try { // Agregar a un empleado que no exista
    s->agregarRelacionLaboral("0", "1", 1123.513); // <- El error
  } catch (exception& e) {
      cerr << "Se ha producido una excepcion: " << e.what() << endl;
  }
  
  try { // Agregar a un empresa que no exista
    s->agregarRelacionLaboral("1", "0", 1123.513); // <- El error
  } catch (exception& e) {
      cerr << "Se ha producido una excepcion: " << e.what() << endl;
  }

  /* TESTCASE DE FINALIZAR RELACION LABORAL */


  try { // Cuando no existe empleado
    DtNacional* mynesRL1 = new DtNacional("41411", newDireccion("Calle 1", 87, "San Jose"), "214789");
    s->agregarEmpresa(mynesRL1);
    s->finalizarRelacionLaboral("41411", "0", fecha1); 
  } catch (exception& e) {
      cerr << "Se ha producido una excepcion: " << e.what() << endl;
  }

  try { // Cuando no existe empresa
    s->agregarEmpleado("41412", "Juan", "Perez", dir1);
    s->finalizarRelacionLaboral("41412", "0", fecha1); 
  } catch (exception& e) {
      cerr << "Se ha producido una excepcion: " << e.what() << endl;
  }
  
  try{ // Finalizar una relacion laboral que no exista
    s->agregarEmpleado("145", "Juan", "Perez", dir1);
    DtNacional* mynesRL2 = new DtNacional("145", newDireccion("Calle 1", 87, "San Jose"), "214789");
    s->agregarEmpresa(mynesRL2);
    s->finalizarRelacionLaboral("145", "145", fecha1); 
  } catch (exception& e) {
      cerr << "Se ha producido una excepcion: " << e.what() << endl;
  }

  try { // Finalizar una relacion laboral ya finalizada
    s->agregarEmpleado("987", "Juan", "Perez", dir1);
    DtNacional* mynesRL3 = new DtNacional("848", newDireccion("Calle 1", 87, "San Jose"), "214789");
    s->agregarEmpresa(mynesRL3);
    s->agregarRelacionLaboral("848", "987", 1123.513);
    s->finalizarRelacionLaboral("848", "987", fecha1);
    s->finalizarRelacionLaboral("848", "987", fecha1);
  } catch (exception& e) {
      cerr << "Se ha producido una excepcion: " << e.what() << endl;
  }
  
  /* TESTCASE DE OBTENER INFO EMPRESA POR EMPLEADO */
  try { // Buscar empleado que no exista
    s->obtenerInfoEmpresaPorEmpleado("99", 5);
  } catch (exception& e) {
      cerr << "Se ha producido una excepcion: " << e.what() << endl;
  }

  try { // Si el cant de empresas es menor a 0 o mayor a cantEmpresas
    s->agregarEmpleado("9999", "Juan", "Perez", dir1);
    s->obtenerInfoEmpresaPorEmpleado("9999", 1);
  } catch (exception& e) {
      cerr << "Se ha producido una excepcion: " << e.what() << endl;
  }

  /* TEST DE FECHA */
  try { // Fecha invalida
    Fecha fecha2 = newFecha(32, 2, 2003);
  } catch (exception& e) {
      cerr << "Se ha producido una excepcion: " << e.what() << endl;
  }
  
}


int main() {

  Sistema* s = new Sistema(); // <- Sistema God

  TestCases(s);
  // Direccion dir1 = newDireccion("Calle 1", 1234, "Montevideo");
  // Direccion dir2 = newDireccion("Calle 321", 1234, "Nueva York");
  
  
  // Fecha fecha1 = newFecha(8, 2, 2003); // <-- Viejo arrugado
  // Fecha fecha2 = newFecha(1, 4, 2003); // <-- El del medio q nadie lo co
  // Fecha fecha3 = newFecha(28, 9, 2004); // <-- El mas pendejo

  // DtNacional* nacional1 = new DtNacional("1", dir1, "214789"); // <- Primera muerte
  // DtNacional* nacional2 = new DtNacional("2", dir1, "03213219");
  // DtNacional* nacional3 = new DtNacional("3", dir1, "413432432");

  // DtExtranjera* extranjera1 = new DtExtranjera("4", dir2, "COCA COLA");
  // DtExtranjera* extranjera2 = new DtExtranjera("5", dir1, "MC DONALDS");
  // DtExtranjera* extranjera3 = new DtExtranjera("6", dir1, "HAMBURGUESA KING");


  // s->agregarEmpleado("1", "Juan", "Perez", dir1);
  // s->agregarEmpleado("2", "Pedro", "Gonzalez", dir1);
  // s->agregarEmpleado("3", "Maria", "Rodriguez", dir1);
  // s->agregarEmpleado("4", "Ana", "Lopez", dir1);


  // s->agregarRelacionLaboral("1", "1", 1123.513);
  // s->agregarRelacionLaboral("2", "2", 420.6987);
  // s->agregarRelacionLaboral("3", "3", 45000);
  // s->agregarRelacionLaboral("4", "3", 125000);
  // s->agregarRelacionLaboral("4", "5", 6000);



  // Para mostrar empresas: i = 1
  // Para mostrar empleados: i = 2
  // Para mostrar rel. lab.: i = 3
  // Para ver algo ultra gracioso: i = 4

  delete s;

  return 0;
}