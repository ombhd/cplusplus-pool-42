/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:03:05 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/31 16:46:10 by obouykou         ###   ########.fr       */
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
		// default constructor  
		MutantStack<T>() : std::stack<T>() {}
		
		// copy constructor  
		MutantStack<T>(MutantStack<T> const &src) : std::stack<T>(src){}
		
		// destructor
		virtual ~MutantStack<T>(){}
		
		// assignation operator overload
		MutantStack<T> &operator=(MutantStack<T> const &src)
		{
			if (this != &src)
				this->std::stack<T>::operator=(src);
			return *this;
		}
	
		// types aliases for iterators`
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
		
		
		// required function members to make MutantStack iterable
		
		// Normal iterator and const normal iterator: begin() / end() 
		iterator		begin()			{ return std::stack<T>::c.begin(); }
		const_iterator	begin() const	{ return ( std::stack<T>::c.begin() );}
		
		iterator		end()			{ return std::stack<T>::c.end(); }
		const_iterator	end()	const	{ return ( std::stack<T>::c.end() ); }
		
		// reverse iterator and const reverse iterator: [ rbegin() / rend() ] 
		reverse_iterator		rbegin()		{ return ( std::stack<T>::c.rbegin() );}
		const_reverse_iterator	rbegin() const	{ return ( std::stack<T>::c.rbegin() );}
		
		reverse_iterator		rend()			{ return ( std::stack<T>::c.rend() );}
		const_reverse_iterator	rend()	const	{ return ( std::stack<T>::c.rend() );}
	
};


#endif // !MUTANT_STACK_H