#include <stdio.h>
#include <ctype.h>
#include <string.h>

char input[100];
char stack[100][20];
int top = 0;
int tcount = 1;

void push(char *token) {
    strcpy(stack[top++], token);
}

int main() {
    printf("Enter expression: ");
    scanf("%s", input);

    char token[20];
    int i = 0, len = strlen(input);

    while (i < len) {
        if (isspace(input[i])) { i++; continue; }

        if (isalnum(input[i])) {
            int j = 0;
            while (i < len && isalnum(input[i]))
                token[j++] = input[i++];
            token[j] = '\0';
            push(token);
            continue;
        }

        if (strchr("+-*/=", input[i])) {
            token[0] = input[i++];
            token[1] = '\0';
            push(token);
            continue;
        }
    }

    printf("\nGenerated TAC:\n");
    for (int k = 0; k < top; k++) {
        if (strcmp(stack[k], "*") == 0 || strcmp(stack[k], "/") == 0 ||
            strcmp(stack[k], "+") == 0 || strcmp(stack[k], "-") == 0) {

            printf("t%d = %s %s %s\n", tcount, stack[k-1], stack[k], stack[k+1]);
            printf("%s = t%d\n", stack[k-1], tcount);
            tcount++;
        }
    }

    return 0;
}

