/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:51:19 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/07 10:17:10 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ctime"

void	sep(void)
{
	usleep(500000);
	std::cout << std::endl;	
}

int		main(void) 
{
	// FragTrap
	std::cout << "\nGame start ..\n" << std::endl;
	sleep(1);
	FragTrap bob("bob");
	sep();
	FragTrap omar("omar");
	sep();
	FragTrap hacker("hacker");
	sep();
	
	// ScavTrap
	ScavTrap vilan("vilan");
	sep();
	ScavTrap shrider("shrider");
	sep();
	ScavTrap mark("mark");
	sep();
	std::cout << "\nStart fighting .." << std::endl;
	sep();
	srand(time(NULL));
	while (omar.is_alive())
	{
		// ClapTrap
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

		// ScavTrap
		vilan.meleeAttack(hacker.getName());
		sep();
		if (hacker.is_alive())
		{
			vilan.beRepaired(vilan.getMeleeAttackDamage());
			sep();
		}
		hacker.takeDamage(vilan.getMeleeAttackDamage());
		sep();
		shrider.challengeNewcomer(omar.getName());
		sep();		
		shrider.takeDamage(shrider.getChallengeNewComerPoints());
		sep();
		hacker.rangedAttack(omar.getName());
		sep();
		omar.takeDamage(hacker.getRangedAttackDamage());
		sep();
	}
	return 0;
}