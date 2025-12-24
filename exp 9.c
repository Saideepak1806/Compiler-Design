#include <stdio.h>
#include <string.h>

int main() {
    char prod[100];
    printf("Enter production: ");
    scanf("%s", prod);

    if (prod[0] == prod[3]) {
        printf("Left recursive\n");
        printf("Refactored grammar applied manually.\n");
    } else {
        printf("Not left recursive\n");
    }
    return 0;
}

