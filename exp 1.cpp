#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[100];
    char identifiers[50][20];
    int constants[50];
    char operators[50];

    int id_count = 0, const_count = 0, op_count = 0;
    int i = 0;

    printf("Enter input: ");
    scanf("%[^\n]s", input);

    while (input[i] != '\0') {
        if (isspace(input[i])) {
            i++;
            continue;
        }

        if (isalpha(input[i])) {
            int j = 0;
            while (isalnum(input[i])) {
                identifiers[id_count][j++] = input[i++];
            }
            identifiers[id_count][j] = '\0';
            id_count++;
            continue;
        }

        if (isdigit(input[i])) {
            int num = 0;
            while (isdigit(input[i])) {
                num = num * 10 + (input[i] - '0');
                i++;
            }
            constants[const_count++] = num;
            continue;
        }

        char ch = input[i];
        if (strchr("+-*/=", ch)) {
            operators[op_count++] = ch;
        }
        i++;
    }

    printf("\nIdentifiers:\n");
    for (int k = 0; k < id_count; k++) {
        printf("%s\n", identifiers[k]);
    }

    printf("\nConstants:\n");
    for (int k = 0; k < const_count; k++) {
        printf("%d\n", constants[k]);
    }

    printf("\nOperators:\n");
    for (int k = 0; k < op_count; k++) {
        printf("%c\n", operators[k]);
    }

    return 0;
}

