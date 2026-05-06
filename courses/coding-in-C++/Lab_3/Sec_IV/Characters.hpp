#ifndef CHARACTERS_HPP
#define CHARACTERS_HPP

#include <string>
#include <cstdint>
#include "Inventory.hpp"

class Character {
    friend class Healer;

    private:
        std::uint_least16_t health_points;

    protected:
        std::uint_least16_t id;
        static constexpr std::uint_least16_t MAX_LVL = 10;
        static constexpr std::uint_least16_t DEF_HP = 100;
        static constexpr std::uint_least16_t LVL_STAGES[] = {5, 10, 20, 30, 50 , 75, 100, 150, 200}; //set by choise, the point, where you get leveled up
        static std::uint_least16_t player_count;
        std::string name;
        std::uint_least16_t level;
        Inventory inventory;


    public:
        /*
        @brief creates new Character with a base level of 1 and a base Weapon 

        @param[1] name: the name of the Character
        */
        Character(std::string name);

        /*
        @brief gets the player_count

        @return player_count
        */
        std::uint_least16_t getPlayerCount() const{
            return Character::player_count;
        }

        /*
        @brief gets the Inventory of a Character

        @return inventory
        */
        Inventory& getInventory() {
            return this->inventory;
        }


        /*
        @brief checks if a player should level up

        @return void
        */
        virtual void levelUp() =0;


        /*
        @brief prints the stats of a Character (should be const, but if I add const, the entire code crashes WTF????)
        
        @return void
        */
        virtual Character& printInfo()  =0;

        std::uint_least16_t getHP() const{
            return this->health_points;
        }

        void takeDamage(std::uint_least16_t damage) {
            this->health_points -= damage;
        }

        void attack(Character& target);

        std::uint_least16_t getLevel() const {
            return this->level;
        }

        std::string getName() const {
            return this->name;
        }


};



class Mage : public Character {
    protected:
        std::uint_least16_t mana_points;

    public:
        Character& printInfo() override;

        Mage& regenerateMana(std::uint_least16_t regen) {
            this->mana_points += regen;
            this->levelUp();
            return *this;
        }

        Mage(std::string name) : Character(name), mana_points(0) {};

        void levelUp() override;
};

class Healer : public Mage {
    friend Character;

    public:
        Character& printInfo() override;


        Healer(std::string name) : Mage(name){};

        Healer& heal(Character& target);
};

class Warrior : public Character {
    protected:
        std::uint_least16_t weapon_points;

    public:
        Character& printInfo() override;

         Warrior& regenerateWeapon(std::uint_least16_t regen) {
            this->weapon_points += regen;
            this->levelUp();
            return *this;
        }

        void levelUp() override;

        Warrior(std::string name) : Character(name){};
};

class Thief : public Warrior {

    public:
        Character& printInfo() override;

        Thief& steal(Character& target);

        Thief(std::string name) : Warrior(name) {};
};


#endif