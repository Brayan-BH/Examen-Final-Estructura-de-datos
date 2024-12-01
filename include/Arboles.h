#ifndef ARBOLES_H
#define ARBOLES_H

#include "Estructuras.h"
#include <iostream>

// Nodo del árbol
struct NodoArbol {
    Universo universo;
    NodoArbol* izquierda;
    NodoArbol* derecha;
};

// Insertar en el árbol
NodoArbol* insertarArbol(NodoArbol* raiz, Universo universo) {
    if (!raiz) {
        return new NodoArbol{universo, nullptr, nullptr};
    }
    if (universo.poderTotal < raiz->universo.poderTotal) {
        raiz->izquierda = insertarArbol(raiz->izquierda, universo);
    } else {
        raiz->derecha = insertarArbol(raiz->derecha, universo);
    }
    return raiz;
}

// Mostrar árbol en orden
void mostrarArbol(NodoArbol* raiz) {
    if (!raiz) return;
    mostrarArbol(raiz->izquierda);
    std::cout << "Universo: " << raiz->universo.nombre
              << " | Poder Total: " << raiz->universo.poderTotal << '\n';
    mostrarArbol(raiz->derecha);
}

#endif // ARBOLES_H
