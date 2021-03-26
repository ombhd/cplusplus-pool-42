/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conv.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:37:13 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/26 16:51:55 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_H
#define CONV_H

#include <string>
#include <limits>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <sstream>

class Conv
{
public:
	Conv();
	Conv(const std::string data);
	Conv(const Conv &);
	Conv &operator=(const Conv &);
	~Conv();
	void setData(std::string data);
	const std::string getData() const;
	void toChar();
	void toInt();
	void toFloat();
	void toDouble();
	void present();
	class InvalidArgException : public std::exception
	{
	public:
		virtual const char *what() const throw(); 
	};
	class EmptyArgException : public std::exception
	{
	public:
		virtual const char *what() const throw(); 
	};
	 
	
private:
	std::string	_data;
	long double _convDouble;
	int			_getPrecision();
	bool		_isScientific();
};

#endif // !CONV_H