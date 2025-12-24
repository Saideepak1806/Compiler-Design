#include <stdio.h>
#include <ctype.h>
#include <string.h>

int i = 0;
char input[100];

int S() {
    if (input[i] == 'a') {
        i++;
        if (input[i] == 'b') {
            i++;
            return 1;
        }
        i--;
    }

    if (input[i] == 'a') {
        i++;
        return S();
    }

    if (input[i] == 'b') {
        i++;
        return S();
    }

    return 0;
}

int main() {
    printf("Grammar: S ? aS | Sb | ab\n");
    printf("Enter string: ");
    scanf("%s", input);

    if (S() && input[i] == '\0')
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}

