/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:56:22 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/18 18:01:01 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"

void	sep()
{
	std::cout << std::endl;
	usleep(500000);
}

int main(void)
{
	sep();
	ISpaceMarine* bobi = new AssaultTerminator;
	sep();
	ISpaceMarine* bob = new AssaultTerminator;
	sep();
	ISpaceMarine* jim = new TacticalMarine;
	sep();
	ISpaceMarine* sp = new AssaultTerminator;
	sep();
	ISpaceMarine* sp0 = new TacticalMarine;
	sep();
	ISpaceMarine* sp1 = bob->clone();
	ISpaceMarine* sp2 = jim->clone();
	ISpaceMarine* sp3 = NULL;
	ISquad* vlc = new Squad;
	

	sep();
	std::cout << "after pushing sp : len = " << vlc->push(sp) << std::endl;
	sep();
	std::cout << "after pushing sp0 : len = " << vlc->push(sp0) << std::endl;
	sep();
	std::cout << "after pushing sp1 : len = " << vlc->push(sp1) << std::endl;
	sep();
	std::cout << "after pushing sp1 (2nd time) : len = " << vlc->push(sp1) << std::endl;
	sep();
	std::cout << "after pushing bob : len = " << vlc->push(bob) << std::endl;
	sep();
	std::cout << "after pushing jim : len = " << vlc->push(jim) << std::endl;
	sep();
	std::cout << "after pushing sp2 : len = " << vlc->push(sp2) << std::endl;
	sep();
	std::cout << "after pushing sp3 (NULL) : len = " << vlc->push(sp3) << std::endl;
	sep();

	
	std::cout << sp << " || " << sp0 << " || " << sp1 << " || " 
			  << bob << " || " << jim << " || " << sp2 << " || " << sp3 << std::endl;
	std::cout << vlc->getUnit(0) << " || " << vlc->getUnit(1) << " || " 
			  << vlc->getUnit(2) << " || " << vlc->getUnit(3) << " || " 
			  << vlc->getUnit(4) << " || " << vlc->getUnit(5) << " || "  << vlc->getUnit(6) << std::endl;

	sep();
	std::cout << "len = " << vlc->getCount() << std::endl;
	sep();
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		sep();
	}
	
	sep();
	std::cout << "deleting bobi: starting.." << std::endl;
	delete bobi;
	std::cout << "deleting bobi: done !" << std::endl;
	sep();
	delete vlc;
	sep();
	return 0;
}