/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:04:23 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/08 18:28:58 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H


#include <iostream>
#include <unistd.h>

class ScavTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &);
	ScavTrap &operator=(const ScavTrap &);
	~ScavTrap();

	bool			is_alive() const;
// Getters & Setters
	unsigned int	getHitPoints(void) const;	
	void			setHitPoints(const unsigned int);
	unsigned int	getMaxHitPoints(void) const;	
	void			setMaxHitPoints(const unsigned int);
	unsigned int	getEnergyPoints(void) const;	
	void			setEnergyPoints(const unsigned int);
	unsigned int	getMaxEnergyPoints(void) const;	
	void			setMaxEnergyPoints(const unsigned int);
	unsigned int	getLevel(void) const;	
	void			setLevel(const unsigned int);
	std::string		getName(void) const;	
	void			setName(const std::string);
	unsigned int	getMeleeAttackDamage(void) const;	
	void			setMeleeAttackDamage(const unsigned int);
	unsigned int	getRangedAttackDamage(void) const;	
	void			setRangedAttackDamage(const unsigned int);
	unsigned int	getArmorDamageReduction(void) const;	
	void			setArmorDamageReduction(const unsigned int);
	unsigned int	getChallengeNewComerPoints(void) const;
	void			setChallengeNewComerPoints(const unsigned int);
	unsigned int	getOnePunchManAttackDamagePoints(void) const;
	void			setOnePunchManAttackDamagePoints(const unsigned int);
	unsigned int	getSniperRifleAttackDamagePoints(void) const;
	void			setSniperRifleAttackDamagePoints(const unsigned int);
	unsigned int	getZanbaktuAttackDamagePoints(void) const;
	void			setZanbaktuAttackDamagePoints(const unsigned int);
	unsigned int	getSeroAttackDamagePoints(void) const;
	void			setSeroAttackDamagePoints(const unsigned int);
	unsigned int	getLazerAttackDamagePoints(void) const;
	void			setLazerAttackDamagePoints(const unsigned int);
	unsigned int	getRasinganAttackDamagePoints(void) const;
	void			setRasinganAttackDamagePoints(const unsigned int);

// Normal Attacks
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
// energy points handling
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
// Super Semi random Attack
	void			challengeNewcomer(std::string const &target);

private:
	unsigned int	_hitPoints;
	unsigned int	_maxHitPoints;
	unsigned int	_energyPoints;
	unsigned int	_maxEnergyPoints;
	unsigned int 	_level;
	std::string 	_name;
	unsigned int	_meleeAttackDamage;
	unsigned int	_rangedAttackDamage;
	unsigned int	_armorDamageReduction;
	unsigned int	_challengeNewComerPoints;
	unsigned int	_onePunchManAttackDamagePoints;
	unsigned int	_sniperRifleAttackDamagePoints;
	unsigned int	_zanbaktuAttackDamagePoints;
	unsigned int	_seroAttackDamagePoints;
	unsigned int	_lazerAttackDamagePoints;
	unsigned int	_rasinganAttackDamagePoints;
	void			init(void);
// Super Attacks for Challengers
	void			zanbaktuAttack(std::string const &target);
	void			lazerAttack(std::string const &target);
	void			sniperRifleAttack(std::string const &target);
	void			seroAttack(std::string const &target);
	void			onePunchManAttack(std::string const &target);
	void			rasinganAttack(std::string const &target);
};

#endif // !SCAVTRAP_H