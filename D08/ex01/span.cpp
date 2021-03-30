/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:47:54 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/30 18:50:31 by obouykou         ###   ########.fr       */
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
	std::vector<int>().swap(this->_array);
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

void Span::addNumber(int num)
{
	if (this->_array.size() == this->_N)
		throw FullSpanException();
	this->_array.push_back(num);
	this->_isSorted = false;
}

long	Span::shortestSpan()
{
	if (this->_array.size() < 2)
		throw NoSpanFound();
	if (!this->_isSorted)
	{
		std::sort(this->_array.begin(), this->_array.end());
		this->_isSorted = true;
	}
	long int sp = static_cast<long int>(this->_array.at(1)) - static_cast<long int>(this->_array.at(0));
	for (size_t i = 1; i < this->_array.size() - 1; i++)
	{
		if (this->_array.at(i + 1) - this->_array.at(i) < sp)
			sp = this->_array.at(i + 1) - this->_array.at(i);
	}
	return sp;
}

long	Span::longestSpan()
{
	if (this->_array.size() < 2)
		throw NoSpanFound();
	if (!this->_isSorted)
	{
		std::sort(this->_array.begin(), this->_array.end());
		this->_isSorted = true;
	}
	long int lp = static_cast<long int>(*(this->_array.end() - 1)) - static_cast<long int>(this->_array.at(0));
	return (lp);
}

const char *Span::FullSpanException::what() const throw()
{
	return "Full Span [ No more space for new numbers ]";
}

const char *Span::NoSpanFound::what() const throw()
{
	return "No enough numbers to make span with";
}