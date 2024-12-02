#include <iostream>
#include "Estructuras.h"
#include "Funciones.h"
#include "Pilas.h"
#include "Colas.h"
#include "Arboles.h"
using namespace std;

// Función para mostrar el menú
void mostrarMenu()
{
    cout << "\n==== Menú Principal ====\n";
    cout << "1. Registrar un universo\n";
    cout << "2. Eliminar luchadores y apilarlos (Pilas)\n";
    cout << "3. Gestionar el orden de participación (Colas)\n";
    cout << "4. Mostrar el orden de la cola de luchadores (Colas)\n";
    cout << "5. Mostrar universos ordenados jerarquizados por poder (Árboles)\n";
    cout << "6. Salir\n";
    cout << "Ingrese una opción: ";
}

int main()
{
    NodoPilaLuchador *pilaLuchadores = nullptr;
    NodoArbol *arbolUniversos = nullptr;
    Cola colaLuchadores;
    Universo universo; // Declara la variable universo correctamente.

    Cola colaParticipantes;
    inicializarCola(colaParticipantes);
    int opcion;
    int idUniverso = 1; // ID incremental para universos

    do
    {
        mostrarMenu();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            // Registrar un universo
            Universo universo = registrarUniverso(idUniverso++);
            arbolUniversos = insertarArbol(arbolUniversos, universo);
            break;
        }
        case 2:
        {
            // Eliminar luchador y apilar
            int index;
            cout << "Ingrese el índice del luchador a eliminar: ";
            cin >> index;
            eliminarLuchador(pilaLuchadores, universo, index);
            break;
        }
        case 3:
        {
            if (!arbolUniversos)
            {
                cout << "No hay universos registrados.\n";
                break;
            }

            // Mostrar universos disponibles
            cout << "=== Universos Registrados ===\n";
            mostrarArbol(arbolUniversos);

            // Seleccionar un universo por ID
            int idSeleccionado;
            cout << "Ingrese el ID del universo para gestionar luchadores: ";
            cin >> idSeleccionado;

            NodoArbol *nodoSeleccionado = buscarArbol(arbolUniversos, idSeleccionado);
            if (!nodoSeleccionado)
            {
                cout << "Universo no encontrado.\n";
                break;
            }

            // Gestionar luchadores del universo seleccionado
            Universo &universoSeleccionado = nodoSeleccionado->universo;
            cout << "Gestionando luchadores del Universo: " << universoSeleccionado.nombre << '\n';

            int index;
            cout << "Ingrese el índice del luchador a encolar: ";
            cin >> index;

            if (index >= 0 && index < universoSeleccionado.cantidadLuchadores)
            {
                encolar(colaLuchadores, universoSeleccionado.luchadores[index]);
                cout << "Luchador " << universoSeleccionado.luchadores[index].nombre
                     << " encolado correctamente.\n";
            }
            else
            {
                cout << "Índice inválido.\n";
            }
            break;
        }
        case 4:
        {
            // Mostrar el orden de la cola de luchadores
            mostrarCola(colaLuchadores);
            break;
        }
        case 5:
        {
            // Mostrar universos ordenados por poder
            mostrarUniversosPorPoder(arbolUniversos);
            break;
        }
        case 6:
        {
            // Salir
            cout << "Saliendo del programa...\n";
            break;
        }
        default:
            cout << "Opción inválida. Intente nuevamente.\n";
        }

        // Mostrar la cola de luchadores
        cout << "\nLuchadores en cola:\n";
        mostrarCola(colaLuchadores);

    } while (opcion != 6);

    // Liberar recursos
    liberarMemoria(universo);
    vaciarPilaLuchadores(pilaLuchadores);
    // Cola y árbol podrían necesitar liberación de memoria adicional.

    return 0;
}
