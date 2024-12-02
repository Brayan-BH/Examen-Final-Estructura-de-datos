#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Estructuras.h"
#include "Pilas.h"
#include "Colas.h"
#include "Arboles.h"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Validación de un campo alfabético
void validarCampoAlfabetico(char* campo, int tam) {
    do {
        cout << "Ingrese un valor (solo letras): ";
        cin.getline(campo, tam);
        bool esValido = true;
        for (int i = 0; i < strlen(campo); i++) {
            // Verificar si el carácter no es una letra
            if (!isalpha(campo[i]) && campo[i] != ' ') {
                esValido = false;
                break;
            }
        }
        if (esValido) break;
        cout << "Entrada inválida. Intente de nuevo.\n";
    } while (true);
}

// Validación de un entero positivo
int validarEnteroPositivo(const char* mensaje) {
    int valor;
    do {
        cout << mensaje;
        cin >> valor;
        if (valor > 0) return valor;
        cout << "Debe ingresar un número positivo.\n";
    } while (true);
}

// Validación de un número flotante positivo
float validarFloatPositivo(const char* mensaje) {
    float valor;
    do {
        cout << mensaje;
        cin >> valor;
        if (valor > 0) return valor;
        cout << "Debe ingresar un número positivo.\n";
    } while (true);
}

// Registrar un universo
Universo registrarUniverso(int id) {
    Universo universo;
    universo.id = id;

    cout << "Nombre del Universo: ";
    cin.ignore();  // Limpiar el buffer de entrada antes de leer el nombre
    validarCampoAlfabetico(universo.nombre, 30);

    // Cambiar validación para que sea solo un número entero positivo
    universo.cantidadLuchadores = validarEnteroPositivo("Cantidad de Luchadores: ");

    universo.poderTotal = validarFloatPositivo("Poder Total del Universo: ");

    cout << "Nombre del líder del Universo: ";
    cin.ignore();  // Limpiar el buffer antes de leer el nombre del Dios
    validarCampoAlfabetico(universo.lider, 30);

    cout << "Nombre del Dios del Universo: ";
    cin.ignore();  // Limpiar el buffer antes de leer el nombre del Dios
    validarCampoAlfabetico(universo.dios, 30);

    cout << "Nombre del Ángel del Universo: ";
    cin.ignore();  // Limpiar el buffer antes de leer el nombre del Ángel
    validarCampoAlfabetico(universo.angel, 30);

    universo.luchadores = new Luchador[universo.cantidadLuchadores];
    for (int i = 0; i < universo.cantidadLuchadores; ++i) {
        cout << "Luchador " << i + 1 << ":\n";
        cout << "Nombre: ";
        cin.ignore();  // Limpiar el buffer antes de leer el nombre del luchador
        validarCampoAlfabetico(universo.luchadores[i].nombre, 30);
        universo.luchadores[i].poder = validarFloatPositivo("Poder: ");
        universo.luchadores[i].edad = validarEnteroPositivo("Edad: ");
        universo.luchadores[i].estatura = validarFloatPositivo("Estatura (en metros): ");
        cout << "Raza: ";
        cin.ignore();  // Limpiar el buffer antes de leer la raza
        validarCampoAlfabetico(universo.luchadores[i].raza, 20);
    }

    return universo;
}

// Liberar memoria dinámica
void liberarMemoria(Universo& universo) {
    delete[] universo.luchadores;
}


// Mostrar universos registrados
void mostrarUniversos(NodoArbol* raiz) {
    if (!raiz) {
        cout << "No hay universos registrados.\n";
        return;
    }
    mostrarArbol(raiz);  // Esta función ya está definida como la que muestra el árbol jerarquizado
}

#endif // FUNCIONES_H
