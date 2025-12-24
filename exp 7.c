#include <stdio.h>
#include <ctype.h>
#include <string.h>

char follow[50];
int fcount = 0;

void addFollow(char c) {
    for (int i = 0; i < fcount; i++) {
        if (follow[i] == c) return;
    }
    follow[fcount++] = c;
}

int main() {
    char nonterm;
    printf("Enter non-terminal: ");
    scanf(" %c", &nonterm);

    addFollow('$');
    printf("FIRST(%c) = { ", nonterm);
    for (int i = 0; i < fcount; i++) {
        printf("%c ", follow[i]);
    }
    printf("}\n");
    return 0;
}

