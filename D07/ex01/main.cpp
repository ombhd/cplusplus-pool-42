/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:52:38 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/28 11:29:14 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	print(int &a)
{
	std::cout << a << "\t";
}

void	arrDouble(int &a)
{
	a *= 2;
}

void	putNumber(int &a)
{
	static int i = 0;
	a = ++i;
}

int main(void)
{
	size_t len = 10;
	int *arr = new int[len];
	
	std::cout << "\n\033[33marray before editing : \033[0m" << std::endl;
	iter(arr, len, print);
	
	std::cout << "\n\n\033[33marray puting after editing : \033[0m" << std::endl;
	iter(arr, len, putNumber);
	iter(arr, len, print);
	
	std::cout << std::endl;
	
	std::cout << "\n\n\033[33marray puting after doubling all values : \033[0m" << std::endl;
	iter(arr, len, arrDouble);
	iter(arr, len, print);
	
	std::cout << std::endl;

	return 0;
}
