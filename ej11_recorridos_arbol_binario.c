// A partir de un árbol binario ya construido, implementa funciones para imprimir los recorridos inorden, preorden y postorden.

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
    if (raiz == NULL) {
        return crear_nodo(valor);
    }
    if (valor < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        raiz->derecho = insertar(raiz->derecho, valor);
    }
    return raiz;
}

void inorden(Nodo* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izquierdo);
        printf("%d ", raiz->dato);
        inorden(raiz->derecho);
    }
}

void preorden(Nodo* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dato);
        preorden(raiz->izquierdo);
        preorden(raiz->derecho);
    }
}

void postorden(Nodo* raiz) {
    if (raiz != NULL) {
        postorden(raiz->izquierdo);
        postorden(raiz->derecho);
        printf("%d ", raiz->dato);
    }
}

int main() {
    Nodo* raiz = NULL;
    int opcion, valor;

    do {
        printf("\n1. Insertar\n2. Inorden\n3. Preorden\n4. Postorden\n5. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            printf("Valor a insertar: ");
            scanf("%d", &valor);
            raiz = insertar(raiz, valor);
        } else if (opcion == 2) {
            inorden(raiz);
            printf("\n");
        } else if (opcion == 3) {
            preorden(raiz);
            printf("\n");
        } else if (opcion == 4) {
            postorden(raiz);
            printf("\n");
        }
    } while (opcion != 5);

    return 0;
}
