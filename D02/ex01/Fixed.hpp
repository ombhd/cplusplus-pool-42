/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:41:58 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/02 19:20:03 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP 

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &);
	Fixed(const int n);
	Fixed(const float f);
	~Fixed();

	Fixed &operator=(const Fixed &);
	std::ostream operator<<(const Fixed &);
	int getRawBits(void) const; 
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const; 

private:
	int _fixedPointVal;
	static const int numberOfFractBits = 8;
};


#endif // !FIXED_HPP