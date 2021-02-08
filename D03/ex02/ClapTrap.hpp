/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:04:23 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/08 18:49:35 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <unistd.h>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap&);
	ClapTrap&operator=(const ClapTrap&);
	~ClapTrap();

	bool			is_alive() const;
// Getters
	unsigned int	getHitPoints(void) const;	
	unsigned int	getMaxHitPoints(void) const;	
	unsigned int	getEnergyPoints(void) const;	
	unsigned int	getMaxEnergyPoints(void) const;	
	unsigned int	getLevel(void) const;	
	std::string		getName(void) const;	
	unsigned int	getMeleeAttackDamage(void) const;	
	unsigned int	getRangedAttackDamage(void) const;	
	unsigned int	getArmorDamageReduction(void) const;	

// Normal Attacks
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
// energy points handling
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);


protected:
	unsigned int	_hitPoints;
	unsigned int	_maxHitPoints;
	unsigned int	_energyPoints;
	unsigned int	_maxEnergyPoints;
	unsigned int 	_level;
	std::string 	_name;
	unsigned int	_meleeAttackDamage;
	unsigned int	_rangedAttackDamage;
	unsigned int	_armorDamageReduction;
// Setters
	void			setHitPoints(const unsigned int);
	void			setArmorDamageReduction(const unsigned int);
	void			setMaxHitPoints(const unsigned int);
	void			setRangedAttackDamage(const unsigned int);
	void			setEnergyPoints(const unsigned int);
	void			setMeleeAttackDamage(const unsigned int);
	void			setMaxEnergyPoints(const unsigned int);
	void			setName(const std::string);
	void			setLevel(const unsigned int);
};

#endif // !CLAPTRAP_H