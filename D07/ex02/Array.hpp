/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:24:02 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/28 11:36:48 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <exception>

template <typename T>
class Array
{
	private:
		T 			*_array;
		unsigned int _len;

	public:
		// default constructor
		Array<T>(): _array(new T[0]), _len(0) { }
		
		// constructor with parameter (length)
		Array<T>(unsigned int l): _array(new T[l]), _len(l)
		{
			for (unsigned int i = 0; i < _len; i++)
			{
				_array[i] = 0;
			}
		}
		
		// copy constructor
		Array<T>(Array<T> const &arr)
		{
			*this = arr;
		}
		
		// destruct array
		~Array<T>()
		{
			delete [] this->_array; 
		}

		// assignation operator
		Array &operator=(Array<T> const &arr)
		{
			if (this != &arr)
			{
				this->_len = arr._len;
				_array = new T[_len];
				for (unsigned int i = 0; i < _len; i++)
				{
					this->_array[i] = arr._array[i];
				}
			}
			return *this;
		}
		
		// operator[]
		T &operator[](unsigned int i)
		{
			if (i >= this->_len)
				throw OutOfBoundsException();
			return this->_array[i];
		}
		
		// size function
		const unsigned int &size(void) const
		{
			return this->_len;
		}

		// Out of bounds exception class
		class OutOfBoundsException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Out of bounds";
				}
		};
};


#endif // !ARRAY_H