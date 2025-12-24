#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *input;
int i = 0, top = 0, len;
char stack[100];
char handles[5][10] = {"(E)","E+E","E*E","i","E^E"};

char table[9][9] = {
    {'>','>','<','<','<','<','<','>','>'},
    {'>','>','<','<','<','<','<','>','>'},
    {'>','>','>','>','<','<','<','>','>'},
    {'>','>','>','>','<','<','<','>','>'},
    {'>','>','>','>','<','<','<','>','>'},
    {'>','>','>','>','>','e','e','>','>'},
    {'<','<','<','<','<','<','<','>','e'},
    {'>','>','>','>','>','e','e','>','>'},
    {'<','<','<','<','<','<','<','<','>'}
};

int idx(char c) {
    if(c=='+') return 0;
    if(c=='-') return 1;
    if(c=='*') return 2;
    if(c=='/') return 3;
    if(c=='^') return 4;
    if(isalpha(c)) return 5;
    if(c=='(') return 6;
    if(c==')') return 7;
    if(c=='$') return 8;
    return -1;
}

void reduce() {
    for(int h=0; h<5; h++) {
        int hlen = strlen(handles[h]);
        if(top >= hlen && strcmp(&stack[top-hlen], handles[h])==0) {
            top -= hlen;
            stack[top++]='E';
            stack[top]='\0';
            printf("Reduced using E?%s\n", handles[h]);
        }
    }
}

int main() {
    input = (char*)malloc(100);
    printf("Enter expression: ");
    scanf("%s", input);
    strcat(input,"$");
    len = strlen(input);

    strcpy(stack,"$");
    top = 1;

    while(i < len) {
        stack[top++] = input[i++];
        stack[top]='\0';
        printf("%s\t%s\tShift\n", stack, &input[i]);
        if(table[idx(stack[top-1])][idx(input[i])] == '>') {
            reduce();
        }
    }

    if(strcmp(stack,"$E$")==0)
        printf("ACCEPTED\n");
    else
        printf("REJECTED\n");
}

