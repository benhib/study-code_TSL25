#include <stdio.h>

//Global list of letters, mutiple use
const char col_lable[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};


//Function mapping for compiler
void chessboard_I();
void chessboard_II();
void row_letter();
void row_border();

int main () {

    chessboard_II();

    return 0;
}


void chessboard_I() { //Section I; simple chessboard

    for (int col = 8; col > 0; col--) //Board starts at 8
    {
        for (int row = 1; row < 8; row++)
        {
            printf("%c%i ", col_lable[row-1], col);
        }
        printf("\n");
    }
    
}

void row_letter() { //Prints the row with the column letters
    printf(" ");
    for (int col = 0; col < 8; col++) //Letters on top
    {
            printf("%4c", col_lable[col]);
    }
    printf("\n");
}

void row_border() { //Prints the row with border markers
    char pattern[] = "+---";
    printf("  ");
    for (int i = 0; i < 8; i++)
    {
        printf("%s", pattern);
    }
    printf("+  \n");
}

void chessboard_II() { //Prints the chessboard with border, labeling and colored squares
    
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
    row_border();
    }
    
    row_letter();

}



