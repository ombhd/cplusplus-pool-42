/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:58:21 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/31 19:36:31 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	Zombie *zombieHorde = new Zombie[N];

	for(int i = 0; i < N; i++)
	{
		zombieHorde[i].setName(genRandomString());	
	}
}

ZombieHorde::~ZombieHorde()
{
}

std::string	ZombieHorde::genRandomString(void) 
{
    std::string randomString;
    const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int len;
    
    len = random() % 6 + 4;
	randomString.reserve(len);
    for (int i = 0; i < len; ++i)
	{
        randomString += alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	return randomString;
}