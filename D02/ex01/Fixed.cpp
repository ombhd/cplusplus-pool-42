/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:06:28 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/03 12:55:18 by obouykou         ###   ########.fr       */
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
	*this = par;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointVal = n << numberOfFractBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointVal = roundf(f * (1 << numberOfFractBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &par)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPointVal = par.getRawBits();
	return *this;
}

int 	Fixed::getRawBits(void) const
{
	return this->_fixedPointVal;
}

void 	Fixed::setRawBits(int const raw)
{
	this->_fixedPointVal = raw;
}

float 	Fixed::toFloat(void) const
{
	return (float)_fixedPointVal / (1 << numberOfFractBits);
}

int 	Fixed::toInt(void) const
{
	return _fixedPointVal >> numberOfFractBits;
}

std::ostream &operator<<(std::ostream &o, const Fixed &par)
{
	o << par.toFloat();
	return (o);
}
