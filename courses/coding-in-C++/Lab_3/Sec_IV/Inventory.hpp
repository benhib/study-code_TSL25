#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <string>
#include <cstdint>

// @brief Weapon class 
class Weapon{
    private:
        std::string name;
        std::uint_least16_t damage;
    public:
        /*
        @brief creates a Weapon with name and damage

        @param[1] name: the name of the Weapon
        @param[2] damage: the damage of the Weapon

        @return the created weapon
        */
        Weapon(std::string name, int damage): name(name), damage(damage) {}

        /*
        @brief gets the name of the Weapon

        @return name of the Weapon
        */
        const std::string& getWeaponName() const{
            return  this->name;
        }

        /*
        @brief gets the damage of the Weapon

        @return damage of the Weapon
        */
        const std::uint_least16_t& getWeaponDamage() const{
            return  this->damage;
        }

};

//@brief Inventory class 
class Inventory {
    private:
        static constexpr std::uint_least16_t MAX_ITEMS = 10;
        std::uint_least16_t used_slots;
        std::string items[MAX_ITEMS];
        Weapon weapon;
        

    public:
        /*
        @brief creates an Inventory with a weapon and empty items
        
        @param[1] weapon: the weapon of the inventory

        @return the created Inventory
        */
        Inventory(Weapon weapon);

        /*
        @brief checks if the Inventory is full

        @return true if full, else false
        */
        bool isFull() const;

        /*
        @brief checks if the Inventory is empty

        @return true if empt, else false
        */
        bool isEmpty() const;

        /*
        @brief adds an item to the Inventory if possible

        @param[1] item: reference to the name of the Item 

        @return true if the item could be added, else false
        */
        bool addItem(const std::string& item);

        /*
        @brief removes the last item of the Inventory if possible

        @param[1] item: reference to where the removed item should be stored

        @return true if the item could be removed, else false
        */
        bool removeLastItem(std::string& item);

        /*
        @brief gets the name of the Weapon

        @return name of the Weapon
        */
        const std::string& getWeaponName() const {
            return this->weapon.getWeaponName();
        }

        /*
        @brief gets the damage of the Weapon

        @return damage of the Weapon
        */
        const std::uint_least16_t& getWeaponDamage() const{
            return  this->weapon.getWeaponDamage();
        }

        /*
        @brief sets the Weapon to a new one

        @param[1] weapon: the new weapon

        @return void
        */
        void newWeapon(Weapon weapon) {
            this->weapon = weapon;
        }

        /*
        @brief gets the used slots

        @return the used slots
        */
       std::uint_least16_t getItemCount() const{
            return this->used_slots;
       }


};


#endif