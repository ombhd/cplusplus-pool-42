/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:52:31 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/28 11:50:17 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{	
	Array<int> array1;
	Array<int> array2(7);

	std::cout << "\n\033[33marray1: size = " << array1.size() << "\033[0m" << std::endl;

	std::cout << std::endl << "\033[33marray2: size = " << array2.size() << "\033[0m" << std::endl;
	for (size_t i = 0; i < array2.size(); i++)
	{
		array2[i] = i;
		std::cout <<  array2[i] << "\t";
	}
	std::cout << std::endl;

	array1 = array2;
	std::cout << std::endl << "After array1 = array2: " << std::endl;
	std::cout << "\033[33marray1: size = " << array1.size() << "\033[0m" << std::endl;
	for (size_t i = 0; i < array1.size(); i++)
	{
		std::cout << array1[i] << "\t";
	}

	array2 = array1;
	std::cout << std::endl << "\nAfter array2 = array1: " << std::endl;
	std::cout << "\033[33marray2: size = " << array2.size() << "\033[0m" << std::endl;
	for (size_t i = 0; i < array2.size(); i++)
	{
		std::cout << array1[i] << "\t";
	}

	std::cout << std::endl << std::endl;
	try
	{
		std::cout << "\033[33mTrying to access index 13 in array2 : \033[0m";
		array2[13] = 2;
		std::cout << "SUCCESS" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << "\033[33mTrying to access index 4 in array2 : \033[0m";
		array2[4] = 2;
		std::cout << "SUCCESS" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << std::endl;
	try
	{
		std::cout << "\033[33mTesting index -37 in array1: \033[0m";
		array1[-37] = 2;
		std::cout << "SUCCESS" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	return (0);
}