/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:13:16 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/18 18:31:36 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria():
_xp(0),
_type("default")
{
	return ;
}

AMateria::AMateria(std::string const &type):
_xp(0),
_type(type)
{
	return ;
}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_xp = src._xp;
	}
	return *this;
}


AMateria::~AMateria()
{
	return ;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

unsigned int AMateria::getXP() const
{
	return this->_xp;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	this->_xp += 10;
}
