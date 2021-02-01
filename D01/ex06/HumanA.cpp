/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:16:44 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/01 16:00:00 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	return ;
}

HumanA::~HumanA()
{
	return ;	
}

void		HumanA::setName(std::string name)
{
	this->name = name;
}

std::string	HumanA::getName()
{
	return (name);
}

void		HumanA::setWeapon(Weapon weapon)
{
	this->weapon.setType(weapon.getType());
}

Weapon		HumanA::getWeapon()
{
	return (this->weapon);
}

void	HumanA::attack()
{
	std::cout << this->name <<" attacks with his " << this->weapon.getType() << std::endl;
}
