#include <stdio.h>

unsigned char status = 0xA7;
int error[2];
char errortype[3][17] = {"Fehler", "Übertemperatur", "Unterspannung"};

int value = 0;

void main () {
    if (status & 128) {
        error[0] = 1;
    } 
    if (status & 64) {
        error[1] = 1;
    } 
    if (status & 32) {
        error[2] = 1;
    }

    value = status & 15; //0-3 bit -> 4 bit

    for (int i = 0; i <= 2; i++)
    {
        printf("Es ist ");
        if (error[i]) {
            printf("ein ");
        } else {
            printf("kein ");
        }
        printf("%s vorhanden.\n", errortype[i]);
    }
    
    printf("Der Messwert beträgt %i.\n", value);
}

/*
xxxx xxxx
0000 0111
0000 0xxx

*/