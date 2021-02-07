/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:09:18 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/07 10:27:10 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	init();
	std::cout << "Let's get this party started!" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : _name(name)
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

bool			FragTrap::is_alive() const
{
	if (this->_hitPoints == 0)
	{
        // std::cout << this->_name << " 🦴 - Who Called Me to My Duty!!? I'M Already DEAD! X_X" << std::endl;
		return false;
	}
	return (true);
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
	_onePunchManAttackDamagePoints = 100;
	_sniperRifleAttackDamagePoints = 7;
	_zanbaktuAttackDamagePoints = 20;
	_seroAttackDamagePoints = 10;
	_rocketAttackDamagePoints = 8;
	_rasinganAttackDamagePoints = 25;
}

void			FragTrap::rangedAttack(std::string const & target)
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

void			FragTrap::meleeAttack(std::string const & target)
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

void			FragTrap::takeDamage(unsigned int amount)
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

void			FragTrap::beRepaired(unsigned int amount)
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

void			FragTrap::vaulthunter_dot_exe(std::string const & target)
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

// Getters and Setters
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
