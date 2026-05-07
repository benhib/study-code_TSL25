#ifndef CHARACTERS_HPP
#define CHARACTERS_HPP

#include <string>
#include <cstdint>
#include "Inventory.hpp"


//@brief abstract Character class
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
        @brief checks if a player should level up and levels them up

        @return void
        */
        virtual void levelUp() =0;


        /*
        @brief prints the stats of a Character (should be const, but if I add const, the entire code crashes WTF????)
        
        @return void
        */
        virtual Character& printInfo()  =0;

        /*
        @brief gets the health points of a character

        @return health points
        */
        const std::uint_least16_t getHP() const{
            return this->health_points;
        }


        /*
        @brief makes the Character take damage

        @param[1] damage: the damage the Character should take

        @return void
        */
        void takeDamage(std::uint_least16_t damage) {
            this->health_points -= damage;
        }


        /*
        @brief makes a Character attack a target and deals damage to the target

        @param[1] target: the Character to attack

        @return void
        */
        void attack(Character& target);


        /*
        @brief gets the level of the Character

        @return level
        */
        const std::uint_least16_t getLevel() const {
            return this->level;
        }

        /*
        @brief gets the name of the Character

        @return name
        */
        const std::string getName() const {
            return this->name;
        }


};


// @brief Mage class extending Character
class Mage : public Character {
    protected:
        std::uint_least16_t mana_points;

    public:
        Character& printInfo() override;

        /*
        @brief gives the Mage experience points and lets them level up

        @param[1] regen: the amount of experience/mana points to add

        @return *this
        */
        Mage& regenerateMana(std::uint_least16_t regen) {
            this->mana_points += regen;
            this->levelUp();
            return *this;
        }

        /*
        @brief creates a new Mage

        @param[1] name: the name to give the Mage

        @return new Mage
        */
        Mage(std::string name) : Character(name), mana_points(0) {};

        void levelUp() override;
};


//@brief Healer class extending Mage (friend of Character)
class Healer : public Mage {

    public:
        Character& printInfo() override;

        /*
        @brief creates a new Healer

        @param[1] name: the name to give the Healer

        @return new Healer
        */
        Healer(std::string name) : Mage(name){};

        /*
        @brief heals the target based on the level

        @param[1] target: the target to heal

        @return *this
        */
        Healer& heal(Character& target);
};

//@brief Warrior class extending Character
class Warrior : public Character {
    protected:
        std::uint_least16_t weapon_points;

    public:
        Character& printInfo() override;

        /*
        @brief gives the Warrior experience points and lets them level up

        @param[1] regen: the amount of experience/weapon points to add

        @return *this
        */
         Warrior& regenerateWeapon(std::uint_least16_t regen) {
            this->weapon_points += regen;
            this->levelUp();
            return *this;
        }

        void levelUp() override;

        /*
        @brief creates a new Warrior

        @param[1] name: the name to give the Warrior

        @return new Warrior
        */
        Warrior(std::string name) : Character(name), weapon_points(0){};
};

//@brief Thief class extending Warrior
class Thief : public Warrior {

    public:
        Character& printInfo() override;

        /*
        @brief lets the Thief steal the last item of the target, if conditions are met

        @param[1] target: the target to steal from

        @return *this
        */
        Thief& steal(Character& target);

        /*
        @brief creates a new Thief

        @param[1] name: the name to give the Thief

        @return new Thief
        */
        Thief(std::string name) : Warrior(name) {};
};


#endif