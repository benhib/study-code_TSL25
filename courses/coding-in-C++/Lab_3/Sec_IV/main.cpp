#include "Characters.hpp"
#include "Inventory.hpp"

int main() {
    Warrior warrior = Warrior("Braker");
    Mage mage = Mage("Warden");
    Healer healer = Healer("Astrus");
    Thief thief = Thief("Hubs");

    warrior.getInventory().newWeapon(Weapon("Rusty Sword", 5));
    mage.getInventory().newWeapon(Weapon("Basic Staff", 5));
    healer.getInventory().newWeapon(Weapon("Advanced Staff", 7));
    thief.getInventory().newWeapon(Weapon("Old Dagger", 7));

    warrior.attack(mage);

    healer.heal(healer);
    
    
    warrior.getInventory().addItem("Berries");
    healer.getInventory().addItem("Questionable Mushrooms");

    
    thief.steal(warrior);

    thief.printInfo();
    healer.printInfo();
    warrior.printInfo();
    mage.printInfo();

    /*
    mage.regenerateMana(5);
    warrior.regenerateWeapon(10);
    healer.regenerateMana(100);
    thief.regenerateWeapon(30);

    thief.steal(healer).printInfo();
    healer.heal(mage).printInfo();
    warrior.printInfo();
    mage.printInfo();
    */

    
}