/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:28:39 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/18 18:05:20 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"


TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
	return ;
}

TacticalMarine::TacticalMarine(const TacticalMarine &src)
{
	*this = src;
	return ;
}

TacticalMarine &TacticalMarine::operator=(const TacticalMarine &tm)
{
	(void) tm;
	return *this;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
	return ;
}

ISpaceMarine *TacticalMarine::clone() const
{
	ISpaceMarine *tmp;

	tmp = new TacticalMarine(*this);
	if (!tmp)
		std::cout << "Can't clone this Tactical Marine, memory allocation failed!" << std::endl;
	return (tmp);
}

void TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}
