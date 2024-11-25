#include <iostream>
#include "Luchador.h" // Asegúrate de que este archivo esté correctamente definido
using namespace std;

// Estructura de la pila
struct Pila {
    Luchador luchador;
    Pila *sig;
};

// Declaración de prototipos
void apilar(Pila *&pila);
void registrar(Pila *&nuevo);
void mostrar(Pila *pila);
void desapilar(Pila *&pila);

// Definición de funciones
void apilar(Pila *&pila) {
    Pila *nuevo = new Pila;
    registrar(nuevo);
    nuevo->sig = pila;
    pila = nuevo;
    return;
}

void registrar(Pila *&nuevo) {
    cin.ignore();
    cout << "Ingrese el nombre del luchador: " << endl;
    cin.getline(nuevo->luchador.nombre, 50);
    cout << "Ingrese la fuerza del luchador: " << endl;
    cin >> nuevo->luchador.fuerza;
    cout << "Ingrese el poder del luchador: " << endl;
    cin >> nuevo->luchador.poder;
    cout << "Ingrese la estatura del luchador: " << endl;
    cin >> nuevo->luchador.estatura;
    cout << "Ingrese el peso del luchador: " << endl;
    cin >> nuevo->luchador.peso;
    cin.ignore();
    cout << endl;
    return;
}

void mostrar(Pila *pila) {
    Pila *aux = pila;
    while (aux != NULL) {
        cout << "Nombre: " << aux->luchador.nombre << endl;
        cout << "Fuerza: " << aux->luchador.fuerza << endl;
        cout << "Poder: " << aux->luchador.poder << endl;
        cout << "Estatura: " << aux->luchador.estatura << endl;
        cout << "Peso: " << aux->luchador.peso << endl;
        cout << endl;
        aux = aux->sig;
    }
    return;
}

void desapilar(Pila *&pila) {
    Pila *aux = pila;
    pila = pila->sig;
    delete aux;
    return;
}
