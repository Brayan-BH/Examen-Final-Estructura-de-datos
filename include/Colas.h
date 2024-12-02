#ifndef COLAS_H
#define COLAS_H

#include "Estructuras.h"
#include <iostream>
using namespace std;

// Nodo para la cola de luchadores
struct NodoCola {
    Luchador luchador;
    NodoCola* siguiente;
};

// Cola de luchadores
struct Cola {
    NodoCola* frente;
    NodoCola* final;
};

// Inicializar la cola
void inicializarCola(Cola& cola) {
    cola.frente = cola.final = nullptr;
}

// Encolar un luchador
void encolar(Cola& cola, Luchador luchador) {
    NodoCola* nuevo = new NodoCola{luchador, nullptr};
    if (!cola.final) {
        cola.frente = cola.final = nuevo;
    } else {
        cola.final->siguiente = nuevo;
        cola.final = nuevo;
    }
}

// Desencolar un luchador
Luchador desencolar(Cola& cola) {
    if (!cola.frente) {
        cerr << "Cola vacía.\n";
        exit(1);
    }
    NodoCola* temp = cola.frente;
    Luchador luchador = temp->luchador;
    cola.frente = cola.frente->siguiente;
    if (!cola.frente) cola.final = nullptr;
    delete temp;
    return luchador;
}

// Mostrar cola de luchadores con índices
void mostrarCola(Cola& cola) {
    NodoCola* actual = cola.frente;
    int index = 0; // Variable para llevar el índice

    if (!actual) {
        cout << "Cola vacía.\n";
        return;
    }

    while (actual) {
        cout << "[" << index << "] Luchador: " << actual->luchador.nombre
             << " | Poder: " << actual->luchador.poder << '\n';
        actual = actual->siguiente;
        index++; // Incrementar el índice para el siguiente luchador
    }
}


#endif // COLAS_H
