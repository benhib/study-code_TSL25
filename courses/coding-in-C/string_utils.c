#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>

int custom_len(char *string) {
    int len = 0;
    while(string[len] != "\0") {
        len++;
    }
    
    return len;
}
/*
jedes Zeichen hat 4 bytes -> größe von Text -> 4*anzahl der Zeichen -> ()/4 -> Anzahl der Zeichen
*/

//
char *read_line_dynamic() {
    char first_element[100];
    if(fgets(first_element, 100, stdin) == 0) {
        printf("Keine Eingabe gefunden.\n");
        return NULL;
    }

    int len = custom_len(first_element);

    char *pstring = malloc(len * sizeof(*pstring));

    if(pstring == NULL) {
        printf("Speicher konnte nicht reserviert werden.\n");
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        *(pstring + i) = first_element[i];
    }
    
    return pstring;
}
