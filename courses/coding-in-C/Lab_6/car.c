#include <stdio.h>

typedef struct Car {
    float fuel_level;
    float max_fuel_level;
    char model[20];
};

void refuel(struct Car *car, float fuel) {
    if ((car->max_fuel_level - car->fuel_level) < fuel) {
        printf("You're trying to add to mouch fuel.\n");
        return;
    }

    car->fuel_level += fuel;

}

int main() {

    struct Car my_car = {10.5, 64, "BMW 3 Series e30 320i"};
    printf("My car has %2.1fL of Fuel.\n", my_car.fuel_level);
    refuel(&my_car, 20);
    printf("My car has %2.1fL of Fuel.\n", my_car.fuel_level);
}