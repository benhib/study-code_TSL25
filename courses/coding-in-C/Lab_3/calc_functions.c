#include <stdio.h>

float add(float number1, float number2);
float subtract(float number1, float number2);
float multiply(float number1, float number2);
float division(float number1, float number2);

int main() {
    float input1;
    float input2;
    float result;
    char operation;
    int flag = 0;

    printf("Geben Sie die erste Zahl ein: \n");
    scanf("%f", &input1);
    printf("Geben Sie die erste Zahl ein: \n");
    scanf("%f", &input2);
    printf("Geben Sie ein, welche Operation Sie durchführen möchten (+, -, *, /): \n");
    


    while (!flag) {
    scanf("%*c%c", &operation);
    
    switch (operation) {

    case('+'):
        result = add(input1, input2);
        break;

    case('-'):
        result = subtract(input1, input2);
        break;

    case('*'):
        result = multiply(input1, input2);
        break;

    case('/'):
        if(!input2) { 
            printf("Die Division durch 0 ist nicht definiert. Bitte starten Sie den Rechner neu. \n");
            return(0);
        }
        result = division(input1, input2);
        break;

    default:
        printf("Ungültige Operation, bitte geben Sie eine valide Operation ein (+, -, *, /): \n");
        continue;
    }

    flag = 1;
    }

    printf("%.4f %c %.4f = %.4f", input1, operation, input2, result);
    return 0;
}

float add(float number1, float number2) {
    return number1 + number2;
}

float subtract(float number1, float number2) {
    return number1 - number2;
}

float multiply(float number1, float number2) {
    return number1 * number2;
}

float division(float number1, float number2) {
    return number1 / number2;
}