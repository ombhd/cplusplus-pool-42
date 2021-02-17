/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:53:26 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/17 18:47:04 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : 
_name("default"),
_actionPoints(MAX_AP),
_weapon(NULL)
{
	return ;
}

Character::Character(std::string const & name) :
_name(name),
_actionPoints(MAX_AP),
_weapon(NULL)
{
	return ;
}

Character::Character(const Character &src)
{
	*this = src;
	return ;
}

Character::~Character()
{
	return ;
}

Character &Character::operator=(const Character &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_actionPoints = src._actionPoints;
		this->_weapon = src._weapon;
	}
	return *this;
}

void Character::recoverAP()
{
	if (this->_actionPoints + 10 > MAX_AP)
		this->_actionPoints = MAX_AP;
	else
		this->_actionPoints += 10;
	return ;
}

void Character::equip(AWeapon* wp)
{
	this->_weapon = wp;
	return ;
}

void Character::attack(Enemy* enemy)
{
	if (!this->_weapon)
	{
		std::cout << "No weapon to attack with 😰" << std::endl;
		return ;
	}
	if (this->_weapon && this->_weapon->getAPCost() > this->_actionPoints)
	{
		std::cout << "No enough AP 😰" << std::endl;
		return ;
	}

	std::cout << this->_name << " attacks " << enemy->getType() 
			  << " with a " << this->_weapon->getName() << std::endl;
	this->_weapon->attack();  
	// AP cost
	if (this->_actionPoints - this->_weapon->getAPCost() <= 0)
		this->_actionPoints = 0;
	else
		this->_actionPoints -= this->_weapon->getAPCost();
	
	// Enemy Damage, if his HP reaches 0 he will die
	enemy->takeDamage(this->_weapon->getDamage());
	if (enemy->getHP() == 0)
		delete enemy;
	return ;
}

std::string Character::getName() const
{
	return this->_name;
}

int			Character::getAP() const
{
	return this->_actionPoints;
}

AWeapon		*Character::getWP() const
{
	return this->_weapon;
}

std::ostream &operator<<(std::ostream &out, const Character &charac)
{
	out << charac.getName() << " has " << charac.getAP() << " AP and ";
	if (charac.getWP() != NULL)
		out << "wields a " << charac.getWP()->getName() << std::endl;
	else
		out << "is unarmed" << std::endl;
	return out;
}