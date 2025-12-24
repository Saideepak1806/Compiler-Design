#include <stdio.h>

int main() {
    int space = 0, newline = 0;
    char ch;
    FILE *fp = fopen("flex_input.txt","r");
    if (!fp) {
        printf("File error\n");
        return 0;
    }
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ') space++;
        if (ch == '\n') newline++;
    }
    printf("Spaces: %d\nLines: %d\n", space, newline);
    fclose(fp);
    return 0;
}

