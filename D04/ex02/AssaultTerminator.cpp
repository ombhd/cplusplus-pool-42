/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:28:39 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/18 15:49:19 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"


AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
	return ;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &)
{
	return ;
}

AssaultTerminator &AssaultTerminator::operator=(const AssaultTerminator &tm)
{
	if (this != &tm)
		*this = tm;
	return *this;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I’ll be back..." << std::endl;
	return ;
}

ISpaceMarine *AssaultTerminator::clone() const
{
	ISpaceMarine *tmp;

	tmp = new AssaultTerminator(*this);
	if (!tmp)
		std::cout << "Can't clone this Assault Terminator, memory allocation failed!" << std::endl;
	return (tmp);
}

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}
