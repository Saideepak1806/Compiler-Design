#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp = fopen("flex_input.txt","r");
    if (!fp) {
        printf("File error\n");
        return 0;
    }

    char ch;
    int chars = 0, words = 0, lines = 0;
    int inWord = 0;

    while ((ch = fgetc(fp)) != EOF) {
        chars++;
        if (ch == '\n') lines++;

        if (isalnum(ch)) {
            if (!inWord) {
                inWord = 1;
                words++;
            }
        } else {
            inWord = 0;
        }
    }

    fclose(fp);
    printf("Characters: %d\nWords: %d\nLines: %d\n", chars, words, lines);
    return 0;
}

