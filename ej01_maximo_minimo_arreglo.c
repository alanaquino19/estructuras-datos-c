// Declara un arreglo de 10 enteros, pide al usuario que los ingrese e imprime el valor máximo y mínimo.

#include <stdio.h>

int main() {
    int numeros[10];
    int i;
    int max, min;

    printf("Ingresa 10 numeros enteros:\n");

    for(i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    max = numeros[0];
    min = numeros[0];

    for(i = 1; i < 10; i++) {
        if(numeros[i] > max) {
            max = numeros[i];
        }
        if(numeros[i] < min) {
            min = numeros[i];
        }
    }

    printf("\nEl valor maximo es: %d\n", max);
    printf("El valor minimo es: %d\n", min);

    return 0;
}
