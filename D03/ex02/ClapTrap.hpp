/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:04:23 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/07 12:53:52 by obouykou         ###   ########.fr       */
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

// Normal Attacks
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
// energy points handling
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);


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
};

#endif // !CLAPTRAP_H