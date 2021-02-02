/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:06:28 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/02 19:21:09 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointVal(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &par)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(par.getRawBits());
}

Fixed::Fixed(const int n)
{
	
}

Fixed::Fixed(const float f)
{
	
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed & par)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPointVal = par.getRawBits();
	return *this;
}

int 	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointVal;
}

void 	Fixed::setRawBits(int const raw)
{
	this->_fixedPointVal = raw;
}

float 	Fixed::toFloat(void) const
{
	
}

int 	Fixed::toInt(void) const
{
	
}