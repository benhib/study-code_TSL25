#include <stdio.h>
#include <assert.h>
#include "string_utils.h"

int main() {
    char string[3] = "te";
    int len = custom_len(string);

    printf("Länge des Strings: %i", len);
}

