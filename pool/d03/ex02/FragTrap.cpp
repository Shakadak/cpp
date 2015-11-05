#include <iostream>
#include <string>
#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
    std::cout << "Uninitialized FR4G-TP constructed." << std::endl;
}

FragTrap::FragTrap(std::string Name) :
    ClapTrap(Name, 100, 100, 100, 100, 1, 30, 20, 5) {
        std::cout << "FR4G-TP "
            << this->_Name
            << " constructed and initialized."
            << std::endl;
    }

FragTrap::FragTrap(FragTrap const & src) :
    ClapTrap(src._Name,
            src._HitPoints,
            src._MaxHitPoints,
            src._EnergyPoints,
            src._EnergyPoints,
            src._Level,
            src._MeleeAttackDamage,
            src._RangedAttackDamage,
            src._ArmorDamageReduction) {
        std::cout << "FR4G-TP "
            << this->_Name
            << " cloned. We wish you good luck if you ever want to order \
them separatly."
            << std::endl;
    }

FragTrap::~FragTrap(void) {
    std::cout << "FR4G-TP "
        << this->_Name
        << " unnaturally shutdown as early as expected. We hope you'll listen \
to us more intently next time."
        << std::endl;
}

FragTrap &  FragTrap::operator=(FragTrap const & rhs) {
        std::cout << "Replacing FR4G-TP "
            << this->_Name
            << " dataset with FR4G-TP "
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

void   FragTrap::rangedAttack(std::string const & target) {
    std::cout << "FR4G-TP "
        << this->_Name
        << " shoot on "
        << target
        << " at range, causing "
        << this->_RangedAttackDamage
        << " points of damage !"
        << std::endl;
}

void   FragTrap::meleeAttack(std::string const & target) {
    std::cout  << "FR4G-TP "
        << this->_Name
        << " brutally hit "
        << target
        << "'s antenna, causing "
        << this->_MeleeAttackDamage
        << " points of damage !"
        << std::endl;
}

void   FragTrap::takeDamage(unsigned int amount) {
    int  damages = ((amount - this->_ArmorDamageReduction) > 0) ? (amount - this->_ArmorDamageReduction) : 0;

    if (damages > 0)
        std::cout << "FR4G-TP "
            << this->_Name
            << " received "
            << damages
            << " points of damage !"
            << std::endl;
    else
        std::cout << "FR4G-TP "
            << this->_Name
            << "'s armor blocked all the damage!"
            << std::endl;

    this->setHitPoints(this->_HitPoints - damages);

    std::cout << this->_HitPoints
        << " hit points left."
        << std::endl;
}

void   FragTrap::beRepaired(unsigned int amount) {
    std::cout << "FR4G-TP "
        << this->_Name
        << " was repaired for "
        << amount
        << " hit points and feels good now."
        << std::endl;
    this->setHitPoints(this->_HitPoints + amount);
    std::cout << "He now has "
        << this->_HitPoints
        << " hit points."
        << std::endl;
}

void   FragTrap::vaulthunter_dot_exe(std::string const & target) {
    if (this->_EnergyPoints < 25)
        std::cout
            << this->_Name
            << " : \"You'll DIE Bi*** ! \
Oh Wait I'm Out of Energy... \
Be kind, don't move... we can talk if you want !\""
            << std::endl;
    else
    {
        int  rand_attack = rand() % 5;
        std::cout << "* BADASS MUSIC STARTED *" << std::endl;
        std::cout
            << "FR4G-TP "
            << this->_Name
            << " used a special attack, the \"";
        switch (rand_attack)
        {
            case 0 :
                std::cout << "Laser Pointer on Light Sensor";
                break;
            case 1 :
                std::cout << "Special Frying Pan, SFP !";
                break;
            case 2 :
                std::cout << "Gigantic Fly Swatter";
                break;
            case 3 :
                std::cout << "Short-Circuit";
                break;
            default :
                std::cout << "Directive three! Uhntssuhntssuhntss--";
                break;
        }
        std::cout << "\" on " << target << std::endl;
        std::cout <<"Guy watching : \" (╯°□°）╯︵ ┻━┻\""
            << std::endl;
        this->_EnergyPoints -= 25;
    }
}
