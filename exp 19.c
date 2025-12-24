#include <stdio.h>
#include <string.h>

void leading_E() { printf("( i "); }
void leading_T() { printf("( i "); }
void leading_F() { printf("( i "); }

int main() {
    printf("LEADING(E) = { "); leading_E(); printf("}\n");
    printf("LEADING(T) = { "); leading_T(); printf("}\n");
    printf("LEADING(F) = { "); leading_F(); printf("}\n");
    return 0;
}

