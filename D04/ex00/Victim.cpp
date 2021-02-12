/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:57:04 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/12 10:20:45 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"


Victim::Victim()
{
}

Victim::Victim(std::string name): _name(name)
{
	std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;
}

Victim::Victim(const Victim &src)
{
	if (this == &src)
		return ;
	*this = src;
	return ;
}

Victim	&Victim::operator=(const Victim &src)
{
	if (this == &src)
		return *this;
	this->_name = src._name;
	return *this;
}

Victim::~Victim()
{
	std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

std::string		Victim::getName() const
{
	return _name;
}

void			Victim::getPolymorphed() const
{
	std::cout << this->_name << " has been turned into a cute little sheep!" << std::endl;
}


std::ostream	&operator<<(std::ostream &out, const Victim &src)
{
	out << "I'm " << src.getName() << " and I like otters!" << std::endl;
	return out;
}