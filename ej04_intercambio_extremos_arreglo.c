// Pide al usuario un arreglo de 5 enteros e intercambia el primer elemento con el último. Muestra el arreglo final.

#include <stdio.h>

int main() {
    int numeros[5];
    int i, temp;

    printf("Ingresa 5 numeros enteros:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &numeros[i]);
    }

    temp = numeros[0];
    numeros[0] = numeros[4];
    numeros[4] = temp;

    printf("Arreglo final:\n");
    for(i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }

    return 0;
}
