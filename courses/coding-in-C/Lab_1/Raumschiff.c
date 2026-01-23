#include <stdio.h>

char class[22];
unsigned crew;
unsigned int days;
unsigned long long distance = 38971985719;
float distance_light_speed = 14.8;
double range = 67823.562;
float test;

int main() {
    printf("Geben Sie die Klasse des Raumschiffs ein:\n");
    scanf("%s", class);
    printf("\nGeben Sie die Anzahl der Crew ein:\n");
    scanf("%i", &crew);
    printf("\nGeben Sie die Anzahl der Missionstage ein:\n");
    scanf("%i", &days);

    
    


    printf("\nName                           Value\n");
    printf("_________________________________________\n");
    printf("Class                         %s\n", class);
    printf("Crew Count                    %i\n", crew);
    printf("Mission Days                  %i\n", days);
    printf("Distance Travelled (km)       %lli\n", distance);
    printf("%% of Light-speed Travel       %.1f\n", distance_light_speed);
    printf("Current Range (km)            %.3f\n ", range);


    return 0;
}