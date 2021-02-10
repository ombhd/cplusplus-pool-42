/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:04:23 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/10 11:38:10 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &);
	FragTrap &operator=(const FragTrap &);
	~FragTrap();

// Getters
	unsigned int	getVaulhunterDamagePoints(void) const;
	unsigned int	getOnePunchManAttackDamagePoints(void) const;
	unsigned int	getSniperRifleAttackDamagePoints(void) const;
	unsigned int	getZanbaktuAttackDamagePoints(void) const;
	unsigned int	getSeroAttackDamagePoints(void) const;
	unsigned int	getRocketAttackDamagePoints(void) const;
	unsigned int	getRasinganAttackDamagePoints(void) const;

// Super Semi random Attack
	void			vaulthunter_dot_exe(std::string const &target);

private:
	unsigned int	_vaulhunterDamagePoints;
	unsigned int	_onePunchManAttackDamagePoints;
	unsigned int	_sniperRifleAttackDamagePoints;
	unsigned int	_zanbaktuAttackDamagePoints;
	unsigned int	_seroAttackDamagePoints;
	unsigned int	_rocketAttackDamagePoints;
	unsigned int	_rasinganAttackDamagePoints;
	void			init(void);
// Setters
	void			setRasinganAttackDamagePoints(const unsigned int);
	void			setVaulhunterDamagePoints(const unsigned int);
	void			setRocketAttackDamagePoints(const unsigned int);
	void			setOnePunchManAttackDamagePoints(const unsigned int);
	void			setSeroAttackDamagePoints(const unsigned int);
	void			setSniperRifleAttackDamagePoints(const unsigned int);
	void			setZanbaktuAttackDamagePoints(const unsigned int);
// Super Attacks
	void			zanbaktuAttack(std::string const &target);
	void			rocketAttack(std::string const &target);
	void			sniperRifleAttack(std::string const &target);
	void			seroAttack(std::string const &target);
	void			onePunchManAttack(std::string const &target);
	void			rasinganAttack(std::string const &target);
};

#endif // !FRAGTRAP_H