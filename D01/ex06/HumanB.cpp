/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:16:44 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/03 18:50:38 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
}

HumanB::~HumanB()
{
	return ;	
}

void		HumanB::setName(std::string name)
{
	this->name = name;
}

std::string	HumanB::getName()
{
	return (name);
}

void		HumanB::setWeapon(Weapon &wpn)
{
	this->weapon = &wpn;
}

Weapon		HumanB::getWeapon()
{
	return (*weapon);
}

void	HumanB::attack()
{
	std::cout << this->name <<" attacks with his " << this->weapon->getType() << std::endl;
}
