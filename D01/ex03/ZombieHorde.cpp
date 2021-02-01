/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:58:21 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/01 10:04:44 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	numberOfZombies = N;
	zombieHorde = new Zombie[numberOfZombies];

	srand((unsigned int)time(NULL));
	for(int i = 0; i < numberOfZombies; i++)
	{
		zombieHorde[i].setName(genRandomString());
		zombieHorde[i].setType(genRandomString());
	}
}

ZombieHorde::~ZombieHorde()
{
	delete [] zombieHorde;
}

std::string	ZombieHorde::genRandomString(void) 
{
    std::string randomString;
    const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
	int len;
    
    len = random() % 6 + 4;
	randomString.reserve(len);
    for (int i = 0; i < len; ++i)
	{
        randomString += alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	return randomString;
}

void		ZombieHorde::announce()
{
	for (int i = 0; i < numberOfZombies; i++)
	{
		std::cout << std::endl;
		zombieHorde[i].announce();
	}
	
}
