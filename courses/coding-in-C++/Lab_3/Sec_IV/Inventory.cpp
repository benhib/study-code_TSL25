#include <string>
#include <iostream>
#include "Inventory.hpp"


Inventory::Inventory(Weapon weapon) : weapon(weapon), used_slots(0) {
            for (int i = 0; i < MAX_ITEMS; i++) {
                items[i] = "";
            }
        }

bool Inventory::isEmpty() const {
    return !used_slots;
}

bool Inventory::isFull() const {
    return used_slots == 10;
}

bool Inventory::addItem(const std::string& item) {
    if(this->isFull()) {
        std::cout << "Cannot add Item, full inventory\n";
        return false;
    } else {
        items[used_slots] = item;
        used_slots++;
        return true;
    }
}

bool Inventory::removeLastItem(std::string& item) {
    if(this->isEmpty()) {
            std::cout << "Cannot remove Item, empty inventory\n";
        return false;
    } else {
        for (int i = 1; i < MAX_ITEMS; i++) {
            used_slots--;
            item = items[used_slots];
            items[used_slots] = "";
            return true;
        }
    }
}
