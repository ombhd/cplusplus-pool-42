/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:44:47 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/28 12:57:25 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <iterator>

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vec(12);

	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i] = i;
		std::cout << vec.at(i) << std::endl;
	}
	std::vector<int>::const_iterator iter = vec.begin();
	
	easyfind(iter, 4);
	
	return 0;
}