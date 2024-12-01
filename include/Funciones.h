#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Estructuras.h"
#include "Pilas.h"
#include "Colas.h"
#include "Arboles.h"
#include <iostream>
#include <cstring>
#include <cctype>

// Validación de un campo alfabético
void validarCampoAlfabetico(char* campo, int tam) {
    do {
        std::cout << "Ingrese un valor (solo letras): ";
        std::cin.getline(campo, tam);
        bool esValido = true;
        for (int i = 0; i < strlen(campo); i++) {
            if (!isalpha(campo[i]) && campo[i] != ' ') {
                esValido = false;
                break;
            }
        }
        if (esValido) break;
        std::cout << "Entrada inválida. Intente de nuevo.\n";
    } while (true);
}

// Validación de un entero positivo
int validarEnteroPositivo(const char* mensaje) {
    int valor;
    do {
        std::cout << mensaje;
        std::cin >> valor;
        if (valor > 0) return valor;
        std::cout << "Debe ingresar un número positivo.\n";
    } while (true);
}

// Validación de un número flotante positivo
float validarFloatPositivo(const char* mensaje) {
    float valor;
    do {
        std::cout << mensaje;
        std::cin >> valor;
        if (valor > 0) return valor;
        std::cout << "Debe ingresar un número positivo.\n";
    } while (true);
}

// Registrar un universo
Universo registrarUniverso(int id) {
    Universo universo;
    universo.id = id;

    std::cout << "Nombre del Universo: ";
    std::cin.ignore();  // Limpiar el buffer de entrada antes de leer el nombre
    validarCampoAlfabetico(universo.nombre, 30);

    // Cambiar validación para que sea solo un número entero positivo
    universo.cantidadLuchadores = validarEnteroPositivo("Cantidad de Luchadores: ");

    universo.poderTotal = validarFloatPositivo("Poder Total del Universo: ");

    std::cout << "Nombre del Dios del Universo: ";
    std::cin.ignore();  // Limpiar el buffer antes de leer el nombre del Dios
    validarCampoAlfabetico(universo.dios, 30);

    std::cout << "Nombre del Ángel del Universo: ";
    std::cin.ignore();  // Limpiar el buffer antes de leer el nombre del Ángel
    validarCampoAlfabetico(universo.angel, 30);

    universo.luchadores = new Luchador[universo.cantidadLuchadores];
    for (int i = 0; i < universo.cantidadLuchadores; ++i) {
        std::cout << "Luchador " << i + 1 << ":\n";
        std::cout << "Nombre: ";
        std::cin.ignore();  // Limpiar el buffer antes de leer el nombre del luchador
        validarCampoAlfabetico(universo.luchadores[i].nombre, 30);
        universo.luchadores[i].poder = validarFloatPositivo("Poder: ");
        universo.luchadores[i].edad = validarEnteroPositivo("Edad: ");
        universo.luchadores[i].estatura = validarFloatPositivo("Estatura (en metros): ");
        std::cout << "Raza: ";
        std::cin.ignore();  // Limpiar el buffer antes de leer la raza
        validarCampoAlfabetico(universo.luchadores[i].raza, 20);
    }

    return universo;
}

// Eliminar luchadores y apilarlos
void eliminarLuchador(NodoPilaLuchador*& pila, Universo& universo, int index) {
    if (index < 0 || index >= universo.cantidadLuchadores) {
        std::cout << "Índice de luchador inválido.\n";
        return;
    }

    pushPilaLuchador(pila, universo.luchadores[index]);
    for (int i = index; i < universo.cantidadLuchadores - 1; ++i) {
        universo.luchadores[i] = universo.luchadores[i + 1];
    }
    --universo.cantidadLuchadores;
    std::cout << "Luchador eliminado y apilado.\n";
}

// Liberar memoria dinámica
void liberarMemoria(Universo& universo) {
    delete[] universo.luchadores;
}

// Mostrar y vaciar pila de luchadores eliminados
void vaciarPilaLuchadores(NodoPilaLuchador*& pila) {
    while (pila) {
        Luchador eliminado = popPilaLuchador(pila);
        std::cout << "Luchador eliminado de la pila: " << eliminado.nombre << '\n';
    }
}

// Mostrar universos por poder en orden jerárquico (árbol)
void mostrarUniversosPorPoder(NodoArbol* arbol) {
    std::cout << "Universos ordenados por poder total:\n";
    mostrarArbol(arbol);
}

#endif // FUNCIONES_H
