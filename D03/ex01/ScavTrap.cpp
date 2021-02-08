/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:09:18 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/08 12:59:31 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	init();
	std::cout << "Ah, man, I am so late!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : _name(name)
{
	init();
	std::cout << _name << ": Ah, man, I am so late!" << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << _name << " : I'm too pretty to die!! BUT Yeah let's die!" << std::endl;
	return ;
}

ScavTrap		&ScavTrap::operator=(const ScavTrap &src)
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
	this->setChallengeNewComerPoints(src.getChallengeNewComerPoints());
	this->setOnePunchManAttackDamagePoints(src.getOnePunchManAttackDamagePoints());
	this->setSniperRifleAttackDamagePoints(src.getSniperRifleAttackDamagePoints());
	this->setZanbaktuAttackDamagePoints(src.getZanbaktuAttackDamagePoints());
	this->setSeroAttackDamagePoints(src.getSeroAttackDamagePoints());
	this->setLazerAttackDamagePoints(src.getLazerAttackDamagePoints());
	this->setRasinganAttackDamagePoints(src.getRasinganAttackDamagePoints());
	return *this;
}

void			ScavTrap::init(void)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_level = 1;
	_meleeAttackDamage = 20;
	_rangedAttackDamage = 15;
	_armorDamageReduction = 3;
	_challengeNewComerPoints = 0;
	_onePunchManAttackDamagePoints = 60;
	_sniperRifleAttackDamagePoints = 7;
	_zanbaktuAttackDamagePoints = 20;
	_seroAttackDamagePoints = 10;
	_lazerAttackDamagePoints = 8;
	_rasinganAttackDamagePoints = 25;
}

bool			ScavTrap::is_alive() const
{
	if (this->_hitPoints == 0)
	{
        // std::cout << this->_name << " 🦴 - Who Called Me to My Duty!!? I'M Already DEAD! X_X" << std::endl;
		return false;
	}
	return (true);
}

void			ScavTrap::rangedAttack(std::string const & target)
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

void			ScavTrap::meleeAttack(std::string const & target)
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

void			ScavTrap::takeDamage(unsigned int amount)
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
	std::cout << "  - Taken Damage: " << actualDamage << std::endl;
	std::cout << "  - HP left: " << this->_hitPoints << "/"  << this->_maxHitPoints << std::endl;
    return ;
}

void			ScavTrap::beRepaired(unsigned int amount)
{
	if (!this->is_alive())
		return ;
	if (this->_energyPoints < amount)
    {
        std::cout << "  😰 " << this->_name << " : I have NOT enough energy points.." << std::endl;
   		std::cout << " 💛 - Energy points left: " << this->_energyPoints 
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

	std::cout << " 💊 " << this->_name << ": Found Health over here!" << std::endl;
	std::cout << "    - HP points: " << this->_hitPoints << std::endl;
    std::cout << " 💛 - Energy points left: " << this->_energyPoints << "/" << this->_maxEnergyPoints << std::endl;
    return ;
}

// Attacks
void			ScavTrap::challengeNewcomer(std::string const & target)
{
	if (!this->is_alive())
		return ;
	if (this->getEnergyPoints() < 25)
	{
		std::cout << " 🤣 - You are too weak to take this challenge" << std::endl;
		return ;
	}
	std::cout << "\n Challenge time! ..\n" << std::endl;
	std::cout << " Let's see what challenge this new comer has for U ..\n" << std::endl;
	std::cout << " Readyyyy!!! ..\n" << std::endl;
	sleep(2);
	this->setEnergyPoints(this->_energyPoints - 25);
	int randomChallenge =  rand() % 6 + 1;
	int isLucky =  rand() % 1000;
	if (isLucky % 2 == 0)
		switch (randomChallenge)
		{
			case 1:
				lazerAttack(target);
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
	else
	{
		std::cout << this->_name << ": I am lucky, this new comer has no challenge for me .." << std::endl;
		_challengeNewComerPoints = 0;
		return ;
	}

	// Get energy points when you attack a target
	if (this->_energyPoints + this->_challengeNewComerPoints >= this->_maxEnergyPoints)
		this->_energyPoints = this->_maxEnergyPoints;
	else
		this->_energyPoints += this->_challengeNewComerPoints;

	// Display HP and Energy points
	std::cout << "    - HP points: " << this->_hitPoints << "/" << this->_maxHitPoints << std::endl;
    std::cout << " 💛 - Energy points left: " << this->_energyPoints << "/" << this->_maxEnergyPoints << std::endl;
    return ;
}

void			ScavTrap::lazerAttack(std::string const &target)
{
    this->_challengeNewComerPoints = this->_lazerAttackDamagePoints;
    std::cout << " ✨ - SC4V-TP " << this->_name << " receives " << target \
              << "an attack with lazer, causing over " << this->_lazerAttackDamagePoints \
              << " of damage to him!" << std::endl;
    return ;
}

void			ScavTrap::seroAttack(std::string const &target)
{
	this->_challengeNewComerPoints = this->_seroAttackDamagePoints;
    std::cout << " ➿ - SC4V-TP " << this->_name << " receives " << target \
              << "an attack with a sero, causing " << this->_seroAttackDamagePoints \
              << " of damage to him!" << std::endl;
    return ;
}

void			ScavTrap::zanbaktuAttack(std::string const &target)
{
    this->_challengeNewComerPoints = this->_zanbaktuAttackDamagePoints;
    std::cout << " 💀 - SC4V-TP " << this->_name << " receives " << target \
              << "an attack with a zanbaktu, causing " << this->_zanbaktuAttackDamagePoints \
              << " of damage to him!" << std::endl;
    return ;
}

void			ScavTrap::onePunchManAttack(std::string const &target)
{
    this->_challengeNewComerPoints = this->_onePunchManAttackDamagePoints;
    std::cout << " 👨‍🦲🤜- SC4V-TP " << this->_name << " receives " << target \
              << "an attack with one Punch of SuperMan, causing " << this->_onePunchManAttackDamagePoints \
              << " of damage to him!" << std::endl;
    return ;
}

void			ScavTrap::sniperRifleAttack(std::string const &target)
{
    this->_challengeNewComerPoints = this->_sniperRifleAttackDamagePoints;
    std::cout << " 🔦 - SC4V-TP " << this->_name << " receives " << target \
              << "an attack with a sniper rifle, causing " << this->_sniperRifleAttackDamagePoints \
              << " of damage to him!" << std::endl;
    return ;
}

void			ScavTrap::rasinganAttack(std::string const &target)
{
	this->_challengeNewComerPoints = this->_rasinganAttackDamagePoints;
    std::cout << " 🌀 - SC4V-TP " << this->_name << " receives " << target \
              << "an attack with a rasingan, causing " << this->_rasinganAttackDamagePoints \
              << " of damage to him!" << std::endl;
    return ;
}

// Getters and Setters
unsigned int	ScavTrap::getHitPoints(void) const
{
	return _hitPoints;
}

void			ScavTrap::setHitPoints(const unsigned int hp)
{
	_hitPoints = hp;
}

unsigned int	ScavTrap::getMaxHitPoints(void) const
{
	return _maxHitPoints;
}	

void			ScavTrap::setMaxHitPoints(const unsigned int maxHP)
{
	_maxHitPoints = maxHP;
}

unsigned int	ScavTrap::getEnergyPoints(void) const
{
	return _energyPoints; 
}	

void			ScavTrap::setEnergyPoints(const unsigned int energyPoints)
{
	_energyPoints = energyPoints;
}

unsigned int	ScavTrap::getMaxEnergyPoints(void) const
{
	return _maxEnergyPoints;
}	

void			ScavTrap::setMaxEnergyPoints(const unsigned int maxEnergyPoints)
{
	_maxEnergyPoints = maxEnergyPoints;
}

unsigned int	ScavTrap::getLevel(void) const
{
	return _level;
}	

void			ScavTrap::setLevel(const unsigned int level)
{
	_level = level;
}

std::string		ScavTrap::getName(void) const
{
	return _name;
}	

void			ScavTrap::setName(const std::string name)
{
	_name = name;
}

unsigned int	ScavTrap::getMeleeAttackDamage(void) const
{
	return _meleeAttackDamage;
}	

void			ScavTrap::setMeleeAttackDamage(const unsigned int mad)
{
	_meleeAttackDamage = mad;
}

unsigned int	ScavTrap::getRangedAttackDamage(void) const
{
	return _rangedAttackDamage;
}	

void			ScavTrap::setRangedAttackDamage(const unsigned int rad)
{
	_rangedAttackDamage = rad;
}

unsigned int	ScavTrap::getArmorDamageReduction(void) const
{
	return _armorDamageReduction;
}	

void			ScavTrap::setArmorDamageReduction(const unsigned int adr)
{
	_armorDamageReduction = adr;
}

unsigned int	ScavTrap::getChallengeNewComerPoints(void) const
{
	return _challengeNewComerPoints ;
}

void			ScavTrap::setChallengeNewComerPoints(const unsigned int adr)
{
	_challengeNewComerPoints = adr;
}

unsigned int	ScavTrap::getOnePunchManAttackDamagePoints(void) const
{
	return _onePunchManAttackDamagePoints;
}

void			ScavTrap::setOnePunchManAttackDamagePoints(const unsigned int opmDP)
{
	_onePunchManAttackDamagePoints = opmDP;
}

unsigned int	ScavTrap::getSniperRifleAttackDamagePoints(void) const
{
	return _sniperRifleAttackDamagePoints;
}

void			ScavTrap::setSniperRifleAttackDamagePoints(const unsigned int srDP)
{
	_sniperRifleAttackDamagePoints = srDP;
}

unsigned int	ScavTrap::getZanbaktuAttackDamagePoints(void) const
{
	return _zanbaktuAttackDamagePoints;
}

void			ScavTrap::setZanbaktuAttackDamagePoints(const unsigned int zDP)
{
	_zanbaktuAttackDamagePoints = zDP;
}

unsigned int	ScavTrap::getSeroAttackDamagePoints(void) const
{
	return _seroAttackDamagePoints;
}

void			ScavTrap::setSeroAttackDamagePoints(const unsigned int sDP)
{
	_seroAttackDamagePoints = sDP;
}

unsigned int	ScavTrap::getLazerAttackDamagePoints(void) const
{
	return _lazerAttackDamagePoints;
}

void			ScavTrap::setLazerAttackDamagePoints(const unsigned int roDP)
{
	_lazerAttackDamagePoints = roDP;
}

unsigned int	ScavTrap::getRasinganAttackDamagePoints(void) const
{
	return _rasinganAttackDamagePoints;
}

void			ScavTrap::setRasinganAttackDamagePoints(const unsigned int raDP)
{
	_rasinganAttackDamagePoints = raDP;
}
