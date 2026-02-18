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

    int fuseddetection[DATAPOINTS];

    //File opener
    FILE *data1 = fopen("sensor1.txt", "r");
    FILE *data2 = fopen("sensor2.txt", "r");
    if (data1 == NULL || data2 == NULL) {
        printf("Error reading the files.\n");
        return -1;
    }

    
    //File reading and data processing 
    for (int i = 0; i < DATAPOINTS; i++)
    {
        //Tries reading sensor1.txt and saving read data
        if(fscanf(data1, "%f %lf", &psensor1->data[i].time, &psensor1->data[i].probability) != 2) {
            printf("Error getting data from file 1.\n");
            return -1;
        }

        //Determines object presence based of threshold for sensor 1
        if(psensor1->data[i].probability > psensor1->threshold) {
            psensor1->object_detection[i] = 1;
        } else {
            psensor1->object_detection[i] = 0;
        }
        
        //Tries reading sensor2.txt and saving read data
        if(fscanf(data2, "%f %lf", &psensor2->data[i].time, &psensor2->data[i].probability) != 2) {
            printf("Error getting data from file 2.\n");
            return -1;
        }

        //Determines object presence based of threshold for sensor 2
        if(psensor2->data[i].probability > psensor2->threshold) {
            psensor2->object_detection[i] = 1;
        } else {
            psensor2->object_detection[i] = 0;
        }

        //Checks if both sensors detect an object
        fuseddetection[i] = psensor2->object_detection[i] & psensor1->object_detection[i];
    }

    
    int start1 = 0;
    int start2 = 0;
    int startfused = 0;
    //Determines the detection intervalls for the sensors
    for (int i = 1; i < DATAPOINTS; i++)
    {
        //Checks if the object detection changed
        if (sensor1.object_detection[i-1] == 0 && sensor1.object_detection[i] == 1) {

            start1 = i;

        //Checks if the object detection changed again & failsave
        } else if (sensor1.object_detection[i-1] == 1 && sensor1.object_detection[i] == 0 && start1 != 0) {
            printf("Sensor 1 detected an object from %2.2fs until %2.2fs.\n", sensor1.data[start1].time, sensor1.data[i-1].time);
        }

        //Again for Sensor 2 and the fused value
        if (sensor2.object_detection[i-1] == 0 && sensor2.object_detection[i] == 1) {
            start2 = i;
        } else if (sensor2.object_detection[i-1] == 1 && sensor2.object_detection[i] == 0 && start2 != 0) {
            printf("Sensor 2 detected an object from %2.2fs until %2.2fs.\n", sensor2.data[start1].time, sensor2.data[i-1].time);
        }

        //Uses timestamp from sensor 1 since they are identical
        if(fuseddetection[i-1] == 0 && fuseddetection[i] == 1) {
            startfused = i;
        } else if (fuseddetection[i-1] == 1 && fuseddetection[i] == 0) {
            printf("Both sensors detected an object from %2.2fs until %2.2fs.\n", sensor1.data[startfused].time, sensor1.data[i-1].time);
        }

    }
    

    //File closing
    int close1 = fclose(data1);
    int close2 = fclose(data2);
    if (close1 == -1 || close2 == -1) {
        printf("Error closing files.\n");
        return -1;
    }
}