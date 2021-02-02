/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:41:58 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/02 18:58:20 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP 

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &);
	Fixed &operator=(const Fixed &);
	int getRawBits(void) const; 
	void setRawBits(int const raw);
	~Fixed();

private:
	int _fixedPointVal;
	static const int numberOfFractBits = 8;
};


#endif // !FIXED_HPP