// Implementa un árbol binario de búsqueda con inserción y búsqueda. Permite buscar si un valor existe en el árbol.

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* izquierdo;
    struct Nodo* derecho;
} Nodo;

Nodo* crear_nodo(int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    return nuevo;
}

Nodo* insertar(Nodo* raiz, int valor) {
    if(raiz == NULL) {
        return crear_nodo(valor);
    }
    if(valor < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } else if(valor > raiz->dato) {
        raiz->derecho = insertar(raiz->derecho, valor);
    }
    return raiz;
}

int buscar(Nodo* raiz, int valor) {
    if(raiz == NULL) {
        return 0;
    }
    if(raiz->dato == valor) {
        return 1;
    }
    if(valor < raiz->dato) {
        return buscar(raiz->izquierdo, valor);
    } else {
        return buscar(raiz->derecho, valor);
    }
}

int main() {
    Nodo* raiz = NULL;
    int opcion, valor;

    do {
        printf("\n1. Insertar\n2. Buscar\n3. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        if(opcion == 1) {
            printf("Valor a insertar: ");
            scanf("%d", &valor);
            raiz = insertar(raiz, valor);
        } else if(opcion == 2) {
            printf("Valor a buscar: ");
            scanf("%d", &valor);
            if(buscar(raiz, valor)) {
                printf("Valor encontrado\n");
            } else {
                printf("Valor no encontrado\n");
            }
        }
    } while(opcion != 3);

    return 0;
}
