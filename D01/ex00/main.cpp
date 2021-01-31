/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:31:21 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/31 16:09:29 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	describePony(Pony pony)
{
	std::cout << "\n-----------------------------------------------" << std::endl;
	std::cout << "Name          : " << pony.getName() << std::endl;
	std::cout << "Main Color    : " << pony.getMainColor() << std::endl;
	std::cout << "Height        : " << pony.getHeight() << "cm"<< std::endl;
	std::cout << "-----------------------------------------------\n" << std::endl;
}

void	ponyOnTheHeap(std::string name, std::string color, int height)
{
	Pony *pony = new Pony(name);
	pony->setMainColor(color);
	pony->setHeight(height);
	std::cout << " ===> On The Heap" << std::endl;
	describePony(*pony);
	delete pony;
}

void	ponyOnTheStack(std::string name, std::string color, int height)
{
	Pony pony = Pony(name);
	pony.setMainColor(color);
	pony.setHeight(height);
	std::cout << " ===> On The Stack" << std::endl;
	describePony(pony);
}

int		main(void)
{
	ponyOnTheHeap("Baika", "Brown", 137);
	ponyOnTheStack("Hala", "White", 112);
	return (0);
}