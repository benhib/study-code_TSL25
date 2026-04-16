#include <stdio.h>
#include "test_header.hpp"

void print_hello() {
    printf("Hello World from C!\n");
}

int main() {
    print_hello();
    printFromHeader();
 }