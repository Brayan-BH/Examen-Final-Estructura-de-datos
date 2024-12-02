#ifndef ARBOLES_H
#define ARBOLES_H

#include "Estructuras.h"
#include <iostream>
using namespace std;

// Nodo del árbol
struct NodoArbol
{
    Universo universo;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};

// Insertar en el árbol
NodoArbol *insertarArbol(NodoArbol *raiz, Universo universo)
{
    if (!raiz)
    {
        return new NodoArbol{universo, nullptr, nullptr};
    }
    if (universo.poderTotal < raiz->universo.poderTotal)
    {
        raiz->izquierda = insertarArbol(raiz->izquierda, universo);
    }
    else
    {
        raiz->derecha = insertarArbol(raiz->derecha, universo);
    }
    return raiz;
}

// Mostrar árbol en orden con formato y encabezado
void mostrarArbol(NodoArbol *raiz, int nivel = 0, int index = 0)
{
    if (!raiz)
        return;

    // Recorrer subárbol derecho primero (para formato visual de jerarquización)
    mostrarArbol(raiz->derecha, nivel + 1, index);

    // Mostrar nodo actual con indentación según el nivel y el índice
    for (int i = 0; i < nivel; ++i)
    {
        cout << "    "; // Indentación
    }
    cout << "[" << index << "] -> Universo: " << raiz->universo.nombre
         << " | Poder Total: " << raiz->universo.poderTotal << '\n';

    // Recorrer subárbol izquierdo
    mostrarArbol(raiz->izquierda, nivel + 1, index + 1);
}

NodoArbol* buscarArbol(NodoArbol* raiz, int id) {
    if (!raiz) return nullptr;  // Si el árbol está vacío
    if (raiz->universo.id == id) {
        cout << "Universo encontrado: " << raiz->universo.nombre << endl; // Imprimir el nombre del universo
        return raiz;  // Si el ID coincide con el nodo actual
    }
    if (id < raiz->universo.id) {
        return buscarArbol(raiz->izquierda, id);  // Buscar en el subárbol izquierdo
    }
    return buscarArbol(raiz->derecha, id);  // Buscar en el subárbol derecho
}

// Mostrar universos registrados
void mostrarUniversosPorPoder(NodoArbol *raiz)
{
    if (!raiz)
    {
        cout << "No hay universos registrados.\n";
        return;
    }
    mostrarArbol(raiz); // Esta función ya está definida como la que muestra el árbol jerarquizado
}

void gestionarLuchadores(NodoArbol* arbolUniversos, Cola& colaLuchadores) {
    if (!arbolUniversos) {
        cout << "No hay universos registrados.\n";
        return;
    }

    // Mostrar universos registrados con sus ID
    cout << "=== Universos Registrados ===\n";
    mostrarArbol(arbolUniversos); // Mostrar universos jerarquizados

    // Seleccionar un universo por ID
    int idSeleccionado;
    cout << "Ingrese el ID del universo para gestionar luchadores: ";
    cin >> idSeleccionado;

    // Buscar el universo seleccionado usando su ID único
    NodoArbol* nodoSeleccionado = buscarArbol(arbolUniversos, idSeleccionado);
    if (!nodoSeleccionado) {
        cout << "Universo no encontrado.\n";
        return;
    }

    // Acceder a los luchadores del universo seleccionado
    Universo& universoSeleccionado = nodoSeleccionado->universo;
    cout << "Gestionando luchadores del Universo: " << universoSeleccionado.nombre << '\n';

    // Mostrar luchadores de este universo con índices
    for (int i = 0; i < universoSeleccionado.cantidadLuchadores; ++i) {
        cout << "[" << i << "] Luchador: " << universoSeleccionado.luchadores[i].nombre
        << " | Poder: " << universoSeleccionado.luchadores[i].poder << '\n';
    }

    // Encolar un luchador
    int index;
    cout << "Ingrese el índice del luchador a encolar: ";
    cin >> index;

    if (index >= 0 && index < universoSeleccionado.cantidadLuchadores) {
        encolar(colaLuchadores, universoSeleccionado.luchadores[index]);
        cout << "Luchador " << universoSeleccionado.luchadores[index].nombre
            << " encolado correctamente.\n";
    } else {
        cout << "Índice inválido.\n";
    }
}


#endif // ARBOLES_H
