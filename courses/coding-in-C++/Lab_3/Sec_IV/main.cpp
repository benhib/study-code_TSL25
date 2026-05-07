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
    thief.steal(mage);
    healer.heal(healer);
    
    
    warrior.getInventory().addItem("Berries");
    healer.getInventory().addItem("Questionable Mushrooms");

    
    thief.steal(warrior);

    thief.printInfo();
    healer.printInfo();
    warrior.printInfo();
    mage.printInfo();

    
    mage.regenerateMana(5);
    warrior.regenerateWeapon(10);
    healer.heal(mage).regenerateMana(100);
    thief.steal(healer).regenerateWeapon(30);

    warrior.printInfo();
    mage.printInfo();

    thief.steal(mage);

    thief.getInventory().addItem("Wheat");
    thief.getInventory().addItem("Bread");
    thief.getInventory().addItem("Mushrooms");
    thief.getInventory().addItem("Water");
    thief.getInventory().addItem("Healing Potion");
    thief.getInventory().addItem("Flintstone");
    thief.getInventory().addItem("Leaves");
    thief.getInventory().addItem("Spoon");
    thief.getInventory().addItem("Metal");

    thief.getInventory().addItem("Wheat");

    mage.getInventory().addItem("Berries");

    thief.steal(mage);

    thief.printInfo();
    

    return 0;
}

/*
Braker attacked Warden for 5 HP
Astrus healed Astrus for 5 hp
Hubs stole Berries from Braker
---------------------------------
Name: Hubs
Type: Thief
Level: 1
Health Points: 100
Weapon Skill Points: 0
Current Weapon: Old Dagger | Damage: 7
Items In Inventory: 1
---------------------------------
---------------------------------
Name: Astrus
Type: Healer
Level: 1
Health Points: 105
Magic Points: 0
Current Weapon: Advanced Staff | Damage: 7
Items In Inventory: 1
---------------------------------
---------------------------------
Name: Braker
Type: Warrior
Level: 1
Health Points: 100
Weapon Skill Points: 0
Current Weapon: Rusty Sword | Damage: 5
Items In Inventory: 0
---------------------------------
---------------------------------
Name: Warden
Type: Mage
Level: 1
Health Points: 95
Magic Points: 0
Current Weapon: Basic Staff | Damage: 5
Items In Inventory: 0
---------------------------------
Astrus healed Warden for 5 hp
Hubs failed to steal from Astrus (target level too high)
---------------------------------
Name: Hubs
Type: Thief
Level: 5
Health Points: 100
Weapon Skill Points: 30
Current Weapon: Old Dagger | Damage: 7
Items In Inventory: 1
---------------------------------
Astrus healed Warden for 40 hp
---------------------------------
Name: Astrus
Type: Healer
Level: 8
Health Points: 105
Magic Points: 100
Current Weapon: Advanced Staff | Damage: 7
Items In Inventory: 1
---------------------------------
---------------------------------
Name: Braker
Type: Warrior
Level: 3
Health Points: 100
Weapon Skill Points: 10
Current Weapon: Rusty Sword | Damage: 5
Items In Inventory: 0
---------------------------------
---------------------------------
Name: Warden
Type: Mage
Level: 2
Health Points: 140
Magic Points: 5
Current Weapon: Basic Staff | Damage: 5
Items In Inventory: 0
---------------------------------
*/