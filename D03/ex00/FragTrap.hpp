/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:04:23 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/05 12:43:12 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H

#include <iostream>
#include <cstdlib>

class FragTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &);
	FragTrap &operator=(const FragTrap &);
	~FragTrap();
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
	unsigned int	getVaulhunterDamagePoints(void) const;
	void			setVaulhunterDamagePoints(const unsigned int);
	unsigned int	getOnePunchManAttackDamagePoints(void) const;
	void			setOnePunchManAttackDamagePoints(const unsigned int);
	unsigned int	getSniperRifleAttackDamagePoints(void) const;
	void			setSniperRifleAttackDamagePoints(const unsigned int);
	unsigned int	getZanbaktuAttackDamagePoints(void) const;
	void			setZanbaktuAttackDamagePoints(const unsigned int);
	unsigned int	getSeroAttackDamagePoints(void) const;
	void			setSeroAttackDamagePoints(const unsigned int);
	unsigned int	getRocketAttackDamagePoints(void) const;
	void			setRocketAttackDamagePoints(const unsigned int);
	unsigned int	getRasinganAttackDamagePoints(void) const;
	void			setRasinganAttackDamagePoints(const unsigned int);

// Normal Attacks
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
// energy points handling
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
// Super Semi random Attack
	void			vaulthunter_dot_exe(std::string const &target);

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
	// not initialized yet
	unsigned int	_vaulhunterDamagePoints;
	unsigned int	_onePunchManAttackDamagePoints;
	unsigned int	_sniperRifleAttackDamagePoints;
	unsigned int	_zanbaktuAttackDamagePoints;
	unsigned int	_seroAttackDamagePoints;
	unsigned int	_rocketAttackDamagePoints;
	unsigned int	_rasinganAttackDamagePoints;
	void	init(void);
// Super Attacks
	void			zanbaktuAttack(std::string const &target);
	void			rocketAttack(std::string const &target);
	void			sniperRifleAttack(std::string const &target);
	void			seroAttack(std::string const &target);
	void			onePunchManAttack(std::string const &target);
	void			rasinganAttack(std::string const &target);
};

#endif // !FRAGTRAP_H