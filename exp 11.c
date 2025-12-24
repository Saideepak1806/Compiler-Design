#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;
struct sym { char label[20]; int addr; } table[50];

int search(char s[]) {
    for (int i = 0; i < count; i++)
        if (strcmp(table[i].label, s) == 0) return 1;
    return 0;
}

void insert() {
    char lab[20];
    int ad;
    scanf("%s %d", lab, &ad);
    if (search(lab)) printf("Duplicate\n");
    else strcpy(table[count].label, lab), table[count++].addr = ad;
}

void display() {
    for (int i = 0; i < count; i++)
        printf("%s %d\n", table[i].label, table[i].addr);
}

int main() {
    int ch;
    while (1) {
        scanf("%d", &ch);
        if (ch == 1) insert();
        if (ch == 2) display();
        if (ch == 3) exit(0);
    }
}

