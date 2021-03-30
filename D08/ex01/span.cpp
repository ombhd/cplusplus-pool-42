/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:47:54 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/30 11:28:07 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span():
_N(0),
_isSorted(false)
{
	_array.reserve(0);
}

Span::Span(unsigned int n):
_N(n),
_isSorted(false)
{
	_array.reserve(this->_N);
}

Span::Span(Span const & src)
{
	*this = src;
}

Span::~Span()
{
	this->_array.clear();
}

Span &Span::operator=(Span const &span)
{
	if (this != &span)
	{
		this->~Span();
		this->_N = span._N;
		this->_isSorted = span._isSorted;
		this->_array = span._array;
	}
	return *this;
}

// void Span::addNumber(int number)
// {
// 	if (this->_index == this->_N)
// 		throw FullSpanException();
// 	this->_array[this->_index++] = number;
// 	this->_isSorted = false;
// }

int	Span::shortestSpan()
{
	if (this->_array.size() < 2)
		throw NoSpanFound();
	if (!this->_isSorted)
	{
		std::sort(this->_array.begin(), this->_array.end());
		this->_isSorted = true;
	}
	return (this->_array.at(1) - this->_array.at(0));
}

int	Span::longestSpan()
{
	if (this->_array.size() < 1)
		throw NoSpanFound();
	if (!this->_isSorted)
	{
		std::sort(this->_array.begin(), this->_array.end());
		this->_isSorted = true;
	}
	return (*(this->_array.end()) - this->_array.at(0));
}

const char *Span::FullSpanException::what() const throw()
{
	return "Full Span";
}

const char *Span::NoSpanFound::what() const throw()
{
	return "No Span Found";
}