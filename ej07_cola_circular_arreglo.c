// Implementa una cola circular. Implementa enqueue, dequeue y función para mostrar el contenido.

#include <stdio.h>
#define MAX 5

int cola[MAX];
int frente = -1;
int final = -1;

void enqueue(int valor) {
    if((final + 1) % MAX == frente) {
        return;
    }
    if(frente == -1) {
        frente = 0;
    }
    final = (final + 1) % MAX;
    cola[final] = valor;
}

int dequeue() {
    if(frente == -1) {
        return -1;
    }
    int valor = cola[frente];
    if(frente == final) {
        frente = final = -1;
    } else {
        frente = (frente + 1) % MAX;
    }
    return valor;
}

void mostrar() {
    int i;
    if(frente == -1) {
        printf("Cola vacia\n");
        return;
    }
    i = frente;
    while(1) {
        printf("%d ", cola[i]);
        if(i == final) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int opcion, valor;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Mostrar cola\n4. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        if(opcion == 1) {
            printf("Valor a insertar: ");
            scanf("%d", &valor);
            enqueue(valor);
        } else if(opcion == 2) {
            valor = dequeue();
            if(valor != -1) {
                printf("Se extrajo: %d\n", valor);
            } else {
                printf("Cola vacia\n");
            }
        } else if(opcion == 3) {
            mostrar();
        }
    } while(opcion != 4);

    return 0;
}
