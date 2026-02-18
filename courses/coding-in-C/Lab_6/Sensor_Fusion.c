#include <stdio.h>

enum { DATAPOINTS = 3000 };   

typedef struct SensorData{
    float time;
    double probability;
} SensorData;

typedef struct Sensor {
    int id;
    double threshold;
    SensorData data[DATAPOINTS];
    int object_detection[DATAPOINTS];
} Sensor;


int main () {
    struct Sensor sensor1 = {1, 0.8};
    struct Sensor *psensor1 = &sensor1;

    struct Sensor sensor2 = {2, 0.7};
    struct Sensor *psensor2 = &sensor2;

    FILE *data1 = fopen("sensor1.txt", "r");
    FILE *data2 = fopen("sensor2.txt", "r");
    if (data1 == NULL || data2 == NULL) {
        printf("Fehler beim Einlesen der Datei.\n");
        return -1;
    }

    

    for (int i = 0; i < DATAPOINTS; i++)
    {
        if(fscanf(data1, "%f %lf", &psensor1->data[i].time, &psensor1->data[i].probability) != 2) {
            printf("Fehler beim Auswerten der Daten1.\n");
            return -1;
        }
        
        if(fscanf(data2, "%f %lf", &psensor2->data[i].time, &psensor2->data[i].probability) != 2) {
            printf("Fehler beim Auswerten der Daten1.\n");
            return -1;
        }
    }
    

    int close1 = fclose(data1);
    int close2 = fclose(data2);
    if (close1 == -1 || close2 == -1) {
        printf("Fehler beim Schließen der Datei.\n");
        return -1;
    }
}