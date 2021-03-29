/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:47:54 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/29 17:03:01 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span():
_N(0),
_index(0),
_isSorted(false),
_array(new int[0])
{

}

Span::Span(unsigned int n):
_N(n),
_index(0),
_isSorted(false),
_array(new int[_N])
{
	
}

Span::Span(Span const & src)
{
	*this = src;
}

Span::~Span()
{
	delete [] this->_array;
}

Span &Span::operator=(Span const &span)
{
	if (this != &span)
	{
		this->~Span();
		this->_N = span._N;
		this->_index = span._index;
		this->_isSorted = span._isSorted;
		this->_array = new int[this->_N];
		for (unsigned int i = 0; i < this->_N; i++)
		{
			this->_array[i] = span._array[i];
		}
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
	if (this->_index < 1)
		throw NoSpanFound();
	if (!this->_isSorted)
	{
		std::sort(this->_array, this->_array + this->_index);
		this->_isSorted = true;
	}
	return (this->_array[1] - this->_array[0]);
}

int	Span::longestSpan()
{
	if (this->_index < 1)
		throw NoSpanFound();
	if (!this->_isSorted)
	{
		std::sort(this->_array, this->_array + this->_index);
		this->_isSorted = true;
	}
	return (this->_array[this->_index - 1] - this->_array[0]);
}

const char *Span::FullSpanException::what() const throw()
{
	return "Full Span";
}

const char *Span::NoSpanFound::what() const throw()
{
	return "No Span Found";
}