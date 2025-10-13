// Implementa una pila usando un arreglo. Incluye funciones para push, pop y mostrar la pila.

#include <stdio.h>
#define MAX 10

int pila[MAX];
int tope = -1;

void push(int valor) {
    if(tope < MAX - 1) {
        tope++;
        pila[tope] = valor;
    }
}

int pop() {
    if(tope >= 0) {
        int valor = pila[tope];
        tope--;
        return valor;
    }
    return -1;
}

void mostrar() {
    int i;
    if(tope == -1) {
        printf("Pila vacia\n");
        return;
    }
    for(i = tope; i >= 0; i--) {
        printf("%d\n", pila[i]);
    }
}

int main() {
    int opcion, valor;
    do {
        printf("\n1. Push\n2. Pop\n3. Mostrar pila\n4. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        if(opcion == 1) {
            printf("Valor a insertar: ");
            scanf("%d", &valor);
            push(valor);
        } else if(opcion == 2) {
            valor = pop();
            if(valor != -1) {
                printf("Se extrajo: %d\n", valor);
            } else {
                printf("Pila vacia\n");
            }
        } else if(opcion == 3) {
            mostrar();
        }
    } while(opcion != 4);

    return 0;
}
