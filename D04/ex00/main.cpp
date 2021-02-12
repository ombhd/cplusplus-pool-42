/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:00:05 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/12 11:22:33 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"
#include "Sorcerer.hpp"
#include "Peon.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);


	std::cout << "Test: jim.getPolymorphed() ==> "; 
	jim.getPolymorphed();
	std::cout << "Test: jim.getName() ==> "; 
	jim.getName();
	
	Victim *v = new Peon("jimmy");
	v->getPolymorphed();
	delete v;

	return 0;
}

AWeapon.[hpp cpp]  PlasmaRifle.[hpp cpp]  PowerFist.[hpp cpp]  Enemy.[hpp cpp]  SuperMutant.[hpp cpp]  RadScorpion.[hpp cpp]  Character.[hpp cpp]  main.cpp