/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:09:18 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/03 15:54:28 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	init();
	return ;
}

FragTrap::FragTrap(std::string name) : _name(name)
{
	init();
	return ;
}

FragTrap::~FragTrap()
{
	return ;
}

void	FragTrap::init(void)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_maxEnergyPoints = 100;
	_level = 1;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
}

void	FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->getRangedAttackDamage() << " points of damage!" << std::endl;
	this->setRangedAttackDamage(this->getRangedAttackDamage() + 2);
}

void	FragTrap::meleeAttack(std::string const & target)
{
	unsigned int tmp = this->getMeleeAttackDamage() + 2;
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at melee, causing " << this->getMeleeAttackDamage() << " points of damage!" << std::endl;
	if (tmp > )
		this->setMeleeAttackDamage();
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at melee, causing " << this->getMeleeAttackDamage() << " points of damage!" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	
}

unsigned int	FragTrap::getHitPoints(void) const
{
	return _hitPoints;
}	

void			FragTrap::setHitPoints(const unsigned int hp)
{
	_hitPoints = hp;
}

unsigned int	FragTrap::getMaxHitPoints(void) const
{
	return _maxHitPoints;
}	

void			FragTrap::setMaxHitPoints(const unsigned int maxHP)
{
	_maxHitPoints = maxHP;
}

unsigned int	FragTrap::getEnergyPoints(void) const
{
	return _energyPoints; 
}	

void			FragTrap::setEnergyPoints(const unsigned int energyPoints)
{
	_energyPoints = energyPoints;
}

unsigned int	FragTrap::getMaxEnergyPoints(void) const
{
	return _maxEnergyPoints;
}	

void			FragTrap::setMaxEnergyPoints(const unsigned int maxEnergyPoints)
{
	_maxEnergyPoints = maxEnergyPoints;
}

unsigned int	FragTrap::getLevel(void) const
{
	return _level;
}	

void			FragTrap::setLevel(const unsigned int level)
{
	_level = level;
}

std::string		FragTrap::getName(void) const
{
	return _name;
}	

void			FragTrap::setName(const std::string name)
{
	_name = name;
}

unsigned int	FragTrap::getMeleeAttackDamage(void) const
{
	return _meleeAttackDamage;
}	

void			FragTrap::setMeleeAttackDamage(const unsigned int mad)
{
	_meleeAttackDamage = mad;
}

unsigned int	FragTrap::getRangedAttackDamage(void) const
{
	return _rangedAttackDamage;
}	

void			FragTrap::setRangedAttackDamage(const unsigned int rad)
{
	_rangedAttackDamage = rad;
}

unsigned int	FragTrap::getArmorDamageReduction(void) const
{
	return _armorDamageReduction;
}	

void			FragTrap::setArmorDamageReduction(const unsigned int adr)
{
	_armorDamageReduction = adr;
}
