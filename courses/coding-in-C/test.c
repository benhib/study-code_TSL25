#include <stdio.h>

int main () {
    int test[] = {10,20,30,40,50};
    int* ptest_1 = &test[1];
    int* ptest_2 = &test[sizeof(test - 1)];

    printf("Pointer1: %p \nPointer2: %p \nDifferenz: %i", ptest_1, ptest_2, ptest_2 - ptest_1);

    return 0;
}