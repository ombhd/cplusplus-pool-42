/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:54:04 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/17 19:10:25 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

#include <unistd.h>

void	sep()
{
	std::cout << std::endl;
	usleep(500000);
}

int main()
{
	// Character 
    Character* nkki = new Character("nkki");
    std::cout << *nkki;
	sep();
	
	// Weapons
    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();

	// Enemies
    Enemy* rad = new RadScorpion();
	sep();
    Enemy* super = new SuperMutant();
	sep();
	// equip weapons to character nkki
    nkki->equip(pr);
    std::cout << *nkki;
	sep();
    nkki->equip(pf);
    std::cout << *nkki;
    sep();
    if (rad)
        std::cout << rad->getType() << " has " << rad->getHP() << " HP." << std::endl;
    sep();
    nkki->attack(rad);
    sep();

	nkki->recoverAP();
    sep();
	std::cout << *nkki;
    sep();
	
    if (rad)
        std::cout << rad->getType() << " has " << rad->getHP() << " HP." << std::endl;
    sep();
    std::cout << *nkki;
    sep();
    nkki->equip(pr);
    sep();
    std::cout << *nkki;
    sep();
    nkki->attack(rad);
    sep();
    if (rad)
        std::cout << rad->getType() << " has " << rad->getHP() << " HP." << std::endl;
    sep();
    std::cout << *nkki;
    sep();
    nkki->attack(rad);
    sep();
    std::cout << *nkki;
    sep();

    nkki->equip(pf);
    sep();
    std::cout << *nkki;
    sep();
    std::cout << super->getType() << " has " << super->getHP() << " HP." << std::endl;
    sep();
    nkki->attack(super);
    sep();
    std::cout << super->getType() << " has " << super->getHP() << " HP." << std::endl;
    sep();
    std::cout << *nkki;
    sep();
    nkki->attack(super);
    sep();
    std::cout << super->getType() << " has " << super->getHP() << " HP." << std::endl;
    sep();
    std::cout << *nkki;
    sep();
    nkki->attack(super);
    sep();
    std::cout << super->getType() << " has " << super->getHP() << " HP." << std::endl;
    sep();
    std::cout << *nkki;
    sep();

    delete nkki;
    sep();
    delete super;
    sep();
	// delete rad;
    delete pr;
    delete pf;
    return 0;
}