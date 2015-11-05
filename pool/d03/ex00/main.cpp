#include "FragTrap.hpp"
#include <iostream>
#include <cstdlib>

int    main(void) {
    srand(time(NULL));
    FragTrap a = FragTrap("T1MM7");
    FragTrap b = FragTrap("KR0T3");

    std::cout << "T1MM7 VS KR0T3 !" << std::endl;

    b.meleeAttack("T1MM7");
    a.takeDamage(b.getRangedAttackDamage());
    a.meleeAttack("KR0T3");
    b.takeDamage(a.getMeleeAttackDamage());
    b.vaulthunter_dot_exe("T1MM7");
    if (b.getEnergyPoints() >= 25)
        a.takeDamage(b.getMeleeAttackDamage());
    a.beRepaired(10);
    b.vaulthunter_dot_exe("T1MM7");
    if (b.getEnergyPoints() >= 25)
        a.takeDamage(b.getMeleeAttackDamage());
    a.beRepaired(10);
    b.meleeAttack("T1MM7");
    a.takeDamage(b.getMeleeAttackDamage());
    a.vaulthunter_dot_exe("KR0T3");
    if (a.getEnergyPoints() >= 25)
        b.takeDamage(a.getRangedAttackDamage());
    b.beRepaired(15);
    b.vaulthunter_dot_exe("T1MM7");
    if (b.getEnergyPoints() >= 25)
        a.takeDamage(b.getMeleeAttackDamage());
    a.meleeAttack("KR0T3");
    b.takeDamage(a.getMeleeAttackDamage());
    b.vaulthunter_dot_exe("T1MM7");
    if (b.getEnergyPoints() >= 25)
        a.takeDamage(b.getRangedAttackDamage());
    b.vaulthunter_dot_exe("T1MM7");
    if (b.getEnergyPoints() >= 25)
        a.takeDamage(b.getRangedAttackDamage());

    return (0);
}
