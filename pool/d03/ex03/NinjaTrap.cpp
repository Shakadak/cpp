#include <iostream>
#include <string>
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) {
}

NinjaTrap::NinjaTrap(std::string Name) :
    ClapTrap(Name, 60, 60, 120, 120, 1, 60, 5, 0) {
    std::cout
        << Name
        << " sing : \"Teenage mutant ninja Robot ! Teenage mutant ninja Robot !\""
        << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src): ClapTrap(src) {
    std::cout
        << this->_Name
        << " says : \"Kage Bunshin no jutsu!\""
        << std::endl;
}

NinjaTrap::~NinjaTrap(void) {
    std::cout
        << this->_Name
        << " scream : \"I can't leave! I'm not ENOUGH of SCREW PIZZAS!\""
        << std::endl;
}

NinjaTrap &  NinjaTrap::operator=(NinjaTrap const & rhs) {
    this->_Name = rhs.getName();
    this->_HitPoints = rhs.getHitPoints();
    this->_MaxHitPoints = rhs.getMaxHitPoints();
    this->_EnergyPoints = rhs.getEnergyPoints();
    this->_MaxEnergyPoints = rhs.getMaxEnergyPoints();
    this->_Level = rhs.getLevel();
    this->_MeleeAttackDamage = rhs.getMeleeAttackDamage();
    this->_RangedAttackDamage = rhs.getRangedAttackDamage();
    this->_ArmorDamageReduction = rhs.getArmorDamageReduction();

    return (*this);
}

void   NinjaTrap::rangedAttack(std::string const & target) {
    std::cout
        << "NINJ4-TP "
        << this->_Name
        << " throw shurikens on "
        << target
        << " at range, causing "
        << this->_RangedAttackDamage
        << " points of damage !"
        << std::endl;
}

void   NinjaTrap::meleeAttack(std::string const & target) {
    std::cout
        << "NINJ4-TP "
        << this->_Name
        << " hit "
        << target
        << " without it seeing him move, causing "
        << this->_MeleeAttackDamage
        << " points of damage !"
        << std::endl;
}

void   NinjaTrap::takeDamage(unsigned int amount) {
    int  damages = ((amount - this->_ArmorDamageReduction) > 0) ? (amount - this->_ArmorDamageReduction) : 0;

    if (damages > 0)
        std::cout
            << "NINJ4-TP "
            << this->_Name
            << " recieved "
            << damages
            << " points of damage !"
            << std::endl;
    else
        std::cout
            << "NINJ4-TP "
            << this->_Name
            << " didn't take any damage!"
            << std::endl;
    this->setHitPoints(this->_HitPoints - damages);
    std::cout
        << this->_HitPoints
        << " hit points left."
        << std::endl;
}

void   NinjaTrap::beRepaired(unsigned int amount) {
    std::cout
        << "NINJ4-TP "
        << this->_Name
        << " was repaired for "
        << amount
        << " hit points and feels stealthy again."
        << std::endl;
    this->setHitPoints(this->_HitPoints + amount);
    std::cout
        << "He now has "
        << this->_HitPoints
        << " hit points."
        << std::endl;
}

void   NinjaTrap::ninjaShoebox(ClapTrap cpt) {
    std::cout
        <<"Ninja "
        << this->_Name
        << " hit ClapTrap "
        << cpt.getName()
        << "'s back."<< std::endl;
}

void   NinjaTrap::ninjaShoebox(ScavTrap cpt) {
    std::cout
        <<"Ninja "
        << this->_Name
        << " hit ScavTrap "
        << cpt.getName()
        << "'s eye."<< std::endl;
    return ;
}

void   NinjaTrap::ninjaShoebox(FragTrap cpt) {
    std::cout
        <<"Ninja "
        << this->_Name
        << " hit FragTrap "
        << cpt.getName()
        << "'s second antenna."<< std::endl;
}

void   NinjaTrap::ninjaShoebox(NinjaTrap cpt) {
    std::cout
        <<"Ninja "
        << this->_Name
        << " hit NinjaTrap "
        << cpt.getName()
        << "'s balls"<< std::endl;
}
