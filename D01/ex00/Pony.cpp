/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 10:58:13 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/31 11:29:55 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"


Pony::Pony()
{
	std::cout << "a Pony is born!" << std::endl;	
	return ;
}

Pony::Pony(std::string name)
{
	this->name = name;
	std::cout << "Pony " << name << " is born!" << std::endl;	
}

Pony::~Pony(void)
{
	std::cout << "Pony " << name << " is died!" << std::endl;	
	return ;
}

void	Pony::setName(std::string name)
{
	this->name = name;
}

std::string		Pony::getName()
{
	return (name);
}

void	Pony::setHeight(int height)
{
	this->height = height;
}

int		Pony::getHeight()
{
	return (height);
}

void	Pony::setMainColor(int color)
{
	this->mainColor = color;
}

int		Pony::getMainColor()
{
	return (mainColor);
}

Pony	Pony::*ponyOnTheHeap()
{
	Pony *pony = new Pony();
	std::cout << "Pony is now allocated on the heap" << std::endl;
}

Pony	Pony::ponyOnTheStack()
{
	
}
