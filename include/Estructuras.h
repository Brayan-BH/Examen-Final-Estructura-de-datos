#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H


// Estructura de Luchadores
struct Luchador {
    char nombre[30];   // Nombre del luchador
    int poder;         // Poder del luchador
    int edad;          // Edad del luchador
    float estatura;    // Estatura en metros
    char raza[20];     // Raza del luchador
};

// Estructura de Universos
struct Universo {
    int id;                  // ID del universo
    char nombre[30];         // Nombre del universo
    int cantidadLuchadores;  // Cantidad de luchadores en el universo
    float poderTotal;        // Poder total del universo
    char dios[30];           // Nombre del dios del universo
    char angel[30];          // Nombre del ángel del universo
    Luchador* luchadores;    // Lista dinámica de luchadores
};

#endif // ESTRUCTURAS_H
