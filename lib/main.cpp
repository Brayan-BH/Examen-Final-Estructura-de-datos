#include "Pilas.h"
using namespace std;

int main (){
    Pila *pila = new Pila;

    int opcion;

    do
    {
        // Menu
        cout<<"1. Apilar"<<endl;
        cout<<"2. Desapilar"<<endl;
        cout<<"3. Mostrar"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Ingrese una opcion del menu: "<<endl;
        cin>>opcion;

        if (opcion != 4)
        {
            switch (opcion)
            {
            case 1:
                apilar(pila);
                break;
            case 2:
                desapilar(pila);
                break;
            case 3:
                mostrar(pila);
                break;
            default:
                cout<<"Opcion invalida"<<endl;
                break;
            }
        }
        
        
    } while (opcion != 4);
    
    return 0;
}