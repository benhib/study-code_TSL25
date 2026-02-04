#include <stdio.h>

int main() {
    float number1;
    float number2;
    float result;
    char operation;
    int flag = 0;

    printf("Geben Sie die erste Zahl ein: \n");
    scanf("%f", &number1);
    printf("Geben Sie die erste Zahl ein: \n");
    scanf("%f", &number2);
    printf("Geben Sie ein, welche Operation Sie durchführen möchten (+, -, *, /): \n");
    


    while (!flag) {
    scanf("%*c%c", &operation);

    if(operation == '+') {
        result = number1 + number2;
    } else if (operation == '-') {
        result = number1 - number2;
    } else if (operation == '*') {
        result = number1 * number2;
    } else if (operation == '/') {
        if (!number2) {
            printf("Die Division durch 0 ist nicht definiert. Bitte starten Sie den Rechner neu \n");
            return(0);
        }
        result = number1 / number2;
    } else {
        printf("Ungültige Operation, bitte geben Sie eine valide Operation ein (+, -, *, /): \n");
        continue;
    }

    flag = 1;
    }

    printf("%.4f %c %.4f = %.4f", number1, operation, number2, result);
    return 0;
}