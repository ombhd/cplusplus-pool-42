/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:24:02 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/27 18:26:47 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
#define WHATEVER_H


// swap template function
template <typename T>
void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// max template function
template <typename T>
T const & max(T const &a, T const &b)
{
	return (a > b ? a : b);
}

// min template function
template <typename T>
T const & min(T const &a, T const &b)
{
	return (a < b ? a : b);
}


#endif // !WHATEVER_H