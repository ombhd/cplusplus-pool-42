/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:12:11 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/30 17:40:18 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define	SPAN_H

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

class Span
{
private:
	unsigned int _N;
	bool _isSorted;
	
public:
	std::vector<int> _array;
	Span();
	Span(unsigned int);
	Span(Span const &);
	~Span();
	Span 	&operator=(Span const &span);
	long	shortestSpan();
	long	longestSpan();
	void 	addNumber(int);

	template < template < typename > class T >
	void addNumber(T<int*> begin, T<int*> end)
	{
		long int range = end - begin;
		if (range < 0)
			throw std::invalid_argument("begin adress is bigger than the end adress");
		if (range + this->_array.size() > this->_N)
			throw FullSpanException();
		this->_array.insert(this->_array.end(), begin, end);
		this->_isSorted = false;
	}

	class FullSpanException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class NoSpanFound : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

#endif // !SPAN_H