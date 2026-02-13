#include <stdio.h>
#include <ctype.h>

int main() {
    char word[101];

    printf("Geben Sie ein Wort zum testen ein: \n");
    scanf("%100s", word);

    
    int i = 0;
    for (;i < 101; i++) { // Überprüft Länge des Worts
        if (word[i] == '\0') {
            i;
            break;
        }
    }
    
    
        for (int pos = 0; pos <= i/2; pos++) { // Prüft auf Gleichheit vom Rand des Worts aus
            if (tolower(word[0+pos]) == tolower(word[i-pos-1])) {
                continue;
            } 
            printf("Das Wort %s ist kein Palindrom.\n", word);
            return 0;
        }
        printf("Das Wort %s ist ein Palindrom. \n", word);
    



    return 0;
}