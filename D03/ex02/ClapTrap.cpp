/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:09:18 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/07 11:39:27 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	return ;
}

ClapTrap::~ClapTrap()
{
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
	this->setOnePunchManAttackDamagePoints(src.getOnePunchManAttackDamagePoints());
	this->setSniperRifleAttackDamagePoints(src.getSniperRifleAttackDamagePoints());
	this->setZanbaktuAttackDamagePoints(src.getZanbaktuAttackDamagePoints());
	this->setSeroAttackDamagePoints(src.getSeroAttackDamagePoints());
	this->setRocketAttackDamagePoints(src.getRocketAttackDamagePoints());
	this->setRasinganAttackDamagePoints(src.getRasinganAttackDamagePoints());
	return *this;
}

bool			ClapTrap::is_alive() const
{
	if (this->_hitPoints == 0)
	{
        // std::cout << this->_name << " 🦴 - Who Called Me to My Duty!!? I'M Already DEAD! X_X" << std::endl;
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
    std::cout << " 💚 - Energy points left: " << this->_energyPoints << "/" << this->_maxEnergyPoints << std::endl;
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
    std::cout << " 💚 - Energy points left: " << this->_energyPoints << "/" << this->_maxEnergyPoints << std::endl;
    return ;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int actualDamage;

	if (!this->is_alive())
		return ;
	// We do this, because armor decreases the damage amount by _armorDamageReduction value
	actualDamage = amount - this->_armorDamageReduction;
    if (actualDamage >= this->_hitPoints)
    {
        this->_hitPoints = 0;
        std::cout << this->_name << " 🦴 - I'M DEAD! I'M DEAD! OMG I'M DEAD! X_X" << std::endl;
		return ;
    }
	this->_hitPoints -= actualDamage;
	std::cout << this->_name << " 😈 - Hahahahaha! I'm alive!" << std::endl;
	std::cout << " And I have " << this->_hitPoints << "/"  << this->_maxHitPoints << " HP left" << std::endl;
	std::cout << " Despite of taking " << actualDamage << " Damage" << std::endl;
    return ;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints < amount)
    {
        std::cout << this->_name << ": I have NOT enough energy points.." << std::endl;
   		std::cout << " 💚 - Energy points left: " << this->_energyPoints 
		   		  << "/"  << this->_maxEnergyPoints << std::endl;
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

	std::cout << this->_name << " 💊 - Found Health over here!" << std::endl;
	std::cout << "    - HP points: " << this->_hitPoints << std::endl;
    std::cout << " 💚 - Energy points left: " << this->_energyPoints << "/" << this->_maxEnergyPoints << std::endl;
    return ;
}

// Attacks

void			ClapTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (!this->is_alive())
		return ;
	if (this->getEnergyPoints() < 25)
	{
		std::cout << " 😰 - You don't have much energy to perform the VaultHunter Attack" << std::endl;
		return ;
	}
	std::cout << "\nBoogie time!\n" << std::endl;
	sleep(2);
	this->setEnergyPoints(this->_energyPoints - 25);
	int randomAttack =  rand() % 6 + 1;
	switch (randomAttack)
	{
		case 1:
			rocketAttack(target);
			sleep(1);
			break;
		case 2:
			zanbaktuAttack(target);
			sleep(1);
			break;
		case 3:
			sniperRifleAttack(target);
			sleep(1);
			break;
		case 4:
			seroAttack(target);
			sleep(1);
			break;
		case 5:
			onePunchManAttack(target);
			sleep(1);
			break;
		case 6:
			rasinganAttack(target);
			sleep(1);
			break;
		default:
			break;
	}
	
	// Get energy points when you attack a target
	if (this->_energyPoints + this->_vaulhunterDamagePoints >= this->_maxEnergyPoints)
		this->_energyPoints = this->_maxEnergyPoints;
	else
		this->_energyPoints += this->_vaulhunterDamagePoints;

	// Display HP and Energy points
	std::cout << "    - HP points: " << this->_hitPoints << "/" << this->_maxHitPoints << std::endl;
    std::cout << " 💚 - Energy points left: " << this->_energyPoints << "/" << this->_maxEnergyPoints << std::endl;
    return ;
}

void			ClapTrap::rocketAttack(std::string const &target)
{
    this->_vaulhunterDamagePoints = this->_rocketAttackDamagePoints;
    std::cout << " 🚀 - FR4G-TP " << this->_name << " attacks " << target \
              << " with rockets, causing over " << this->_rocketAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

void			ClapTrap::seroAttack(std::string const &target)
{
	this->_vaulhunterDamagePoints = this->_seroAttackDamagePoints;
    std::cout << " ➿ - FR4G-TP " << this->_name << " attacks " << target \
              << " with a sero, causing " << this->_seroAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

void			ClapTrap::zanbaktuAttack(std::string const &target)
{
    this->_vaulhunterDamagePoints = this->_zanbaktuAttackDamagePoints;
    std::cout << " 💀 - FR4G-TP " << this->_name << " attacks " << target \
              << " with a zanbaktu, causing " << this->_zanbaktuAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

void			ClapTrap::onePunchManAttack(std::string const &target)
{
    this->_vaulhunterDamagePoints = this->_onePunchManAttackDamagePoints;
    std::cout << " 🤛👨‍🦲- FR4G-TP " << this->_name << " attacks " << target \
              << " with one Punch Man, causing " << this->_onePunchManAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

void			ClapTrap::sniperRifleAttack(std::string const &target)
{
    this->_vaulhunterDamagePoints = this->_sniperRifleAttackDamagePoints;
    std::cout << " 🔦 - FR4G-TP " << this->_name << " attacks " << target \
              << " with a sniper rifle, causing " << this->_sniperRifleAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

void			ClapTrap::rasinganAttack(std::string const &target)
{
	this->_vaulhunterDamagePoints = this->_rasinganAttackDamagePoints;
    std::cout << " 🌀 - FR4G-TP " << this->_name << " attacks " << target \
              << " with a rasingan, causing " << this->_rasinganAttackDamagePoints \
              << " points of damage !" << std::endl;
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

unsigned int	ClapTrap::getVaulhunterDamagePoints(void) const
{
	return _vaulhunterDamagePoints ;
}

void			ClapTrap::setVaulhunterDamagePoints(const unsigned int adr)
{
	_vaulhunterDamagePoints = adr;
}

unsigned int	ClapTrap::getOnePunchManAttackDamagePoints(void) const
{
	return _onePunchManAttackDamagePoints;
}

void			ClapTrap::setOnePunchManAttackDamagePoints(const unsigned int opmDP)
{
	_onePunchManAttackDamagePoints = opmDP;
}

unsigned int	ClapTrap::getSniperRifleAttackDamagePoints(void) const
{
	return _sniperRifleAttackDamagePoints;
}

void			ClapTrap::setSniperRifleAttackDamagePoints(const unsigned int srDP)
{
	_sniperRifleAttackDamagePoints = srDP;
}

unsigned int	ClapTrap::getZanbaktuAttackDamagePoints(void) const
{
	return _zanbaktuAttackDamagePoints;
}

void			ClapTrap::setZanbaktuAttackDamagePoints(const unsigned int zDP)
{
	_zanbaktuAttackDamagePoints = zDP;
}

unsigned int	ClapTrap::getSeroAttackDamagePoints(void) const
{
	return _seroAttackDamagePoints;
}

void			ClapTrap::setSeroAttackDamagePoints(const unsigned int sDP)
{
	_seroAttackDamagePoints = sDP;
}

unsigned int	ClapTrap::getRocketAttackDamagePoints(void) const
{
	return _rocketAttackDamagePoints;
}

void			ClapTrap::setRocketAttackDamagePoints(const unsigned int roDP)
{
	_rocketAttackDamagePoints = roDP;
}

unsigned int	ClapTrap::getRasinganAttackDamagePoints(void) const
{
	return _rasinganAttackDamagePoints;
}

void			ClapTrap::setRasinganAttackDamagePoints(const unsigned int raDP)
{
	_rasinganAttackDamagePoints = raDP;
}
