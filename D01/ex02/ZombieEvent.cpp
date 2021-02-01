/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:35:30 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/01 09:59:50 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
}

ZombieEvent::~ZombieEvent()
{
}

Zombie		*ZombieEvent::newZombie(std::string name)
{
	Zombie *zombie = new Zombie();
	zombie->setName(name);
	return (zombie);
}

void		ZombieEvent::setZombieType(Zombie &zombie, std::string type)
{
	zombie.setType(type);
}

std::string	ZombieEvent::genRandomString(const int len) 
{
    std::string randomString;
    const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
    
    randomString.reserve(len);
    for (int i = 0; i < len; ++i)
	{
        randomString += alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	return randomString;
}

void		ZombieEvent::randomChump()
{
	Zombie zombie;
	
    srand((unsigned int)time(NULL));
	zombie.setName(genRandomString(7));
	zombie.setType(genRandomString(5));
	zombie.announce();
}