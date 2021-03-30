/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:09:18 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/30 13:34:34 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
{
	init();
	std::cout << "SuperCyborg is here!" << std::endl;
	return ;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	init();
	std::cout << _name << ": Hey, Am I the ONLY SuperCyborg here!" << std::endl;
	return ;
}

SuperTrap::SuperTrap(const SuperTrap &src)
{
	*this = src;
}

SuperTrap::~SuperTrap()
{
	std::cout << _name << " : SuperCyborg is dead!" << std::endl;
	return ;
}

SuperTrap &SuperTrap::operator=(const SuperTrap &src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	return *this;
}

void			SuperTrap::init(void)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_meleeAttackDamage = 60;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
}


// Attacks

void			SuperTrap::rangedAttack(std::string const & target)
{
	FragTrap::rangedAttack(target);
}

void			SuperTrap::meleeAttack(std::string const & target)
{
	NinjaTrap::meleeAttack(target);
}

