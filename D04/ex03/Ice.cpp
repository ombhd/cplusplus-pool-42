/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:13:16 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/19 12:39:18 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	return ;
}

Ice::Ice(const Ice &src)
{
	*this = src;
}

Ice &Ice::operator=(const Ice &src)
{
	this->AMateria::operator=(src);
	return *this;
}


Ice::~Ice()
{
	return ;
}

AMateria *Ice::clone() const
{
	AMateria *tmp;

	tmp = new Ice(*this);
	if (!tmp)
		std::cout << "Can't clone this Ice, memory allocation failed!" << std::endl;
	return (tmp);
}

void Ice::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
