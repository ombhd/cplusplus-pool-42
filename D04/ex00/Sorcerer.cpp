/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:57:04 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/12 10:17:18 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"


Sorcerer::Sorcerer()
{
}

Sorcerer::Sorcerer(std::string name, std::string title): _name(name), _title(title)
{
	std::cout << _name <<", " << _title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &src)
{
	if (this == &src)
		return ;
	*this = src;
	return ;
}

Sorcerer	&Sorcerer::operator=(const Sorcerer &src)
{
	if (this == &src)
		return *this;
	_name = src._name;
	_title = src._title;
	return *this;
}

Sorcerer::~Sorcerer()
{
	std::cout << _name <<", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
}

std::string		Sorcerer::getName() const
{
	return _name;
}

std::string		Sorcerer::getTitle() const
{
	return _title;
}

void			Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &out, const Sorcerer &src)
{
	out << "I am " << src.getName() << ", " << src.getTitle() << ", and I like ponies!" << std::endl;
	return out;
}