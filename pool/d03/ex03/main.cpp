#include <cstdlib>
#include <iostream>
#include "NinjaTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int    main(void)
{
    srand(time(NULL));
    ScavTrap a = ScavTrap("T1MM7");
    FragTrap b = FragTrap("KR0T3");
    NinjaTrap c = NinjaTrap("Z3R0");
    NinjaTrap d = NinjaTrap("ST4N");
    NinjaTrap e = NinjaTrap(d);

    std::cout << "T1MM7 ..... VS ........ KR0T3 !" << std::endl;

    b.meleeAttack("T1MM7");
    a.takeDamage(b.getRangedAttackDamage());
    a.meleeAttack("KR0T3");
    b.takeDamage(a.getMeleeAttackDamage());
    b.vaulthunter_dot_exe("T1MM7");
    if (b.getEnergyPoints() >= 25)
        a.takeDamage(b.getMeleeAttackDamage());
    a.beRepaired(20);
    b.vaulthunter_dot_exe("T1MM7");
    if (b.getEnergyPoints() >= 25)
        a.takeDamage(b.getMeleeAttackDamage());
    a.beRepaired(20);
    b.meleeAttack("T1MM7");
    a.takeDamage(b.getMeleeAttackDamage());
    a.challengeNewcomer("KR0T3");
    b.beRepaired(15);
    b.vaulthunter_dot_exe("T1MM7");
    if (b.getEnergyPoints() >= 25)
        a.takeDamage(b.getMeleeAttackDamage());
    a.challengeNewcomer("KR0T3");
    a.meleeAttack("KR0T3");
    b.takeDamage(a.getMeleeAttackDamage());
    b.vaulthunter_dot_exe("T1MM7");
    if (b.getEnergyPoints() >= 25)
        a.takeDamage(b.getRangedAttackDamage());
    b.vaulthunter_dot_exe("T1MM7");
    if (b.getEnergyPoints() >= 25)
        a.takeDamage(b.getRangedAttackDamage());
    a.challengeNewcomer("ST4N");
    c.ninjaShoebox(a);
    e.ninjaShoebox(b);
    c.ninjaShoebox(d);
    return (0);
}
