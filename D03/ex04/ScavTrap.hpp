/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:04:23 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/10 10:21:58 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &);
	ScavTrap &operator=(const ScavTrap &);
	~ScavTrap();

// Getters
	unsigned int	getChallengeNewComerPoints(void) const;
	unsigned int	getOnePunchManAttackDamagePoints(void) const;
	unsigned int	getSniperRifleAttackDamagePoints(void) const;
	unsigned int	getZanbaktuAttackDamagePoints(void) const;
	unsigned int	getSeroAttackDamagePoints(void) const;
	unsigned int	getLazerAttackDamagePoints(void) const;
	unsigned int	getRasinganAttackDamagePoints(void) const;

// Super Semi random Attack
	void			challengeNewcomer(std::string const &target);

private:
	unsigned int	_challengeNewComerPoints;
	unsigned int	_onePunchManAttackDamagePoints;
	unsigned int	_sniperRifleAttackDamagePoints;
	unsigned int	_zanbaktuAttackDamagePoints;
	unsigned int	_seroAttackDamagePoints;
	unsigned int	_lazerAttackDamagePoints;
	unsigned int	_rasinganAttackDamagePoints;
	void			init(void);
// Setters
	void			setChallengeNewComerPoints(const unsigned int);
	void			setRasinganAttackDamagePoints(const unsigned int);
	void			setOnePunchManAttackDamagePoints(const unsigned int);
	void			setLazerAttackDamagePoints(const unsigned int);
	void			setSniperRifleAttackDamagePoints(const unsigned int);
	void			setSeroAttackDamagePoints(const unsigned int);
	void			setZanbaktuAttackDamagePoints(const unsigned int);
// Super Attacks for Challengers
	void			zanbaktuAttack(std::string const &target);
	void			lazerAttack(std::string const &target);
	void			sniperRifleAttack(std::string const &target);
	void			seroAttack(std::string const &target);
	void			onePunchManAttack(std::string const &target);
	void			rasinganAttack(std::string const &target);
};

#endif // !SCAVTRAP_H