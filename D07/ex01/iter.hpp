/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:43:42 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/30 13:29:04 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>
void	iter(T *arr, const size_t &count, void (*func)(T &))
{
	for (size_t i = 0; i < count; i++)
	{
		func(arr[i]);
	}
}

#endif // !ITER_H
