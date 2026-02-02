#include <stdio.h>

char col_lable[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};


void chessboard_I() {

    for (int col = 8; col > 0; col--) //field starts at 8
    {
        for (int row = 1; row < 9; row++)
        {
            printf("%c%i ", col_lable[row-1], col);
        }
        printf("\n");
    }
    
}

void row_letter() {
    printf(" ");
    for (int col = 0; col < 8; col++) //Letters on top
    {
            printf("%4c", col_lable[col]);
    }
    printf("\n");
}

void row_border() {
    char pattern[] = "+---";
    printf("  ");
    for (int i = 0; i < 8; i++)
    {
        printf("%s", pattern);
    }
    printf("+  \n");
}

void chessboard_II() {
    
    char black[] = "###";
    char white[] = "   ";

    row_letter();
    row_border();

    for (int row = 8; row > 0; row--)
    {
        printf("%i ", row);
        if (!(row%2)) {
                for (int i = 0; i < 4; i++)
        {
            printf("|%s|", black);
            printf("%s", white);
        }} else {
            for (int i = 0; i < 4; i++)
        {
            printf("|%s|", white);
            printf("%s", black);
        }
        
    }
    printf("| %i\n", row);
    }
    

    row_border();
    row_letter();

}



int main () {

    chessboard_II();

    return 0;
}