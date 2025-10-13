// Implementa una tabla hash de enteros usando una función hash sencilla y listas enlazadas para manejar colisiones. Incluye insertar y buscar.

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

Nodo* tabla[TAM];

int hash(int valor) {
    return valor % TAM;
}

void insertar(int valor) {
    int indice = hash(valor);
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = tabla[indice];
    tabla[indice] = nuevo;
}

int buscar(int valor) {
    int indice = hash(valor);
    Nodo* actual = tabla[indice];
    while(actual != NULL) {
        if(actual->dato == valor) {
            return 1;
        }
        actual = actual->siguiente;
    }
    return 0;
}

void mostrar() {
    int i;
    for(i = 0; i < TAM; i++) {
        printf("%d: ", i);
        Nodo* actual = tabla[i];
        while(actual != NULL) {
            printf("%d -> ", actual->dato);
            actual = actual->siguiente;
        }
        printf("NULL\n");
    }
}

int main() {
    int opcion, valor, i;
    for(i = 0; i < TAM; i++) {
        tabla[i] = NULL;
    }

    do {
        printf("\n1. Insertar\n2. Buscar\n3. Mostrar tabla\n4. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        if(opcion == 1) {
            printf("Valor a insertar: ");
            scanf("%d", &valor);
            insertar(valor);
        } else if(opcion == 2) {
            printf("Valor a buscar: ");
            scanf("%d", &valor);
            if(buscar(valor)) {
                printf("Valor encontrado\n");
            } else {
                printf("Valor no encontrado\n");
            }
        } else if(opcion == 3) {
            mostrar();
        }
    } while(opcion != 4);

    return 0;
}
