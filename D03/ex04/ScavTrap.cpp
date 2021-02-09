/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:09:18 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/08 18:26:56 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	init();
	std::cout << "Ah, man, I am so late!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
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
	_onePunchManAttackDamagePoints = 200;
	_sniperRifleAttackDamagePoints = 13;
	_zanbaktuAttackDamagePoints = 37;
	_seroAttackDamagePoints = 21;
	_lazerAttackDamagePoints = 12;
	_rasinganAttackDamagePoints = 30;
}

// Attacks
void			ScavTrap::challengeNewcomer(std::string const &attacker)
{
	if (!this->is_alive())
		return ;
	if (this->getEnergyPoints() < 25)
	{
		std::cout << " 🤣 Oh " << this->_name << "! You are too weak to take the New Comer Challenge .." << std::endl;
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
				lazerAttack(attacker);
				sleep(1);
				break;
			case 2:
				zanbaktuAttack(attacker);
				sleep(1);
				break;
			case 3:
				sniperRifleAttack(attacker);
				sleep(1);
				break;
			case 4:
				seroAttack(attacker);
				sleep(1);
				break;
			case 5:
				onePunchManAttack(attacker);
				sleep(1);
				break;
			case 6:
				rasinganAttack(attacker);
				sleep(1);
				break;
			default:
				break;
		}
	else
	{
		std::cout << "  " << this->_name << ": I am lucky, this new comer has no challenge for me .." << std::endl;
		_challengeNewComerPoints = 0;
		return ;
	}

	// Lose energy points, because of the new comer attack
	if ((int)(this->_energyPoints - this->_challengeNewComerPoints) <= 0)
		this->_energyPoints = 0;
	else
		this->_energyPoints -= this->_challengeNewComerPoints;

	// Display HP and Energy points
	std::cout << "    - HP points: " << this->_hitPoints << "/" << this->_maxHitPoints << std::endl;
    std::cout << "  - Energy points left: " << this->_energyPoints << "/" << this->_maxEnergyPoints << "💛" << std::endl;
    return ;
}

void			ScavTrap::lazerAttack(std::string const &attacker)
{
    this->_challengeNewComerPoints = this->_lazerAttackDamagePoints;
    std::cout << " ✨ - SC4V-TP " << this->_name << " receives an attack with lazer from " \
			  << attacker <<", causing " << this->_lazerAttackDamagePoints \
              << " of damage to him!" << std::endl;
    return ;
}

void			ScavTrap::seroAttack(std::string const &attacker)
{
	this->_challengeNewComerPoints = this->_seroAttackDamagePoints;
    std::cout << " ➿ - SC4V-TP " << this->_name << " receives an attack with a sero from " \
			  << attacker <<", causing " << this->_seroAttackDamagePoints \
              << " of damage to him!" << std::endl;
    return ;
}

void			ScavTrap::zanbaktuAttack(std::string const &attacker)
{
    this->_challengeNewComerPoints = this->_zanbaktuAttackDamagePoints;
    std::cout << " 💀 - SC4V-TP " << this->_name << " receives an attack with a zanbaktu from " \
			  << attacker <<", causing " << this->_zanbaktuAttackDamagePoints \
              << " of damage to him!" << std::endl;
    return ;
}

void			ScavTrap::onePunchManAttack(std::string const &attacker)
{
    this->_challengeNewComerPoints = this->_onePunchManAttackDamagePoints;
    std::cout << " 👨‍🦲🤜- SC4V-TP " << this->_name << " receives an attack with one Punch of SuperMan from " \
			  << attacker <<", causing " << this->_onePunchManAttackDamagePoints \
              << " of damage to him!" << std::endl;
    return ;
}

void			ScavTrap::sniperRifleAttack(std::string const &attacker)
{
    this->_challengeNewComerPoints = this->_sniperRifleAttackDamagePoints;
    std::cout << " 🔦 - SC4V-TP " << this->_name << " receives an attack with a sniper rifle from " \
			  << attacker <<", causing " << this->_sniperRifleAttackDamagePoints \
              << " of damage to him!" << std::endl;
    return ;
}

void			ScavTrap::rasinganAttack(std::string const &attacker)
{
	this->_challengeNewComerPoints = this->_rasinganAttackDamagePoints;
    std::cout << " 🌀 - SC4V-TP " << this->_name << " receives an attack with a rasingan from " \
			  << attacker <<", causing " << this->_rasinganAttackDamagePoints \
              << " of damage to him!" << std::endl;
    return ;
}

// Getters and Setters

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
