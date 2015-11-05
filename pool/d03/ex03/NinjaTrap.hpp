#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class NinjaTrap : public ClapTrap {
    public:
        NinjaTrap(std::string Name);
        NinjaTrap(NinjaTrap const & src);
        ~NinjaTrap(void);

        NinjaTrap &  operator=(NinjaTrap const & rhs);

        void    rangedAttack(std::string const & target);
        void    meleeAttack(std::string const & target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        void    ninjaShoebox(ClapTrap cpt);
        void    ninjaShoebox(ScavTrap cpt);
        void    ninjaShoebox(FragTrap cpt);
        void    ninjaShoebox(NinjaTrap cpt);

    private:
        NinjaTrap(void);
};

#endif
