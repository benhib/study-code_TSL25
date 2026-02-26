#include <stdio.h>
#include <assert.h>
#include "string_utils.h"

int main() {
    char string[] = "Hello";
    int len = custom_len(string);

    printf("Länge des Strings: %i \n", len);

    assert(custom_len("Hello") == 5);
}

