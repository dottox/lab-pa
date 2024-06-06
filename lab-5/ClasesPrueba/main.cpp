#include "Factory.h"
#include "ISistema.h"

int main() {
    ISistema * s = Factory::getSistema();
    cout << "soy feliz" << endl;;
    if (s != NULL) {
        s->agregarPersona("Pepito");
        cout << "Nombre del Socio: " << s->getNombreSocio() << endl;
    }
    else
        cout << "El sistema está en NULL  :(" << endl;
    return 0;
}
