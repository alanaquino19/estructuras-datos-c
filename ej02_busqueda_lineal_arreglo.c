// Lee un número entero y busca si se encuentra en un arreglo previamente cargado. Indica su posición o si no existe.

#include <stdio.h>

int main() {
    int numeros[10];
    int i, valor, encontrado = 0;

    printf("Ingresa 10 numeros enteros:\n");
    for(i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    printf("Ingresa el valor a buscar: ");
    scanf("%d", &valor);

    for(i = 0; i < 10; i++) {
        if(numeros[i] == valor) {
            printf("Valor encontrado en la posicion %d\n", i);
            encontrado = 1;
            break;
        }
    }

    if(!encontrado) {
        printf("Valor no encontrado\n");
    }

    return 0;
}
