/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:36:10 by obouykou          #+#    #+#             */
/*   Updated: 2021/06/22 19:10:34 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int main()
{
	Zombie zombie;
	Zombie *zombie_ptr;
	ZombieEvent zombieEvent;

	// Zombie class
	zombie.setName("Mark");
	zombie.setType("brains destroyer");
	zombie.announce();

	// ZombieEvent class
	zombie_ptr = zombieEvent.newZombie("Eren");
	std::cout << "\nAfter calling newZombie()" << std::endl;
	zombie_ptr->announce();
	zombieEvent.setZombieType("bones destroyer");
	std::cout << "\nAfter calling setZombieType()" << std::endl;
	zombie_ptr->announce();
	std::cout << "\nCalling setZombieType()" << std::endl;
	zombieEvent.randomChump();
	delete zombie_ptr;
	
	return (0);
}