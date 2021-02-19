/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:13:16 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/18 18:31:36 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	return ;
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	return ;
}

Cure &Cure::operator=(const Cure &src)
{
	this->AMateria::operator=(src);
	return *this;
}

Cure::~Cure()
{
	return ;
}

AMateria *Cure::clone() const
{
	AMateria *tmp;

	tmp = new Cure(*this);
	if (!tmp)
		std::cout << "Can't clone this Cure, memory allocation failed!" << std::endl;
	return (tmp);
}

void Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
