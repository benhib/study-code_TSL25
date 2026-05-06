#include <string>
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
        return false;
    } else {
        used_slots++;
        items[used_slots] = item;
        return true;
    }
}

bool Inventory::removeLastItem(std::string& item) {
    if(this->isEmpty()) {
        return false;
    } else {
        for (int i = 1; i < MAX_ITEMS; i++) {
            items[used_slots] = "";
            used_slots--;
            return true;
        }
    }
}
