#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[100], stack[100];
int ip = 0, sp = 0;

void reduce() {
    while (1) {
        if (sp >= 3 && stack[sp-3]=='E' && stack[sp-2]=='+' && stack[sp-1]=='E') {
            sp -= 3;
            stack[sp++] = 'E';
            printf("Reduced: E?E+E\n");
        }
        else if (sp >= 3 && stack[sp-3]=='E' && stack[sp-2]=='*' && stack[sp-1]=='E') {
            sp -= 3;
            stack[sp++] = 'E';
            printf("Reduced: E?E*E\n");
        }
        else if (sp >= 1 && (stack[sp-1]=='a' || stack[sp-1]=='b')) {
            sp -= 1;
            stack[sp++] = 'E';
            printf("Reduced: E?%c\n", stack[sp-1]);
        }
        else break;
    }
}

int main() {
    printf("Enter input: ");
    scanf("%s", input);
    strcpy(stack, "");
    sp = 0;

    while (input[ip] != '\0') {
        stack[sp++] = input[ip++];
        stack[sp] = '\0';
        printf("Stack after shift: %s\n", stack);
        reduce();
    }

    if (sp == 1 && stack[0] == 'E')
        printf("ACCEPT\n");
    else
        printf("REJECT\n");

    return 0;
}

