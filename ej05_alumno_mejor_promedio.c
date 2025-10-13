// Define una estructura Alumno con nombre, edad y promedio. Crea un arreglo de 5 alumnos e imprime los datos del alumno con mejor promedio.

#include <stdio.h>

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Alumno;

int main() {
    Alumno alumnos[5];
    int i, pos_max = 0;

    for(i = 0; i < 5; i++) {
        printf("Nombre del alumno %d: ", i + 1);
        scanf("%s", alumnos[i].nombre);
        printf("Edad: ");
        scanf("%d", &alumnos[i].edad);
        printf("Promedio: ");
        scanf("%f", &alumnos[i].promedio);
    }

    for(i = 1; i < 5; i++) {
        if(alumnos[i].promedio > alumnos[pos_max].promedio) {
            pos_max = i;
        }
    }

    printf("\nAlumno con mejor promedio:\n");
    printf("Nombre: %s\n", alumnos[pos_max].nombre);
    printf("Edad: %d\n", alumnos[pos_max].edad);
    printf("Promedio: %.2f\n", alumnos[pos_max].promedio);

    return 0;
}
