#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <string>
# include "NinjaTrap.hpp"
# include "FragTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap {
    public:
        SuperTrap(std::string Name);
        SuperTrap(SuperTrap const & src);
        ~SuperTrap(void);

        SuperTrap &  operator=(SuperTrap const & rhs);

        void    rangedAttack(std::string const & target);
        using FragTrap::rangedAttack;
        using NinjaTrap::meleeAttack;
        void    beRepaired(unsigned int amount);

    private:
        using ClapTrap::_Name;
        using FragTrap::_HitPoints;
        using FragTrap::_MaxHitPoints;
        using NinjaTrap::_EnergyPoints;
        using NinjaTrap::_MaxEnergyPoints;
        using NinjaTrap::_MeleeAttackDamage;
        using FragTrap::_RangedAttackDamage;
        using FragTrap::_ArmorDamageReduction;
        SuperTrap(void);
};

#endif
