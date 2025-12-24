#include <stdio.h>
#include <ctype.h>
#include <string.h>

char productions[10][50];
char follow[50];
int pcount, fcount = 0;

void addFollow(char c) {
    for (int i = 0; i < fcount; i++) {
        if (follow[i] == c) return;
    }
    follow[fcount++] = c;
}

void findFollow(char c) {
    if (productions[0][0] == c) {
        addFollow('$');
    }
    for (int i = 0; i < pcount; i++) {
        int len = strlen(productions[i]);
        for (int j = 2; j < len; j++) {
            if (productions[i][j] == c) {
                if (j+1 < len && islower(productions[i][j+1])) {
                    addFollow(productions[i][j+1]);
                }
                if (j+1 == len-1) {
                    findFollow(productions[i][0]);
                }
            }
        }
    }
}

int main() {
    printf("Enter production count: ");
    scanf("%d", &pcount);
    for (int i = 0; i < pcount; i++) {
        scanf("%s", productions[i]);
    }
    char nonterm;
    printf("Find FOLLOW of: ");
    scanf(" %c", &nonterm);
    findFollow(nonterm);
    printf("FOLLOW(%c) = { ", nonterm);
    for (int i = 0; i < fcount; i++) {
        printf("%c ", follow[i]);
    }
    printf("}\n");
    return 0;
}

