/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:23:36 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/12 12:35:45 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(): AWeapon("Plasma Rifle", 5, 21)
{
	return ;
}

PlasmaRifle::~PlasmaRifle()
{
	return ;
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &src)
{
	*this = src;
	return ;
}

PlasmaRifle &PlasmaRifle::operator=(const PlasmaRifle &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_APCost = src._APCost;
		this->_damage = src._damage;
	}
	return *this;
}


void	PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
	return ;
}