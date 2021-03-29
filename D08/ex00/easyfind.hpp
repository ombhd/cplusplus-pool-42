/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:27:36 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/29 14:38:05 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_H
#define EASY_FIND_H

#include <algorithm>

template <class T>
bool easyfind(T const &container, int const &value)
{
	return find(container.begin(), container.end(), value) != container.end();
}

#endif // !EASY_FIND_H