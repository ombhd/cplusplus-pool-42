/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:16:44 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/03 18:48:25 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	weapon.getType();
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

void		HumanA::setWeapon(Weapon wpn)
{
	this->weapon.setType(wpn.getType());
}

Weapon		HumanA::getWeapon()
{
	return (weapon);
}

void		HumanA::attack()
{
	std::cout << this->name <<" attacks with his " << this->weapon.getType() << std::endl;
}
