/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:09:18 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/08 18:39:14 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << " ⬇ ClapClap in" << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << " ⬆ ClapClap out" << std::endl << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	this->setHitPoints(src.getHitPoints());
	this->setMaxHitPoints(src.getMaxHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setMaxEnergyPoints(src.getMaxEnergyPoints());
	this->setLevel(src.getLevel());
	this->setName(src.getName());
	this->setMeleeAttackDamage(src.getMeleeAttackDamage());
	this->setRangedAttackDamage(src.getRangedAttackDamage());
	this->setArmorDamageReduction(src.getArmorDamageReduction());
	return *this;
}

bool			ClapTrap::is_alive() const
{
	if (this->_hitPoints == 0)
	{
        std::cout << this->_name << " 💀 - Who Called Me to My Duty!!? I'M Already DEAD! X_X" << std::endl;
		return false;
	}
	return (true);
}

void			ClapTrap::rangedAttack(std::string const & target)
{
	if (!this->is_alive())
		return ;
	std::cout << " 🔫 - FR4G-TP " << this->_name << " attacks " \
			  << target << " at range, causing " << this->_rangedAttackDamage \
			  << " points of damage!" << std::endl;
			  
	// Get energy points when you attack a target
	if (this->_energyPoints + this->_rangedAttackDamage >= this->_maxEnergyPoints)
		this->_energyPoints = this->_maxEnergyPoints;
	else
		this->_energyPoints += this->_rangedAttackDamage;
	
	// Display HP and Energy points
	std::cout << "    - HP points: " << this->_hitPoints << "/" << this->_maxHitPoints << std::endl;
    std::cout << "    - Energy points left: " << this->_energyPoints << "/" << this->_maxEnergyPoints << "💛" << std::endl;
    return ;
}

void			ClapTrap::meleeAttack(std::string const & target)
{
	if (!this->is_alive())
		return ;
	std::cout << " 🔪 - FR4G-TP " << this->_name << " attacks " \
			  << target << " with melee, causing " << this->getMeleeAttackDamage() \
			  << " points of damage!" << std::endl;
	
	// Get energy points when you attack a target
	if (this->_energyPoints + this->_meleeAttackDamage >= this->_maxEnergyPoints)
		this->_energyPoints = this->_maxEnergyPoints;
	else
		this->_energyPoints += this->_meleeAttackDamage;

	// Display HP and Energy points
	std::cout << "    - HP points: " << this->_hitPoints << "/" << this->_maxHitPoints << std::endl;
    std::cout << "    - Energy points left: " << this->_energyPoints << "/" << this->_maxEnergyPoints << "💛" << std::endl;
    return ;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int actualDamage;

	if (!this->is_alive())
		return ;
	if (amount == 0)
	{
		std::cout << " 😹 " << this->_name << ": What a weak child!" << std::endl;
		return ;
	}
	// We do this, because armor decreases the damage amount by _armorDamageReduction value
	actualDamage = amount - this->_armorDamageReduction;
    if (actualDamage >= this->_hitPoints)
    {
        this->_hitPoints = 0;
        std::cout << this->_name << " 🦴 - Don't forget me! I'M DEAD! X_X" << std::endl;
		return ;
    }
	this->_hitPoints -= actualDamage;
	std::cout << " 😈 " << this->_name << ": LOL! That's all the power you've got! I'm STILL alive, YEAH!" << std::endl;
	std::cout << "    - Taken Damage: " << actualDamage << std::endl;
	std::cout << "    - HP left: " << this->_hitPoints << "/"  << this->_maxHitPoints << std::endl;
    std::cout << "    - Energy points left: " << this->_energyPoints << "/" << this->_maxEnergyPoints << "💛" << std::endl;
    return ;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->is_alive())
		return ;
	if (this->_energyPoints < amount)
    {
        std::cout << "  😰 " << this->_name << " : I have NOT enough energy points.." << std::endl;
   		std::cout << "    - Energy points left: " << this->_energyPoints 
		   		  << "/"  << this->_maxEnergyPoints << "💛" << std::endl;
		return ;
    }

	if (this->_energyPoints - amount >= 0)
		this->_energyPoints -=  amount;
	else
		this->_energyPoints = 0;
	if (this->_hitPoints + amount < this->_maxHitPoints)
		this->_hitPoints += amount;
	else
		this->_hitPoints = this->_maxHitPoints;

	std::cout << " 💊 " << this->_name << ": Found Health over here!" << std::endl;
	std::cout << "    - HP points: " << this->_hitPoints << std::endl;
    std::cout << "    - Energy points left: " << this->_energyPoints << "/" << this->_maxEnergyPoints << "💛" << std::endl;
    return ;
}

// Getters and Setters
unsigned int	ClapTrap::getHitPoints(void) const
{
	return _hitPoints;
}

void			ClapTrap::setHitPoints(const unsigned int hp)
{
	_hitPoints = hp;
}

unsigned int	ClapTrap::getMaxHitPoints(void) const
{
	return _maxHitPoints;
}	

void			ClapTrap::setMaxHitPoints(const unsigned int maxHP)
{
	_maxHitPoints = maxHP;
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return _energyPoints; 
}	

void			ClapTrap::setEnergyPoints(const unsigned int energyPoints)
{
	_energyPoints = energyPoints;
}

unsigned int	ClapTrap::getMaxEnergyPoints(void) const
{
	return _maxEnergyPoints;
}	

void			ClapTrap::setMaxEnergyPoints(const unsigned int maxEnergyPoints)
{
	_maxEnergyPoints = maxEnergyPoints;
}

unsigned int	ClapTrap::getLevel(void) const
{
	return _level;
}	

void			ClapTrap::setLevel(const unsigned int level)
{
	_level = level;
}

std::string		ClapTrap::getName(void) const
{
	return _name;
}	

void			ClapTrap::setName(const std::string name)
{
	_name = name;
}

unsigned int	ClapTrap::getMeleeAttackDamage(void) const
{
	return _meleeAttackDamage;
}	

void			ClapTrap::setMeleeAttackDamage(const unsigned int mad)
{
	_meleeAttackDamage = mad;
}

unsigned int	ClapTrap::getRangedAttackDamage(void) const
{
	return _rangedAttackDamage;
}	

void			ClapTrap::setRangedAttackDamage(const unsigned int rad)
{
	_rangedAttackDamage = rad;
}

unsigned int	ClapTrap::getArmorDamageReduction(void) const
{
	return _armorDamageReduction;
}	

void			ClapTrap::setArmorDamageReduction(const unsigned int adr)
{
	_armorDamageReduction = adr;
}
