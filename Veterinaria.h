#ifndef VETERINARIA_H
#define VETERINARIA_H
#include "Animal.h"
#include "Persona.h"


#define MAX_ANIMALES 100
#define MAX_INTERNADOS 5
#define MAX_SOCIOS 100

class Persona;
class Animal;

class Veterinaria
{
    public:
        Veterinaria(string); // string -> nombre de la veterinaria

        void alimentar(Animal *);

        void internar(Animal *);
        void darDeAlta(Animal *);

        void imprimirAnimalesPorSocio();
        void imprimirAnimalesAdoptados();
        void imprimirRegistroAdoptados();
        void imprimirAnimalesInternados();
        void imprimirAnimales();

        void agregarAnimal(Animal *); // Agrega un animal a la veterinaria.	
        void adoptar(Animal *, Persona *); // Solo si el animal está en la veterinaria.
        
        void agregarSocio(Persona *);
        void eliminarSocio(Persona *);

        int getCantAnimalesAdopcion();
        int getCantAnimalesInternados();
        int getcantRegistroAdopcion();
        int getCantAnimales(); // suma de los dos anteriores.
        int getSocios();

        Animal * getAnimal(string); // string -> nombre

    private:
        Animal** animalesAdopcion;
        Animal** registroAdopcion;
        Animal** animalesInternados;
        Persona** socios; // Persona ** asd = new Persona*[MAX_SOCIOS];
        int cantAnimalesAdopcion;
        int cantAnimalesInternados;
        int cantRegistroAdopcion;
        int cantSocios;

        int estaEnLaLista(Animal**, int, Animal*);
        void imprimirLista(Animal**, int, string);
        void quitarAnimal(Animal *);
        void agregarAnimalRegistro(Animal *);

    protected:
        string nombre;
};

#endif