#include <cstdint>
#include <string>
#include <iostream>
#include "Characters.hpp"
#include "Inventory.hpp"
#include <cmath>

std::uint_least16_t Character::player_count = 0;

Character::Character(std::string name) : name(name), level(1), health_points(DEF_HP) , inventory(Inventory(Weapon("Stick", 1))){
            this->id = Character::player_count;
            Character::player_count++;
}

void Character::attack(Character& target) {
    std::uint_least16_t damage = std::floor(this->getInventory().getWeaponDamage() * 
                                this->level / target.level); //game mechanik to determine the damage done to an opponent
    
    std::cout << this->name << " attacked " << target.name << " for " << damage << " HP\n";
    
    target.takeDamage(damage);
}


void Mage::levelUp() {
    if(this->mana_points >= LVL_STAGES[this->level-1]) {
        this->level++;
        this->levelUp();
    }
}

void Warrior::levelUp() {
    if(this->weapon_points >= LVL_STAGES[this->level-1]) {
        this->level++;
        this->levelUp();
    }
}

Thief& Thief::steal(Character& target) {
    if(target.getLevel() <= this->level + 1) {

        if(target.getInventory().isEmpty()) {
            std::cout << this->name << " failed to steal from " << target.getName() 
                      << " (empty Inventory)" << std::endl;
            return *this;
        }

        if(this->getInventory().isFull()) {
            std::cout << this->name << " has full inventory" << std::endl;
            return *this;
        }

        std::string item;
        bool success = target.getInventory().removeLastItem(item);

        if(success) {
            this->getInventory().addItem(item);
            std::cout << this->name << " stole " << item 
                      << " from " << target.getName() << std::endl;
            return *this;
        }

        std::cout << this->name << " failed to steal from " 
                  << target.getName() << std::endl;
        return *this;
    }

    std::cout << this->name << " failed to steal from " << target.getName() 
              << " (target level too high)" << std::endl;
    return *this;
}

Healer& Healer::heal(Character& target) {
    target.health_points += this->level * 5; // A healer heals 5x his level in hp

    std::cout << this->name << " healed " << target.name << " for " << this->level * 5 << " hp\n";
    return *this;
}

Character& Mage::printInfo() {
    using namespace std;

    cout << "---------------------------------\n";
    cout << "Name: " << this->name << endl;
    cout << "Type: Mage\n";
    cout << "Level: " << this->level << endl;
    cout << "Health Points: " << this->getHP() << endl;
    cout << "Magic Points: " << this->mana_points << endl;
    cout << "Current Weapon: " <<  this->getInventory().getWeaponName() << " | Damage: " << this->getInventory().getWeaponDamage() << endl;
    cout << "Items In Inventory: " << this->getInventory().getItemCount() << endl;
    cout << "---------------------------------\n\n";

    return *this;
}

Character& Healer::printInfo() {
    using namespace std;

    cout << "---------------------------------\n";
    cout << "Name: " << this->name << endl;
    cout << "Type: Healer\n";
    cout << "Level: " << this->level << endl;
    cout << "Health Points: " << this->getHP() << endl;
    cout << "Magic Points: " << this->mana_points << endl;
    cout << "Current Weapon: " <<  this->getInventory().getWeaponName() << " | Damage: " << this->getInventory().getWeaponDamage() << endl;
    cout << "Items In Inventory: " << this->getInventory().getItemCount() << endl;
    cout << "---------------------------------\n\n";

    return *this;
}

Character& Warrior::printInfo() {
    using namespace std;

    cout << "---------------------------------\n";
    cout << "Name: " << this->name << endl;
    cout << "Type: Warrior\n";
    cout << "Level: " << this->level << endl;
    cout << "Health Points: " << this->getHP() << endl;
    cout << "Weapon Skill Points: " << this->weapon_points << endl;
    cout << "Current Weapon: " <<  this->getInventory().getWeaponName() << " | Damage: " << this->getInventory().getWeaponDamage() << endl;
    cout << "Items In Inventory: " << this->getInventory().getItemCount() << endl;
    cout << "---------------------------------\n\n";

    return *this;
}

Character& Thief::printInfo() {
    using namespace std;

    cout << "---------------------------------\n";
    cout << "Name: " << this->name << endl;
    cout << "Type: Thief\n";
    cout << "Level: " << this->level << endl;
    cout << "Health Points: " << this->getHP() << endl;
    cout << "Weapon Skill Points: " << this->weapon_points << endl;
    cout << "Current Weapon: " <<  this->getInventory().getWeaponName() << " | Damage: " << this->getInventory().getWeaponDamage() << endl;
    cout << "Items In Inventory: " << this->getInventory().getItemCount() << endl;
    cout << "---------------------------------\n\n";

    return *this;
}