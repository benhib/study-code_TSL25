#include <stdio.h>
#include <stdlib.h>

int main() {
    int input = 0;
    if (!scanf("%i", &input)) {
        printf("Error reading integer from terminal\n.");
    }
    //malloc gives a pointer to the start of the reserved storage but it doesnt have to be contious
    int *psave = malloc(sizeof *psave);

    if (psave == NULL) {
        printf("Failed to allocate memory.\n");
        return -1;
    }

    *psave = input;

    //calloc gives a pointer to a continous reserved memory space filled with "0"
    int *psavecont = calloc(input, sizeof *psavecont);
    if (psavecont == NULL) {
        printf("Failed to allocate memory.\n");
        return -1;
    }

    for (int i = 0; i < input; i++) {
        *(psavecont + i) = i * i;
        printf("Result: %i\n", *(psavecont + i));
    }

    int *preallocated = realloc(psavecont, 2* input * sizeof *psavecont);

    if (preallocated == NULL) {
        printf("Failed to reallocate memory.\n");
        return -1;
    }

    psavecont = NULL;

    printf("Memory reallocated.\n");
    for (int i = 0; i < 2*input; i++)
    {
        *(preallocated + i) = i*i;
        printf("Result: %i\n", *(psavecont + i));
    }
    

    free(psave);
    free(preallocated);
    
}