#ifndef PILAS_H
#define PILAS_H

#include "Estructuras.h"
#include <iostream>
using namespace std;
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
        cerr << "Pila vacía.\n";
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
        cout << "Pila vacía.\n";
        return;
    }
    while (pila) {
        cout << "Luchador: " << pila->luchador.nombre
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
        cerr << "Pila vacía.\n";
        exit(1);
    }
    NodoPilaUniverso* temp = pila;
    Universo universo = temp->universo;
    pila = pila->siguiente;
    delete temp;
    return universo;
}

// Eliminar luchadores y apilarlos
void eliminarLuchador(NodoPilaLuchador*& pila, Universo& universo, int index) {
    if (index < 0 || index >= universo.cantidadLuchadores) {
        cout << "Índice de luchador inválido.\n";
        return;
    }

    pushPilaLuchador(pila, universo.luchadores[index]);
    for (int i = index; i < universo.cantidadLuchadores - 1; ++i) {
        universo.luchadores[i] = universo.luchadores[i + 1];
    }
    --universo.cantidadLuchadores;
    cout << "Luchador eliminado y apilado.\n";
}

// Mostrar y vaciar pila de luchadores eliminados
void vaciarPilaLuchadores(NodoPilaLuchador*& pila) {
    while (pila) {
        Luchador eliminado = popPilaLuchador(pila);
        cout << "Luchador eliminado de la pila: " << eliminado.nombre << '\n';
    }
}


void mostrarPilaUniversos(NodoPilaUniverso* pila) {
    if (!pila) {
        cout << "Pila vacía.\n";
        return;
    }
    while (pila) {
        cout << "Universo: " << pila->universo.nombre
                  << " | Poder Total: " << pila->universo.poderTotal << '\n';
        pila = pila->siguiente;
    }
}


#endif // PILAS_H
