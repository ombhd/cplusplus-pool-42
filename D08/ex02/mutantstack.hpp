/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:03:05 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/31 13:47:19 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_H
#define MUTANT_STACK_H

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	private:
		
	public:
		MutantStack<T>() : std::stack<T>() {}
		MutantStack<T>(MutantStack const &src) : std::stack<T>(src){}
		virtual ~MutantStack<T>(){}
	
    typedef typename std::stack<T>::container_type::iterator					iterator;
    typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator			reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
	
	iterator	begin()			{ return std::stack<T>::c.begin(); }
	
	iterator	end()			{ return std::stack<T>::c.end(); }
	
	const_iterator cbegin()		{ return ( std::stack<T>::c.cbegin() );}
	
	const_iterator cend()		{ return ( std::stack<T>::c.cend() ); }

	reverse_iterator rbegin()	{ return ( std::stack<T>::c.rbegin() );}
	
	reverse_iterator rend()		{ return ( std::stack<T>::c.rend() );}

	const_reverse_iterator crbegin()	{ return ( std::stack<T>::c.crbegin() );}
	
	const_reverse_iterator crend()		{ return ( std::stack<T>::c.crend() );}
	
};


#endif // !MUTANT_STACK_H