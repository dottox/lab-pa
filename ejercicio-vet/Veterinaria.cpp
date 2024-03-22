#include "Veterinaria.h"
#include <iostream>


Veterinaria::Veterinaria(string nom){
    this->nombre = nom;

    this->animalesAdopcion = new Animal*[MAX_ANIMALES];
    this->registroAdopcion = new Animal*[MAX_ANIMALES];
    this->animalesInternados = new Animal*[MAX_INTERNADOS];

    this->socios = new Persona*[MAX_SOCIOS];

    this->cantAnimalesAdopcion = 0;
    this->cantAnimalesInternados = 0;
    this->cantSocios = 0;
};


/* ---- FUNCIONES DE VETERINARIA ----- */

void Veterinaria::alimentar(Animal* a)
{
    int hambreBefore = a->getHambre();
    a->alimentar();
    int hambreAfter = a->getHambre();

    cout << a->getNombre() << (hambreBefore - hambreAfter == 0) ? " no tenía hambre" : " ha comido 😋";
};

void Veterinaria::imprimirAnimalesAdoptados(){
    int cantA = this->getCantAnimalesAdopcion();
    this->imprimirLista(this->animalesAdopcion, cantA, "ANIMALES ADOPTADOS");
};

void Veterinaria::imprimirRegistroAdoptados() {
    int cantA = this->getcantRegistroAdopcion();
    this->imprimirLista(this->registroAdopcion, cantA, "REGISTRO DE ANIMALES ADOPTADOS");
};


void Veterinaria::imprimirAnimalesInternados(){
    int cantA = this->getCantAnimalesInternados();
    this->imprimirLista(this->animalesInternados, cantA, "ANIMALES INTERNADOS");
};

void Veterinaria::imprimirAnimales(){
    imprimirAnimalesAdoptados();
    imprimirAnimalesInternados();
    imprimirRegistroAdoptados();
    cout << endl;
};
/* ----------------------------------- */

/* ---- FUNCION DE ANIMALES ----*/

void Veterinaria::agregarAnimal(Animal* a){
    int cantA = this->getCantAnimalesAdopcion();
    int index = estaEnLaLista(this->animalesAdopcion, cantA, a);
    if (index == -1) {
        if (cantA < MAX_ANIMALES) {
            this->animalesAdopcion[cantA] = a;
            this->cantAnimalesAdopcion++;
            
            if (estaEnLaLista(this->registroAdopcion, this->getcantRegistroAdopcion(), a) == -1) 
                this->agregarAnimalRegistro(a);

            cout << "El animal " << a->getNombre() << " ha sido agregado correctamente" << endl;
        } else {
            cout << "Error: No se pueden agregar mas animales, la capacidad esta completa." << endl;
        }
    } else {
        cout << "Error: El animal " << a->getNombre() << " ya se encuentra en la lista." << endl;
    }
};

void Veterinaria::adoptar(Animal* a, Persona* p){
    int cantA = this->getCantAnimalesAdopcion();
    int index = estaEnLaLista(this->animalesAdopcion, cantA, a);
    if(index != -1){
        this->animalesAdopcion[index] = this->animalesAdopcion[cantA - 1]; // Reemplaza el animal a dar de alta
        this->cantAnimalesAdopcion--;
        p->agregarMascota(a); 
        a->agregarPersona(p);
        cout << p->getNombre() << " adopto a " << a->getNombre() << ".\n";
    } else{
        cout << "No existe tal animal, animal." << endl;
    }
};


/* ---- FUNCIONES DE SOCIO ----- */
void Veterinaria::agregarSocio(Persona* p){
    int cantS = this->getSocios();
    if (cantS < MAX_SOCIOS) {
        this->socios[cantS] = p;
        this->cantSocios++;
        cout << "El socio " << p->getNombre() << " ha sido agregado correctamente" << endl;
    }
};

void Veterinaria::eliminarSocio(Persona* p){
    int cantS = this->getSocios();
    for (int i = 0; i < cantS; i++) {
        if (this->socios[i] == p) {
            cout << "El socio " << p->getNombre() << " ha sido eliminado correctamente" << endl;
            this->socios[i] = this->socios[cantS - 1]; 
            this->cantSocios--;
        }
    }
};

void Veterinaria::imprimirAnimalesPorSocio() {
    for (int i = 0; i < this->getSocios(); i++) {
        cout << "Nombre del socio: " << this->socios[i]->getNombre() << endl;
        if (this->socios[i]->getMascota() != NULL) {
            this->socios[i]->getMascota()->imprimir();
            cout << endl;
        } else {
            cout << "No tiene mascota." << endl << endl;
        }
    }
};

/* ----------------------------------- */


/* ---- FUNCIONES DE INTERNAR Y DAR DE ALTA ---- */
void Veterinaria::internar(Animal * a){
    int inter = this->getCantAnimalesInternados();

    int internado = estaEnLaLista(this->animalesInternados, inter, a);
    int adoptado = estaEnLaLista(this->animalesAdopcion, this->getCantAnimalesAdopcion(), a);
    
    if(internado == -1){
        if (inter < MAX_INTERNADOS) {
            if (adoptado != -1) quitarAnimal(a);
            this->animalesInternados[inter] = a; // ah no, no deberìa. Si no hay animales (inter == 0); lo tiene que agregar en la pos 0.
            this->cantAnimalesInternados++;
            cout << "La mascota " << a->getNombre() << " ha sido internada." << endl;
        } else {
            cout << "Error: No se pueden internar mas animales, la capacidad esta completa." << endl;
        }
    }else{
        cout << "Para master, esta mascota ya esta internada." << endl;
    }
};

void Veterinaria::darDeAlta(Animal * a){
    int cantA = this->getCantAnimalesInternados();
    int index = estaEnLaLista(this->animalesInternados, cantA, a);
    if(index != -1){
        this->agregarAnimal(a);
        this->animalesInternados[index] = this->animalesInternados[cantA - 1]; // Reemplaza el animal a dar de alta
        this->cantAnimalesInternados--;
    } else {
        cout << "No existe tal animal para dar de alta, animal." << endl;
    }
}

/* ----- GETTERS ----- */

int Veterinaria::getCantAnimalesAdopcion(){
    return this->cantAnimalesAdopcion;
};

int Veterinaria::getCantAnimalesInternados(){
    return this->cantAnimalesInternados;
};

int Veterinaria::getCantAnimales(){
    return this->cantAnimalesAdopcion + this->cantAnimalesInternados;
};

int Veterinaria::getSocios(){
    return this->cantSocios;
};

int Veterinaria::getcantRegistroAdopcion(){
    return this->cantRegistroAdopcion;
};
/* ------------------- */


int Veterinaria::estaEnLaLista(Animal** lista, int size, Animal* animal){
    for (int i = 0; i < size; i++) {
        if (lista[i] == animal) { 
            return i; // Devuelve el animal
        }
    }
    return -1;
}

void Veterinaria::imprimirLista(Animal** lista, int size, string nombreLista){
    cout << endl << " --- " << nombreLista << " ---" << endl;
    if (size == 0) {
        cout << "No hay animales en la lista." << endl;
    } else {
        for (int i = 0; i < size; i++) {
            cout << "Nombre de la mascota : " << lista[i]->getNombre() << endl;
        }
    }
}

void Veterinaria::quitarAnimal(Animal * a){
    int cantA = this->getCantAnimalesAdopcion();
    int index = estaEnLaLista(this->animalesAdopcion, cantA, a);
    if(index != -1){
        // No falta un delete aquí? 
        this->animalesAdopcion[index] = this->animalesAdopcion[cantA - 1]; // Reemplaza el animal a dar de alta
        this->cantAnimalesAdopcion--;
    } else {
        cout << "No existe tal animal para desadoptar, animal." << endl;
    }
}

void Veterinaria::agregarAnimalRegistro(Animal * a){
    int cantA = this->getcantRegistroAdopcion();
    if (cantA < MAX_ANIMALES) {
        this->registroAdopcion[cantA] = a;
        this->cantRegistroAdopcion++;
    } else {
        cout << "Error: No se pueden agregar mas animales al registro, la capacidad esta completa." << endl;
    }
}