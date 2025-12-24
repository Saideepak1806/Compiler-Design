#include <stdio.h>
#include <string.h>

int main() {
    char op[10];
    printf("Enter operator: ");
    scanf("%s", op);

    if (strcmp(op, "+") == 0) printf("Addition\n");
    else if (strcmp(op, "-") == 0) printf("Subtraction\n");
    else if (strcmp(op, "*") == 0) printf("Multiplication\n");
    else if (strcmp(op, "/") == 0) printf("Division\n");
    else printf("Invalid operator\n");

    return 0;
}

