/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conv.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:37:17 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/27 15:50:41 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Conv.hpp"

Conv::Conv():
_data("0"),
_convDouble(0.0)
{
}

Conv::Conv(const std::string data)
{
	if (data.empty())
		throw EmptyArgException();
	_data = data;
	if (!_isScientific()) // test nan inf +inf -inf
	{
		if (_data.length() > 1)
		{
			if (_data[_data.length() - 1] == 'f')
			{
				// remove 'f' from the data
				_data = _data.substr(0, _data.length() - 1);
			}
			int pointCount = 0;
			size_t i = (_data[0] == '+' || _data[0] == '-') ? 1 : 0;
			for (; i < _data.length(); i++)
			{
				if (_data[i] == '.')
					++pointCount;
				if ((!isdigit(_data[i]) && _data[i] != '.') || pointCount > 1)
				{
					throw InvalidArgException();
				}
			}
		}
		else if (_data.length() == 1 && isprint(_data[0]) && !isnumber(_data[0]))
		{
			int n = static_cast<int>(_data[0]);
			std::stringstream ss;
			ss << n;
			ss >> _data;
		}
	}
	_convDouble = atof(_data.c_str());
}

Conv::Conv(const Conv &src)
{
	*this = src;
}

Conv	&Conv::operator=(const Conv &src)
{
	if (this != &src)
	{
		this->_data = src._data;
	}
	return *this;
}

Conv::~Conv()
{
	
}

void Conv::setData(std::string data)
{
	this->_data = data;	
}

const std::string Conv::getData() const
{
	return this->_data;
}

void	Conv::present()
{
	toChar();
	toInt();
	toFloat();
	toDouble();
}

void	Conv::toChar()
{
	char	c;

	std::cout << "char: ";
	c = static_cast<char>(_convDouble);
	if (isnan(_convDouble) || isinf(_convDouble) ||
		static_cast<int>(_convDouble) > std::numeric_limits<char>::max() || 
		static_cast<int>(_convDouble) < std::numeric_limits<char>::min())
		std::cout << "impossible";
	else if (isprint(c))
		std::cout << "'" << c << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}

void	Conv::toInt()
{
	int		i;

	std::cout << "int: ";
	if (isnan(_convDouble) || isinf(_convDouble) || 
		static_cast<long>(_convDouble) > std::numeric_limits<int>::max() || 
		static_cast<long>(_convDouble) < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
	{
		i = static_cast<int>(_convDouble);
		std::cout << i;
	}
	std::cout << std::endl;
}

void	Conv::toFloat()
{
	float	f;

	std::cout << "float: ";
	if (isnan(_convDouble))
		std::cout << "nanf";
	else if (isinf(_convDouble))
	{
		(_convDouble < 0) ? std::cout << "-" : std::cout << "+";;
		std::cout << "inff";
	}
	else
	{
		f = static_cast<float>(_convDouble);
		std::cout.precision(_getPrecision());
		std::cout.setf( std::ios::fixed, std:: ios::floatfield);
		std::cout << f << "f";
	}
	std::cout << std::endl;
}

void	Conv::toDouble()
{
	double	d;

	std::cout << "double: ";
	if (isnan(_convDouble))
		std::cout << "nan";
	else if (isinf(_convDouble))
	{
		(_convDouble < 0) ? std::cout << "-" : std::cout << "+";;
		std::cout << "inf";
	}
	else
	{
		d = static_cast<double>(_convDouble);
		std::cout.precision(_getPrecision());
		std::cout.setf( std::ios::fixed, std:: ios::floatfield);
		std::cout << d;
	}
	std::cout << std::endl;
}

int			Conv::_getPrecision()
{
	size_t i;
	int precision;

	precision = 1;
	if ((i = this->_data.find_first_of('.')) != std::string::npos && i != this->_data.length() - 1)
	{
		precision--;
		for (++i; i < _data.length() && isdigit(_data[i]); i++)
			++precision;
	}
	return precision;
}

bool		Conv::_isScientific()
{
	std::string science[8] = {"nan", "nanf", "inf", "inff", "+inf", "-inf", "+inff", "-inff"};
	for (size_t i = 0; i < 8; i++)
	{
		if (_data == science[i])
			return true;
	}
	return false;
}

const char *Conv::InvalidArgException::what() const throw()
{
	return "Error: invalid argument.\n\nA valid argument should contains only: \n    ◊ digits + one and only one point '.' + one and only one 'f' character at the end [to express float type]\n  OR\n    ◊ one and only one displayable character";
}

const char *Conv::EmptyArgException::what() const throw()
{
	return "Error: empty argument.";
}