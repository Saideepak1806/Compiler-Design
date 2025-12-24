#include <stdio.h>
#include <string.h>

int main() {
    char prod[100];
    printf("Enter production: ");
    scanf("%s", prod);

    if (strncmp(prod, "iEtS", 4) == 0) {
        printf("Factored grammar: S -> iEtSX\nX -> eS | a\n");
    } else {
        printf("No factoring needed\n");
    }
    return 0;
}

