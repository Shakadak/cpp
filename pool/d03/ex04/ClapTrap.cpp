#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
    std::cout << "CL4P-TP assembled." << std::endl;
}

ClapTrap::ClapTrap(
        std::string Name,
        int HP, int MHP,
        int EP,
        int MEP,
        int LVL,
        int MAD,
        int RAD,
        int ADR) :
    _HitPoints(HP),
    _MaxHitPoints(MHP),
    _EnergyPoints(EP),
    _MaxEnergyPoints(MEP),
    _Level(LVL),
    _Name(Name),
    _MeleeAttackDamage(MAD),
    _RangedAttackDamage(RAD),
    _ArmorDamageReduction(ADR) {
        std::cout
            << this->_Name
            << " : \"Allow me to introduce myself, I'm CL4P-TP stewart bot, but my friends call me Claptrap!\""
            << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) :
    _HitPoints(src._HitPoints),
    _MaxHitPoints(src._MaxHitPoints),
    _EnergyPoints(src._EnergyPoints),
    _MaxEnergyPoints(src._EnergyPoints),
    _Level(src._Level),
    _Name(src._Name),
    _MeleeAttackDamage(src._MeleeAttackDamage),
    _RangedAttackDamage(src._RangedAttackDamage),
    _ArmorDamageReduction(src._ArmorDamageReduction) {
        std::cout
            << "AGAIN !? So I think it's time for me to leave..."
            << std::endl;
}

ClapTrap::~ClapTrap(void) {
    std::cout
        << this->_Name
        << " : \"IT'S THE END OF THE WORLD AS YOU KNOW IT...\""
        << std::endl;
}

ClapTrap &  ClapTrap::operator=(ClapTrap const & rhs) {
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

std::string  ClapTrap::getName(void) const {
    return (this->_Name);
}

int    ClapTrap::getHitPoints(void) const {
    return (this->_HitPoints);
}

int    ClapTrap::getMaxHitPoints(void) const {
    return (this->_MaxHitPoints);
}
int    ClapTrap::getEnergyPoints(void) const {
    return (this->_EnergyPoints);
}

int    ClapTrap::getMaxEnergyPoints(void) const {
    return (this->_MaxEnergyPoints);
}

int    ClapTrap::getLevel(void) const {
    return (this->_Level);
}

int    ClapTrap::getMeleeAttackDamage(void) const {
    return (this->_MeleeAttackDamage);
}

int    ClapTrap::getRangedAttackDamage(void) const {
    return (this->_RangedAttackDamage);
}

int    ClapTrap::getArmorDamageReduction(void) const {
    return (this->_ArmorDamageReduction);
}

void   ClapTrap::setName(std::string Name) {
    this->_Name = Name;
}

void   ClapTrap::setHitPoints(int HP) {
    if (HP > this->_MaxHitPoints || HP < 0)
        this->_HitPoints = (HP < 0) ? 0 : this->_MaxHitPoints;
    else
        this->_HitPoints = HP;
}

void   ClapTrap::setMaxHitPoints(int MHP) {
    if (MHP > 0)
        this->_MaxHitPoints = MHP;
}

void   ClapTrap::setEnergyPoints(int EP) {
    if (EP > this->_MaxEnergyPoints || EP < 0)
        this->_EnergyPoints = (EP < 0) ? 0 : this->_MaxEnergyPoints;
    else
        this->_EnergyPoints = EP;
}

void   ClapTrap::setMaxEnergyPoints(int MEP) {
    if (MEP > 0)
        this->_MaxEnergyPoints = MEP;
}

void   ClapTrap::setLevel(int LVL) {
    if (LVL > 1)
        this->_Level = LVL;
}

void   ClapTrap::setMeleeAttackDamage(int Dmg) {
    if (Dmg > 0)
        this->_MeleeAttackDamage = Dmg;
}

void   ClapTrap::setRangedAttackDamage(int Dmg) {
    if (Dmg > 0)
        this->_RangedAttackDamage = Dmg;
}

void   ClapTrap::setArmorDamageReduction(int Shield) {
    this->_ArmorDamageReduction = Shield;
}

void   ClapTrap::rangedAttack(std::string const & target) {
    std::cout
        << "CL4P-TP "
        << this->_Name
        << " attacks "
        << target
        << " at range, causing "
        << this->_RangedAttackDamage
        << " points of damage !"
        << std::endl;
}

void   ClapTrap::meleeAttack(std::string const & target) {
    std::cout
        << "CL4P-TP "
        << this->_Name
        << " attacks "
        << target
        << " in melee, causing "
        << this->_MeleeAttackDamage
        << " points of damage !"
        << std::endl;
}

void   ClapTrap::takeDamage(unsigned int amount) {
    int  damages = ((amount - this->_ArmorDamageReduction) > 0) ? (amount - this->_ArmorDamageReduction) : 0;

    if (damages > 0) {
        std::cout
            << "CL4P-TP "
            << this->_Name
            << " received "
            << damages
            << " damage points !"
            << std::endl; }
    else {
        std::cout
            << "CL4P-TP "
            << this->_Name
            << "'s armor blocked the entire attack!"
            << std::endl; }
    this->setHitPoints(this->_HitPoints - damages);
    std::cout
        << this->_HitPoints
        << " hit points left."
        << std::endl;
}

void   ClapTrap::beRepaired(unsigned int amount) {
    std::cout
        << "CL4P-TP "
        << this->_Name
        << " was repaired for "
        << amount
        << " hit points."
        << std::endl;
    this->setHitPoints(this->_HitPoints + amount);
    std::cout
        << "He now has "
        << this->_HitPoints
        << " hit points."
        << std::endl;
}
