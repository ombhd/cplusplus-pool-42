/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:28:20 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/01 12:08:11 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	return;
}

Brain::~Brain(void)
{
	return;
}

void		Brain::setIQ(int iq)
{
	this->iq = iq;
}

int			Brain::getIQ(void)
{
	return (iq);
}

std::string	Brain::toupperAdress(std::string str) const
{
	int l;

	l = str.length();
	for (int i = 2; i < l; i++)
	{
		str[i] = toupper(str[i]);
	}
	return (str);
}

std::string Brain::identify(void) const
{
	std::stringstream	ss;
	
	ss << std::hex << this;
	return (toupperAdress(ss.str()));
}
