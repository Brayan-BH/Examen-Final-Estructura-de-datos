#ifndef PILAS_H
#define PILAS_H

#include "Estructuras.h"
#include <iostream>

// Nodo para la pila de luchadores
struct NodoPilaLuchador {
    Luchador luchador;
    NodoPilaLuchador* siguiente;
};

// Nodo para la pila de universos
struct NodoPilaUniverso {
    Universo universo;
    NodoPilaUniverso* siguiente;
};

// Funciones para la pila de luchadores
void pushPilaLuchador(NodoPilaLuchador*& pila, Luchador luchador) {
    NodoPilaLuchador* nuevo = new NodoPilaLuchador{luchador, pila};
    pila = nuevo;
}

Luchador popPilaLuchador(NodoPilaLuchador*& pila) {
    if (!pila) {
        std::cerr << "Pila vacía.\n";
        exit(1);
    }
    NodoPilaLuchador* temp = pila;
    Luchador luchador = temp->luchador;
    pila = pila->siguiente;
    delete temp;
    return luchador;
}

void mostrarPilaLuchadores(NodoPilaLuchador* pila) {
    if (!pila) {
        std::cout << "Pila vacía.\n";
        return;
    }
    while (pila) {
        std::cout << "Luchador: " << pila->luchador.nombre
                  << " | Poder: " << pila->luchador.poder << '\n';
        pila = pila->siguiente;
    }
}

// Funciones para la pila de universos
void pushPilaUniverso(NodoPilaUniverso*& pila, Universo universo) {
    NodoPilaUniverso* nuevo = new NodoPilaUniverso{universo, pila};
    pila = nuevo;
}

Universo popPilaUniverso(NodoPilaUniverso*& pila) {
    if (!pila) {
        std::cerr << "Pila vacía.\n";
        exit(1);
    }
    NodoPilaUniverso* temp = pila;
    Universo universo = temp->universo;
    pila = pila->siguiente;
    delete temp;
    return universo;
}

void mostrarPilaUniversos(NodoPilaUniverso* pila) {
    if (!pila) {
        std::cout << "Pila vacía.\n";
        return;
    }
    while (pila) {
        std::cout << "Universo: " << pila->universo.nombre
                  << " | Poder Total: " << pila->universo.poderTotal << '\n';
        pila = pila->siguiente;
    }
}

#endif // PILAS_H
