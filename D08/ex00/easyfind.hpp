/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:27:36 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/28 13:01:12 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_H
#define EASY_FIND_H

#include <algorithm>
#include <exception>

template <class T>
T &easyfind(T const *container, int value)
{
	InIter iter;

	if ((iter = find(container.begin(), container.end(), value)) == last)
		throw std::exception();
	return iter;
}

#endif // !EASY_FIND_H