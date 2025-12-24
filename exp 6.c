#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char id[50];
    printf("Enter identifier: ");
    scanf("%s", id);

    if (!isalpha(id[0])) {
        printf("Invalid identifier\n");
        return 0;
    }

    for (int i = 1; id[i] != '\0'; i++) {
        if (!isalnum(id[i])) {
            printf("Invalid identifier\n");
            return 0;
        }
    }

    printf("Valid identifier\n");
    return 0;
}

