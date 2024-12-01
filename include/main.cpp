#include <iostream>
#include "Estructuras.h"
#include "Funciones.h"
#include "Pilas.h"
#include "Colas.h"
#include "Arboles.h"

// Función para mostrar el menú
void mostrarMenu() {
    std::cout << "\n==== Menú Principal ====\n";
    std::cout << "1. Registrar un universo\n";
    std::cout << "2. Eliminar luchadores y apilarlos (Pilas)\n";
    std::cout << "3. Gestionar el orden de participación (Colas)\n";
    std::cout << "4. Mostrar universos ordenados por poder (Árboles)\n";
    std::cout << "5. Salir\n";
    std::cout << "Ingrese una opción: ";
}

int main() {
    NodoPilaLuchador* pilaLuchadores = nullptr;
    NodoArbol* arbolUniversos = nullptr;
    Cola colaLuchadores;
    Universo universo;  // Declara la variable universo correctamente.

    inicializarCola(colaLuchadores);  // Inicializa la cola

    int opcion;
    int idUniverso = 1; // ID incremental para universos

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                // Registrar un universo
                Universo universo = registrarUniverso(idUniverso++);
                arbolUniversos = insertarArbol(arbolUniversos, universo);
                break;
            }
            case 2: {
                // Eliminar luchador y apilar
                int index;
                std::cout << "Ingrese el índice del luchador a eliminar: ";
                std::cin >> index;
                eliminarLuchador(pilaLuchadores, universo, index);
                break;
            }
            case 3: {
                // Gestionar el orden en colas
                int index;
                std::cout << "Ingrese el índice del luchador a encolar: ";
                std::cin >> index;
                if (index >= 0 && index < universo.cantidadLuchadores) {
                    encolar(colaLuchadores, universo.luchadores[index]); // Encola al luchador
                    std::cout << "Luchador " << universo.luchadores[index].nombre
                              << " encolado.\n";
                } else {
                    std::cout << "Índice inválido.\n";
                }
                break;
            }
            case 4: {
                // Mostrar universos ordenados por poder
                mostrarUniversosPorPoder(arbolUniversos);
                break;
            }
            case 5: {
                // Salir
                std::cout << "Saliendo del programa...\n";
                break;
            }
            default:
                std::cout << "Opción inválida. Intente nuevamente.\n";
        }
        
        // Mostrar la cola de luchadores
        std::cout << "\nLuchadores en cola:\n";
        mostrarCola(colaLuchadores);

    } while (opcion != 5);

    // Liberar recursos
    liberarMemoria(universo);
    vaciarPilaLuchadores(pilaLuchadores);
    // Cola y árbol podrían necesitar liberación de memoria adicional.
    
    return 0;
}
