#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter input: ");
    fgets(input, 100, stdin);

    if (strncmp(input, "//", 2) == 0) {
        printf("It is a comment\n");
        return 0;
    }

    if (strncmp(input, "/*", 2) == 0) {
        if (strstr(input, "*/")) {
            printf("It is a comment\n");
        } else {
            printf("Not a valid comment\n");
        }
        return 0;
    }

    printf("It is not a comment\n");
    return 0;
}

