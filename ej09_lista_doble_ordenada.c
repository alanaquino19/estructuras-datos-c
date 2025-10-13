// Implementa una lista doblemente enlazada donde cada nuevo nodo se inserte automáticamente de forma ordenada (ascendente).

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* anterior;
    struct Nodo* siguiente;
} Nodo;

Nodo* cabeza = NULL;

void insertar_ordenado(int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;

    if(cabeza == NULL) {
        cabeza = nuevo;
    } else if(valor < cabeza->dato) {
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
        cabeza = nuevo;
    } else {
        Nodo* actual = cabeza;
        while(actual->siguiente != NULL && actual->siguiente->dato < valor) {
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual->siguiente;
        if(actual->siguiente != NULL) {
            actual->siguiente->anterior = nuevo;
        }
        nuevo->anterior = actual;
        actual->siguiente = nuevo;
    }
}

void mostrar() {
    Nodo* actual = cabeza;
    while(actual != NULL) {
        printf("%d <-> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

int main() {
    int opcion, valor;
    do {
        printf("\n1. Insertar ordenado\n2. Mostrar lista\n3. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        if(opcion == 1) {
            printf("Valor a insertar: ");
            scanf("%d", &valor);
            insertar_ordenado(valor);
        } else if(opcion == 2) {
            mostrar();
        }
    } while(opcion != 3);

    return 0;
}
