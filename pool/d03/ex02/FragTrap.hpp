#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
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

    private:
        FragTrap(void);
};

#endif
