#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
    std::cout << "Uninitialized CL4P-TP dicovered." << std::endl;
}

ScavTrap::ScavTrap(std::string Name) :
    ClapTrap(Name, 100, 100, 100, 100, 1, 30, 20, 5) {
        std::cout << "SC4V-TP "
            << this->_Name
            << " discovered and reinitialized. Scavenge along."
            << std::endl;
    }

ScavTrap::ScavTrap(ScavTrap const & src) :
    ClapTrap(src._Name,
            src._HitPoints,
            src._MaxHitPoints,
            src._EnergyPoints,
            src._EnergyPoints,
            src._Level,
            src._MeleeAttackDamage,
            src._RangedAttackDamage,
            src._ArmorDamageReduction) {
        std::cout << "SC4V-TP "
            << this->_Name
            << " cloned. We wish you good luck if you ever want to order \
them separatly."
            << std::endl;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "SC4V-TP "
        << this->_Name
        << " short-circuited for good."
        << std::endl;
}

ScavTrap &  ScavTrap::operator=(ScavTrap const & rhs) {
        std::cout << "Replacing SC4V-TP "
            << this->_Name
            << " dataset with SC4V-TP "
            << rhs.getName()
            << "'s one. We do not hold responsible for any trouble ensuing."
            << std::endl;
        this->_HitPoints = rhs.getHitPoints();
        this->_MaxHitPoints = rhs.getMaxHitPoints();
        this->_EnergyPoints = rhs.getEnergyPoints();
        this->_MaxEnergyPoints = rhs.getMaxEnergyPoints();
        this->_Level = rhs.getLevel();
        this->_Name = rhs.getName();
        this->_MeleeAttackDamage = rhs.getMeleeAttackDamage();
        this->_RangedAttackDamage = rhs.getRangedAttackDamage();
        this->_ArmorDamageReduction = rhs.getArmorDamageReduction();
        return (*this);
}

void   ScavTrap::rangedAttack(std::string const & target) {
    std::cout
        << "SC4V-TP "
        << this->_Name
        << " attacks "
        << target
        << " at range, causing "
        << this->_RangedAttackDamage
        << " points of damage !"
        << std::endl;
}

void   ScavTrap::meleeAttack(std::string const & target) {
    std::cout  << "SC4V-TP "
        << this->_Name
        << " brutally hit "
        << target
        << "'s antenna, causing "
        << this->_MeleeAttackDamage
        << " points of damage !"
        << std::endl;
}

void   ScavTrap::takeDamage(unsigned int amount) {
    int  damages = ((amount - this->_ArmorDamageReduction) > 0) ? (amount - this->_ArmorDamageReduction) : 0;

    if (damages > 0)
        std::cout << "SC4V-TP "
            << this->_Name
            << " received "
            << damages
            << " points of damage !"
            << std::endl;
    else
        std::cout << "SC4V-TP "
            << this->_Name
            << "'s armor blocked all the damage!"
            << std::endl;

    this->setHitPoints(this->_HitPoints - damages);

    std::cout << this->_HitPoints
        << " hit points left."
        << std::endl;
}

void   ScavTrap::beRepaired(unsigned int amount) {
    std::cout << "SC4V-TP "
        << this->_Name
        << " was repaired for "
        << amount
        << " hit points and feels volted up now."
        << std::endl;
    this->setHitPoints(this->_HitPoints + amount);
    std::cout << "He now has "
        << this->_HitPoints
        << " hit points."
        << std::endl;
}

void   ScavTrap::challengeNewcomer(std::string const & target) {
    if (this->_EnergyPoints < 25)
        std::cout
            << this->_Name
            << " : \"Sorry, I'm not in the mood to care about you.\""
            << std::endl;
    else
    {
        int  rand_attack = rand() % 5;
        std::cout << "* DEEP FOGHORN *"
            << std::endl
            << "\"BRRRRRRRAAAAAWWWWRWRRRMRMRMMRMRMMMMM!!!\""
            << std::endl
            << "SC4V-TP "
            << this->_Name
            << ": \"I challenge " << target << " to a duel of ";
        switch (rand_attack)
        {
            case 0 :
                std::cout << "Worm Eating";
                break;
            case 1 :
                std::cout << "Shooting Star Catching";
                break;
            case 2 :
                std::cout << "Lava Swimming";
                break;
            case 3 :
                std::cout << "";
                break;
            default :
                std::cout << "Dancing: Uhntssuhntssuhntss--";
                break;
        }
        std::cout << " \"" << std::endl;
        std::cout << "Guy watching : \" (╯°□°）╯︵ ┻━┻\""
            << std::endl;
        this->_EnergyPoints -= 25;
    }
}
