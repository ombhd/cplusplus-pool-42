/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:31:22 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/31 19:35:33 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEVENT_H
#define ZOMBIEVENT_H

#include <ctime>

#include "Zombie.hpp"

class ZombieEvent
{
private:
	std::string genRandomString(int len);

public:
	ZombieEvent();
	~ZombieEvent();
	void		setZombieType(Zombie &zombie, std::string type);
	Zombie  	*newZombie(std::string name);
	void		randomChump();
};


#endif // !ZOMBIEVENT_H