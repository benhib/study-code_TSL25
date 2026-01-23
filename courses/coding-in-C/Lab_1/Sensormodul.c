#include <stdio.h>

unsigned char status = 0xA7;
int error = 0;
int temperror = 0;
int volterror = 0;
int value = 0;

void main () {
    if (status & 128) {
        error = 1;
    } 
    if (status & 64) {
        temperror = 1;
    } 
    if (status & 32) {
        volterror = 1;
    }

    value = status & 7;

    printf("Fehler: %i\n", error);
    printf("Übertemperatur: %i\n", temperror);
    printf("Unterspannung: %i\n", volterror);
    printf("Messwert: %i\n", value);
}

/*
xxxx xxxx
0000 0111
0000 0xxx

*/