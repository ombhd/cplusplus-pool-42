/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:56:22 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/18 16:52:10 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"

int main(void)
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new TacticalMarine;
	ISpaceMarine* sp = new TacticalMarine;
	ISpaceMarine* sp0 = new TacticalMarine;
	ISpaceMarine* sp1 = jim->clone();
	ISquad* vlc = new Squad;
	

	std::cout << "after pushing sp : len = " << vlc->push(sp) << std::endl;
	std::cout << "after pushing sp0 : len = " << vlc->push(sp0) << std::endl;
	std::cout << "after pushing sp1 : len = " << vlc->push(sp1) << std::endl;
	std::cout << "after pushing bob : len = " << vlc->push(bob) << std::endl;
	std::cout << "after pushing jim : len = " << vlc->push(jim) << std::endl;
	
	std::cout << sp << " || " << sp0 << " || " << sp1 << " || " << bob << " || " << jim << std::endl;
	std::cout << vlc->getUnit(0) << " || " << vlc->getUnit(1) << " || " 
			  << vlc->getUnit(2) << " || " << vlc->getUnit(3) << " || " << vlc->getUnit(4) << std::endl;
	std::cout << "len = " << vlc->getCount() << std::endl;
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	
	delete vlc;
	return 0;
}