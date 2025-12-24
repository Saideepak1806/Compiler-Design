#include <stdio.h>
#include <string.h>

char input[100];
int i = 0;

int E();
int T();
int EP();
int TP();
int F();

int main() {
    printf("Enter expression: ");
    scanf("%s", input);
    if (E() && input[i] == '\0')
        printf("Accepted\n");
    else
        printf("Rejected\n");
    return 0;
}

int E() { return T() && EP(); }
int EP() {
    if (input[i] == '+') i++, T(), EP();
    return 1;
}
int T() { return F() && TP(); }
int TP() {
    if (input[i] == '*') i++, F(), TP();
    return 1;
}
int F() {
    if (input[i] == '(') return i++, E(), input[i] == ')' && i++, 1;
    if (isalpha(input[i])) return i++, 1;
    return 0;
}

