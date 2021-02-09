/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:09:18 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/08 21:56:11 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	init();
	std::cout << "Let's get this party started!" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	init();
	std::cout << _name << ": this time it'll be awesome, I promise!" << std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << _name << " : I'll die the way I lived: annoying!" << std::endl;
	return ;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
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
	this->setVaulhunterDamagePoints(src.getVaulhunterDamagePoints());
	this->setOnePunchManAttackDamagePoints(src.getOnePunchManAttackDamagePoints());
	this->setSniperRifleAttackDamagePoints(src.getSniperRifleAttackDamagePoints());
	this->setZanbaktuAttackDamagePoints(src.getZanbaktuAttackDamagePoints());
	this->setSeroAttackDamagePoints(src.getSeroAttackDamagePoints());
	this->setRocketAttackDamagePoints(src.getRocketAttackDamagePoints());
	this->setRasinganAttackDamagePoints(src.getRasinganAttackDamagePoints());
	return *this;
}

void			FragTrap::init(void)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_maxEnergyPoints = 100;
	_level = 1;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	_vaulhunterDamagePoints = 0;
	_onePunchManAttackDamagePoints = 200;
	_sniperRifleAttackDamagePoints = 17;
	_zanbaktuAttackDamagePoints = 50;
	_seroAttackDamagePoints = 28;
	_rocketAttackDamagePoints = 20;
	_rasinganAttackDamagePoints = 60;
}


// Attacks

void			FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (!this->is_alive())
		return ;
	if (this->getEnergyPoints() < 25)
	{
		std::cout << " 😰 Oh " << _name << "! You don't have much energy to perform the VaultHunter Attack" << std::endl;
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
    std::cout << "    - Energy points left: " << this->_energyPoints << "/" << this->_maxEnergyPoints << "💛" << std::endl;
    return ;
}

void			FragTrap::rocketAttack(std::string const &target)
{
    this->_vaulhunterDamagePoints = this->_rocketAttackDamagePoints;
    std::cout << " 🚀 - FR4G-TP " << this->_name << " attacks " << target \
              << " with rockets, causing over " << this->_rocketAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

void			FragTrap::seroAttack(std::string const &target)
{
	this->_vaulhunterDamagePoints = this->_seroAttackDamagePoints;
    std::cout << " ➿ - FR4G-TP " << this->_name << " attacks " << target \
              << " with a sero, causing " << this->_seroAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

void			FragTrap::zanbaktuAttack(std::string const &target)
{
    this->_vaulhunterDamagePoints = this->_zanbaktuAttackDamagePoints;
    std::cout << " 💀 - FR4G-TP " << this->_name << " attacks " << target \
              << " with a zanbaktu, causing " << this->_zanbaktuAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

void			FragTrap::onePunchManAttack(std::string const &target)
{
    this->_vaulhunterDamagePoints = this->_onePunchManAttackDamagePoints;
    std::cout << " 🤛👨‍🦲- FR4G-TP " << this->_name << " attacks " << target \
              << " with one Punch Man, causing " << this->_onePunchManAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

void			FragTrap::sniperRifleAttack(std::string const &target)
{
    this->_vaulhunterDamagePoints = this->_sniperRifleAttackDamagePoints;
    std::cout << " 🔦 - FR4G-TP " << this->_name << " attacks " << target \
              << " with a sniper rifle, causing " << this->_sniperRifleAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

void			FragTrap::rasinganAttack(std::string const &target)
{
	this->_vaulhunterDamagePoints = this->_rasinganAttackDamagePoints;
    std::cout << " 🌀 - FR4G-TP " << this->_name << " attacks " << target \
              << " with a rasingan, causing " << this->_rasinganAttackDamagePoints \
              << " points of damage !" << std::endl;
    return ;
}

// Getters Setters
unsigned int	FragTrap::getVaulhunterDamagePoints(void) const
{
	return _vaulhunterDamagePoints ;
}

void			FragTrap::setVaulhunterDamagePoints(const unsigned int adr)
{
	_vaulhunterDamagePoints = adr;
}

unsigned int	FragTrap::getOnePunchManAttackDamagePoints(void) const
{
	return _onePunchManAttackDamagePoints;
}

void			FragTrap::setOnePunchManAttackDamagePoints(const unsigned int opmDP)
{
	_onePunchManAttackDamagePoints = opmDP;
}

unsigned int	FragTrap::getSniperRifleAttackDamagePoints(void) const
{
	return _sniperRifleAttackDamagePoints;
}

void			FragTrap::setSniperRifleAttackDamagePoints(const unsigned int srDP)
{
	_sniperRifleAttackDamagePoints = srDP;
}

unsigned int	FragTrap::getZanbaktuAttackDamagePoints(void) const
{
	return _zanbaktuAttackDamagePoints;
}

void			FragTrap::setZanbaktuAttackDamagePoints(const unsigned int zDP)
{
	_zanbaktuAttackDamagePoints = zDP;
}

unsigned int	FragTrap::getSeroAttackDamagePoints(void) const
{
	return _seroAttackDamagePoints;
}

void			FragTrap::setSeroAttackDamagePoints(const unsigned int sDP)
{
	_seroAttackDamagePoints = sDP;
}

unsigned int	FragTrap::getRocketAttackDamagePoints(void) const
{
	return _rocketAttackDamagePoints;
}

void			FragTrap::setRocketAttackDamagePoints(const unsigned int roDP)
{
	_rocketAttackDamagePoints = roDP;
}

unsigned int	FragTrap::getRasinganAttackDamagePoints(void) const
{
	return _rasinganAttackDamagePoints;
}

void			FragTrap::setRasinganAttackDamagePoints(const unsigned int raDP)
{
	_rasinganAttackDamagePoints = raDP;
}
