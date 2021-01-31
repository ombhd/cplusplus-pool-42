/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:17:10 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/31 16:30:29 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void 		Zombie::setName(std::string name)
{
	this->name = name;
}

std::string Zombie::getName(void)
{
	return (name);
}

void 		Zombie::setType(std::string type)
{
	this->type = type;
}

std::string Zombie::getType(void)
{
	return (type);
}

void		Zombie::announce()
{
	std::cout << "<" << name << " (" << type << ")> " << "A lot of BRRAAAIIIIINNNNNZZZZZ..." << std::endl;
}