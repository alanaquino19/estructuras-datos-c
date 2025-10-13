// Crea una lista enlazada simple y permite insertar nodos al inicio. Muestra la lista después de cada inserción.

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

Nodo* cabeza = NULL;

void insertar_inicio(int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

void mostrar() {
    Nodo* actual = cabeza;
    while(actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

int main() {
    int opcion, valor;
    do {
        printf("\n1. Insertar al inicio\n2. Mostrar lista\n3. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        if(opcion == 1) {
            printf("Valor a insertar: ");
            scanf("%d", &valor);
            insertar_inicio(valor);
        } else if(opcion == 2) {
            mostrar();
        }
    } while(opcion != 3);

    return 0;
}
