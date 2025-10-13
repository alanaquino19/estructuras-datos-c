// Dado un arreglo de caracteres, cuenta cuántas veces aparece cada vocal.

#include <stdio.h>

int main() {
    char texto[100];
    int i = 0;
    int a = 0, e = 0, i_v = 0, o = 0, u = 0;
    char c;

    printf("Ingresa una cadena de texto: ");
    fgets(texto, sizeof(texto), stdin);

    while ((c = texto[i]) != '\0') {
        if (c == 'a' || c == 'A') a++;
        else if (c == 'e' || c == 'E') e++;
        else if (c == 'i' || c == 'I') i_v++;
        else if (c == 'o' || c == 'O') o++;
        else if (c == 'u' || c == 'U') u++;
        i++;
    }

    printf("A: %d\n", a);
    printf("E: %d\n", e);
    printf("I: %d\n", i_v);
    printf("O: %d\n", o);
    printf("U: %d\n", u);

    return 0;
}
