#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int particles[] = {0,0,0,0,0,0,0,0,0,0};
    particles[2] = 1;
    particles[4] = 1;
    particles[6] = 1;
    const int RUNS = 10;

    // int *p_particles = particles;
    
    printf("Run 0: ");
    for (int i = 0; i < 10; i++) {
        printf("%i ", particles[i]);
    }
    printf("\n");

    for (int c = 1; c < RUNS; c++) {

    int temp[] = {0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; i < (sizeof(particles)/4); i++) { //moves particles in temp | sizeof always give 4x the length?
        if(i != 0 && i != 10) { //checks for corner of array

        if(particles[i]) {
        int move = rand()%2; //0 for right, 1 for left movement
            if(move) {
                if(!temp[i-1]) { //checks for collision in left cell
                    temp[i-1] = 1;
                } else {
                    printf("Collision in cell %i. \n", i);
                    temp[i-1] = 0;
                }
            } else {
                if(!temp[i+1]) { //cheks for collision in right cell
                    temp[i+1] = 1;
                } else {
                    printf("Collision in cell %i. \n", i+1);
                    temp[i+1] = 0;
                }
            }
        }
    } else { //sets corners of the array
        temp[i] = particles[i];
    }

}
    
    printf("Run %i: ", c); //prints the array of the current run
    for (int i = 0; i < sizeof(particles)/4; i++) {
        particles[i] = temp[i];
        printf("%i ", temp[i]);
    }
    printf("\n");
}
    

    return 0;
}