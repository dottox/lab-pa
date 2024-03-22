#include "Persona.h"
#include "Gato.h"
#include "Perro.h"
#include "Animal.h"
#include "Veterinaria.h"


int main() {
    Veterinaria* vet = new Veterinaria("Veterinaria de la esquina");

    Persona * p1 = new Persona("Alan");
    Persona * p2 = new Persona("Ana");
    Persona * p3 = new Persona("Carlos");
    Persona * p4 = new Persona("Maria");
    Persona * p5 = new Persona("Juan");
    Persona * p6 = new Persona("Laura");
    Persona * p7 = new Persona("Pedro");
    Persona * p8 = new Persona("Sofia");
    Persona * p9 = new Persona("Diego");
    Persona * p10 = new Persona("Valentina");
    Persona * p11 = new Persona("Luis");
    Persona * p12 = new Persona("Camila");

    cout << endl;
    cout << endl;

    vet->agregarSocio(p1);
    vet->agregarSocio(p2);
    vet->agregarSocio(p3);
    vet->agregarSocio(p4);
    vet->agregarSocio(p5);
    vet->agregarSocio(p6);
    vet->agregarSocio(p7);
    vet->agregarSocio(p8);
    vet->agregarSocio(p9);
    vet->agregarSocio(p10);
    vet->agregarSocio(p11);
    vet->agregarSocio(p12);

    cout << endl;
    cout << endl;


    Animal * a1 = new Perro("Panda");
    Animal * a2 = new Gato("Chobi");
    Animal * a3 = new Perro("Max");
    Animal * a4 = new Gato("Luna");
    Animal * a5 = new Perro("Rocky");
    Animal * a6 = new Gato("Milo");
    Animal * a7 = new Perro("Buddy");
    Animal * a8 = new Gato("Simba");
    Animal * a9 = new Perro("Charlie");
    Animal * a10 = new Gato("Lucy");
    Animal * a11 = new Perro("Cooper");
    Animal * a12 = new Gato("Bella");

    cout << endl;

    a8->alimentar();
    a8->alimentar();
    a8->alimentar();
    a8->alimentar();
    a8->alimentar();

    cout << endl;
    cout << endl;


    vet->agregarAnimal(a1); // Agregar a Panda

    vet->agregarAnimal(a2); // Agregar a Chobi
    vet->adoptar(a2, p1); // Alan adoptó a Chobi

    vet->agregarAnimal(a3); // Agregar a Max
    vet->adoptar(a3, p6); // Laura adoptó a Max

    // No deberia funcionar, animal no está en la vete
    vet->adoptar(a4, p3); // Carlos adoptó a Luna

    vet->agregarAnimal(a5); // Agregar a Rocky
    vet->adoptar(a5, p4); // Maria adoptó a Rocky

    vet->agregarAnimal(a6); // Agregar a Milo
    vet->adoptar(a6, p5); // Juan adoptó a Milo

    vet->agregarAnimal(a7); // Agregar a Buddy
    vet->adoptar(a7, p8); // Sofia adoptó a Buddy

    vet->agregarAnimal(a8); // Agregar a Simba
    vet->adoptar(a8, p7); // Pedro adoptó a Simba

    cout << endl;
    cout << endl;

    vet->internar(a3); // Internar a Max
    vet->internar(a4); // Internar a Luna
    
    vet->internar(a5); // Internar a Rocky
    vet->internar(a5); // No se puede internar porque ya está internado

    vet->internar(a6); // Internar a Milo
    vet->internar(a7); // Internar a Buddy
    vet->internar(a8); // No se puede internar porque no hay espacio.

    vet->darDeAlta(a3); // Hacer espacio

    vet->internar(a8); // AHORA SI

    vet->imprimirAnimales();

    cout << endl;
    cout << endl;

    vet->darDeAlta(a4);
    vet->internar(a1);

    vet->imprimirAnimales();


    vet->eliminarSocio(p1);
    vet->eliminarSocio(p2);
    vet->eliminarSocio(p6);

    vet->imprimirAnimalesPorSocio();

    return 0;
}
