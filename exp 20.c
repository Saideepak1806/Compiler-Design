#include <stdio.h>

void trail_E() { printf("+ * i ) "); }
void trail_T() { printf("* i ) "); }
void trail_F() { printf("i ) "); }

int main() {
    printf("TRAILING(E) = { "); trail_E(); printf("}\n");
    printf("TRAILING(T) = { "); trail_T(); printf("}\n");
    printf("TRAILING(F) = { "); trail_F(); printf("}\n");
    return 0;
}

