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

Cure::Cure(): AMateria("Cure")
{
	return ;
}

Cure::Cure(const Cure &src)
{
	*this = src;
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


// void Cure::use(ICharacter& target)
// {
// 	(void)target;
// 	this->_xp += 10;
// }
