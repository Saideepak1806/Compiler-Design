#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of 3-address statements: ");
    scanf("%d", &n);

    char lhs[20], op1[20], op2[20], op;
    int t = 1;

    printf("\nEnter statements in form: a=b+c or d=x*y\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", lhs);        // read LHS token
        scanf("=%s%c%s", op1, &op, op2); // parse RHS

        printf("mov %s, R%d\n", op1, t);
        if (op == '+') printf("add %s, R%d\n", op2, t);
        if (op == '-') printf("sub %s, R%d\n", op2, t);
        if (op == '*') printf("mul %s, R%d\n", op2, t);
        if (op == '/') printf("div %s, R%d\n", op2, t);
        printf("mov R%d, %s\n\n", t, lhs);
        t++;
    }

    return 0;
}

