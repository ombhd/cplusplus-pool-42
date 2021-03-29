/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:44:47 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/29 15:07:59 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <ctime>

#include "easyfind.hpp"

int main(void)
{
	srand(clock());
	int random;

	// VECTOR
	std::cout << "\n\033[33mVECTOR Tests\033[0m\n" << std::endl;
	std::vector<int> vec(12);
	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i] = rand() % 13;
		std::cout << vec.at(i) << "\t";
	}
	// first test
	std::cout << "\n\n - searching in vector: " << std::endl;
	random = rand() % 13;
	if (easyfind(vec, random))
		std::cout << random << ": Found" << std::endl;
	else
		std::cout << random << ": Not Found" << std::endl;

	// second test
	random = rand() % 13;
	if (easyfind(vec, random))
		std::cout << random << ": Found" << std::endl;
	else
		std::cout << random << ": Not Found" << std::endl;

	// third test
	random = rand() % 13;
	if (easyfind(vec, random))
		std::cout << random << ": Found" << std::endl;
	else
		std::cout << random << ": Not Found" << std::endl;

	// LIST 
	std::cout << "\n\n\033[33mLIST Tests\033[0m\n" << std::endl;

	std::list<int> lst;
	for (size_t i = 0; i < 12; i++)
	{
		random = rand() % 13;
		lst.push_back(random);
		std::cout << random << "\t";
	}
	
	// first test
	std::cout << "\n\n - searching in list: " << std::endl;
	random = rand() % 13;
	if (easyfind(lst, random))
		std::cout << random << ": Found" << std::endl;
	else
		std::cout << random << ": Not Found" << std::endl;

	// second test
	random = rand() % 13;
	if (easyfind(lst, random))
		std::cout << random << ": Found" << std::endl;
	else
		std::cout << random << ": Not Found" << std::endl;

	// third test
	random = rand() % 13;
	if (easyfind(lst, random))
		std::cout << random << ": Found" << std::endl;
	else
		std::cout << random << ": Not Found" << std::endl;
	
	std::cout  << std::endl;
	
	
	return 0;
}