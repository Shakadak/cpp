#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>

class FragTrap {
    public:
        FragTrap(std::string Name);
        FragTrap(FragTrap const & src);
        ~FragTrap(void);

        FragTrap &  operator=(FragTrap const & rhs);

        void   rangedAttack(std::string const & target);
        void   meleeAttack(std::string const & target);
        void   takeDamage(unsigned int amount);
        void   beRepaired(unsigned int amount);
        void   vaulthunter_dot_exe(std::string const & target);

        int    getHitPoints(void) const;
        int    getMaxHitPoints(void) const;
        int    getEnergyPoints(void) const;
        int    getMaxEnergyPoints(void) const;
        int    getLevel(void) const;
        std::string  getName(void) const;
        int    getMeleeAttackDamage(void) const;
        int    getRangedAttackDamage(void) const;
        int    getArmorDamageReduction(void) const;

    private:
        int    _HitPoints;
        int    _MaxHitPoints;
        int    _EnergyPoints;
        int    _MaxEnergyPoints;
        int    _Level;
        std::string  _Name;
        int    _MeleeAttackDamage;
        int    _RangedAttackDamage;
        int    _ArmorDamageReduction;

        FragTrap(void);

    protected:
        void   setHitPoints(int HP);
        void   setMaxHitPoints(int MHP);
        void   setEnergyPoints(int EP);
        void   setMaxEnergyPoints(int MEP);
        void   setLevel(int LVL);
        void   setName(std::string Name);
        void   setMeleeAttackDamage(int Dmg);
        void   setRangedAttackDamage(int Dmg);
        void   setArmorDamageReduction(int Shield);
};

#endif
