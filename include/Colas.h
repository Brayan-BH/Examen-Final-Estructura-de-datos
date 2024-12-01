#ifndef COLAS_H
#define COLAS_H

#include "Estructuras.h"
#include <iostream>

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
        std::cerr << "Cola vacía.\n";
        exit(1);
    }
    NodoCola* temp = cola.frente;
    Luchador luchador = temp->luchador;
    cola.frente = cola.frente->siguiente;
    if (!cola.frente) cola.final = nullptr;
    delete temp;
    return luchador;
}

// Mostrar cola de luchadores
void mostrarCola(Cola& cola) {
    NodoCola* actual = cola.frente;
    if (!actual) {
        std::cout << "Cola vacía.\n";
        return;
    }
    while (actual) {
        std::cout << "Luchador: " << actual->luchador.nombre
                  << " | Poder: " << actual->luchador.poder << '\n';
        actual = actual->siguiente;
    }
}

#endif // COLAS_H
