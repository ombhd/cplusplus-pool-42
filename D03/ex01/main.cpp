/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:51:19 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/06 18:43:02 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ctime"

void	sep(void)
{
	usleep(500000);
	std::cout << std::endl;	
}

int		main(void) 
{
	std::cout << "\nGame start ..\n" << std::endl;
	sleep(1);
	FragTrap bob("bob");
	sep();
	FragTrap omar("omar");
	sep();
	FragTrap hacker("hacker");
	sep();

	std::cout << "\nStart fighting .." << std::endl;
	sep();
	srand(time(NULL));
	while (omar.is_alive())
	{
		omar.meleeAttack(bob.getName());
		sep();
		
		if (bob.is_alive())
		{
			omar.beRepaired(omar.getMeleeAttackDamage());
			sep();
		}
		bob.takeDamage(omar.getMeleeAttackDamage());
		sep();

		bob.vaulthunter_dot_exe(omar.getName());
		sep();
		
		
		omar.takeDamage(bob.getVaulhunterDamagePoints());
		sep();

		hacker.rangedAttack(omar.getName());
		sep();

		omar.takeDamage(hacker.getRangedAttackDamage());
		sep();

	}
	return 0;
}