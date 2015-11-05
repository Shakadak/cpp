#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap(std::string Name);
        ScavTrap(ScavTrap const & src);
        ~ScavTrap(void);

        ScavTrap &  operator=(ScavTrap const & rhs);

        void   rangedAttack(std::string const & target);
        void   meleeAttack(std::string const & target);
        void   takeDamage(unsigned int amount);
        void   beRepaired(unsigned int amount);
        void   challengeNewcomer(std::string const & target);

    private:
        ScavTrap(void);
};

#endif
