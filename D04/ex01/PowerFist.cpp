/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:47:52 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/12 12:48:36 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"


PowerFist::PowerFist(): AWeapon("Power Fist", 8, 50)
{
	return ;
}

PowerFist::~PowerFist()
{
	return ;
}

PowerFist::PowerFist(const PowerFist &src)
{
	*this = src;
	return ;
}

PowerFist &PowerFist::operator=(const PowerFist &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_APCost = src._APCost;
		this->_damage = src._damage;
	}
	return *this;
}


void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
	return ;
}