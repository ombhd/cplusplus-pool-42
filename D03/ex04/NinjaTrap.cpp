/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:09:18 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/10 11:42:21 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap()
{
	init();
	std::cout << "Sa~a, hajimeyou!" << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	init();
	std::cout << _name << ": Sashi Buri!" << std::endl;
	return ;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << _name << " : Proud of what I've done in my life!" << std::endl;
	return ;
}

NinjaTrap &NinjaTrap::operator=(const NinjaTrap &src)
{
	if (this == &src)
		return (*this);
	ClapTrap::operator=(src);
	return *this;
}

void			NinjaTrap::init(void)
{
	_hitPoints = 60;
	_maxHitPoints = 60;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_meleeAttackDamage = 60;
	_rangedAttackDamage = 5;
	_armorDamageReduction = 0;
}


// Attacks
void			NinjaTrap::ninjaShoebox(ClapTrap &clapTrap)
{
	if (!this->is_alive() || !clapTrap.is_alive())
		return ;
	if (this->getEnergyPoints() < 30)
	{
		std::cout << " 😰 Oh " << _name << "! You don't have much energy to perform the ninjaShoebox Attack" << std::endl;
		return ;
	}
	std::cout << "\n Ninja time!\n" << std::endl;
	sleep(2);
	this->setEnergyPoints(this->_energyPoints - 30);

	std::cout << "️ 🀄️ " << this->_name << ": " <<  clapTrap.getName() << "! Get ready to meet your destiny!" << std::endl;
	std::cout << std::endl;
	clapTrap.takeDamage(30);
	

	return ;
}

void			NinjaTrap::ninjaShoebox(FragTrap &clapTrap)
{
	if (!this->is_alive() || !clapTrap.is_alive())
		return ;
	if (this->getEnergyPoints() < 20)
	{
		std::cout << " 😰 Oh " << _name << "! You don't have much energy to perform the ninjaShoebox Attack" << std::endl;
		return ;
	}
	std::cout << "\n Ninja time!\n" << std::endl;
	sleep(2);
	this->setEnergyPoints(this->_energyPoints - 20);

	std::cout << "️ 🀄️ " << this->_name << ": " <<  clapTrap.getName() << "! Your prayers, praaayy..!!" << std::endl;
	std::cout << std::endl;
	clapTrap.takeDamage(20);
	

	return ;
}

void			NinjaTrap::ninjaShoebox(ScavTrap &clapTrap)
{
	if (!this->is_alive() || !clapTrap.is_alive())
		return ;
	if (this->getEnergyPoints() < 15)
	{
		std::cout << " 😰 Oh " << _name << "! You don't have much energy to perform the ninjaShoebox Attack" << std::endl;
		return ;
	}
	std::cout << "\n Ninja time!\n" << std::endl;
	sleep(2);
	this->setEnergyPoints(this->_energyPoints - 15);

	std::cout << "️ 🀄️ " << this->_name << ": " <<  clapTrap.getName() << "! what meme you wanna hear before you die!" << std::endl;
	std::cout << std::endl;
	clapTrap.takeDamage(15);
	

	return ;
}

void			NinjaTrap::ninjaShoebox(NinjaTrap &clapTrap)
{
		if (!this->is_alive() || !clapTrap.is_alive())
		return ;
	if (this->getEnergyPoints() < 10)
	{
		std::cout << " 😰 Oh " << _name << "! You don't have much energy to perform the ninjaShoebox Attack" << std::endl;
		return ;
	}
	std::cout << "\n Ninja time!\n" << std::endl;
	sleep(2);
	this->setEnergyPoints(this->_energyPoints - 10);

	std::cout << "️ 🀄️ " << this->_name << ": " <<  clapTrap.getName() << "! easy death or the hard one..?!" << std::endl;
	clapTrap.takeDamage(10);
	

	return ;
}

