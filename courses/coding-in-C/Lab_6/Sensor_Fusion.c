#include <stdio.h>

const int DATAPOINTS = 3000;

typedef struct SensorData{
    float time;
    double probability;
} ;

typedef struct Sensor {
    int id;
    double threshold;
    struct SensorData data[DATAPOINTS];
    int object_detection[];
};


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
        if(fscanf(data1, "%f %f", psensor1->data->time + i, psensor1->data->probability + i) != 2) {
            printf("Fehler beim Auswerten der Daten.\n");
            return -1;
        }
        if(fscanf(data2, "%f %f", psensor2->data->time + i, psensor2->data->probability + i) != 2) {
            printf("Fehler beim Auswerten der Daten.\n");
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