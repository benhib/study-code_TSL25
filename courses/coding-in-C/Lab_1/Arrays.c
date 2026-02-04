#include <stdio.h>

int switcharray();

void main() {
int array1[][3] = {{12,-5,16}, {5,9,-4}, {-6,8,4}};
int array2[][3] = {{87,235,-4}, {-765,234,5}, {-6,23,-4}};

for (int i = 0; i < 3; i++)
{
    for (int c = 0; c < 3; c++)
    {
        printf();
    }
    
}


}

int[][3][3] switcharray(int array1[][3],int  array2[][3]) {
for (int i = 0; i < 3; i++)
{
    int helparr[3][3];
    for (int c = 0; c < 3; c++)
    {
        helparr[i][c] = array1[i][c];
        array1[i][c] = array2[i][c];
        array2[i][c] = helparr[i][c];
    }
    return array1, array2;
}}