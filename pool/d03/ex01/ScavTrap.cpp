#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
    std::cout << "Uninitialized CL4P-TP dicovered." << std::endl;
}

ScavTrap::ScavTrap(std::string Name) :
    _HitPoints(100),
    _MaxHitPoints(100),
    _EnergyPoints(100),
    _MaxEnergyPoints(100),
    _Level(1),
    _Name(Name),
    _MeleeAttackDamage(30),
    _RangedAttackDamage(20),
    _ArmorDamageReduction(5) {
        std::cout << "SC4V-TP "
            << this->_Name
            << " discovered and reinitialized. Scavenge along."
            << std::endl;
    }

ScavTrap::ScavTrap(ScavTrap const & src) :
    _HitPoints(src._HitPoints),
    _MaxHitPoints(src._MaxHitPoints),
    _EnergyPoints(src._EnergyPoints),
    _MaxEnergyPoints(src._EnergyPoints),
    _Level(src._Level),
    _Name(src._Name),
    _MeleeAttackDamage(src._MeleeAttackDamage),
    _RangedAttackDamage(src._RangedAttackDamage),
    _ArmorDamageReduction(src._ArmorDamageReduction) {
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

std::string  ScavTrap::getName(void) const {
    return (this->_Name);
}
int    ScavTrap::getHitPoints(void) const {
    return (this->_HitPoints);
}

int    ScavTrap::getMaxHitPoints(void) const {
    return (this->_MaxHitPoints);
}
int    ScavTrap::getEnergyPoints(void) const {
    return (this->_EnergyPoints);
}

int    ScavTrap::getMaxEnergyPoints(void) const {
    return (this->_MaxEnergyPoints);
}

int    ScavTrap::getLevel(void) const {
    return (this->_Level);
}

int    ScavTrap::getMeleeAttackDamage(void) const {
    return (this->_MeleeAttackDamage);
}

int    ScavTrap::getRangedAttackDamage(void) const {
    return (this->_RangedAttackDamage);
}

int    ScavTrap::getArmorDamageReduction(void) const {
    return (this->_ArmorDamageReduction);
}
void   ScavTrap::setName(std::string Name) {
    this->_Name = Name;
}

void   ScavTrap::setHitPoints(int HP) {
    if (HP > this->_MaxHitPoints || HP < 0)
        this->_HitPoints = (HP < 0) ? 0 : this->_MaxHitPoints;
    else
        this->_HitPoints = HP;
}

void   ScavTrap::setMaxHitPoints(int MHP) {
    if (MHP > 0)
        this->_MaxHitPoints = MHP;
}

void   ScavTrap::setEnergyPoints(int EP) {
    if (EP > this->_MaxEnergyPoints || EP < 0)
        this->_EnergyPoints = (EP < 0) ? 0 : this->_MaxEnergyPoints;
    else
        this->_EnergyPoints = EP;
}

void   ScavTrap::setMaxEnergyPoints(int MEP) {
    if (MEP > 0)
        this->_MaxEnergyPoints = MEP;
}

void   ScavTrap::setLevel(int LVL) {
    if (LVL > 1)
        this->_Level = LVL;
}

void   ScavTrap::setMeleeAttackDamage(int Dmg) {
    if (Dmg > 0)
        this->_MeleeAttackDamage = Dmg;
}

void   ScavTrap::setRangedAttackDamage(int Dmg) {
    if (Dmg > 0)
        this->_RangedAttackDamage = Dmg;
}

void   ScavTrap::setArmorDamageReduction(int Shield) {
    this->_ArmorDamageReduction = Shield;
}

void   ScavTrap::rangedAttack(std::string const & target) {
    std::cout << "SC4V-TP "
        << this->_Name
        << " shoot on "
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
