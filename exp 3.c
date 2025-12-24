#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char word[]) {
    char keywords[][10] = {
        "main","int","float","char","if","else","for","while","return","printf"
    };
    int total = sizeof(keywords)/sizeof(keywords[0]);
    for (int i = 0; i < total; i++) {
        if (strcmp(keywords[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *fp = fopen("flex_input.txt", "r");
    if (!fp) {
        printf("File error\n");
        return 0;
    }

    char buffer[50];
    int index = 0;
    char ch;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '/') {
            char next = fgetc(fp);
            if (next == '/') {
                while ((ch = fgetc(fp)) != '\n' && ch != EOF);
                continue;
            }
            if (next == '*') {
                while (ch != EOF) {
                    ch = fgetc(fp);
                    if (ch == '*' && (next = fgetc(fp)) == '/') {
                        break;
                    }
                }
                continue;
            }
            if (strchr("+-*/%=", ch)) {
                printf("%c is operator\n", ch);
            }
        }

        if (strchr("+-*/%=", ch)) {
            printf("%c is operator\n", ch);
        }

        if (isalnum(ch)) {
            buffer[index++] = ch;
        } else if (index > 0) {
            buffer[index] = '\0';
            if (isKeyword(buffer)) {
                printf("%s is keyword\n", buffer);
            } else {
                printf("%s is identifier\n", buffer);
            }
            index = 0;
        }
    }

    fclose(fp);
    return 0;
}

