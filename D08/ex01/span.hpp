/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:12:11 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/29 17:06:55 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define	SPAN_H

#include <exception>
#include <algorithm>

class Span
{
private:
	unsigned int _N;
	unsigned int _index;
	bool _isSorted;
	int *_array;
	
public:
	Span();
	Span(unsigned int);
	Span(Span const &);
	~Span();
	Span &operator=(Span const &span);
	int	shortestSpan();
	int	longestSpan();

	template<typename T>
	void Span::addNumber(T & begin, T & end)
	{
		typename T::iterator it;	
	}
	// {
	// 	if (this->_index == this->_N)
	// 		throw FullSpanException();
	// 	this->_array[this->_index++] = number;
	// 	this->_isSorted = false;
	// }

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