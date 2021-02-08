/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:51:19 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/08 18:45:02 by obouykou         ###   ########.fr       */
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
	bool ob = true;
	bool ov = true;
	
	std::cout << "\nGame start ..\n" << std::endl;
	sleep(1);
	FragTrap bigFrag("bigFrag");
	sep();
	FragTrap bob("bob");
	sep();
	FragTrap hacker("hacker");
	sep();
	
	// ScavTrap
	ScavTrap bigScav("bigScav");
	sep();
	ScavTrap shrider("shrider");
	sep();
	ScavTrap mark("mark");
	sep();
	std::cout << "\nStart fighting .." << std::endl;
	sep();
	srand(time(NULL));
	while (bigFrag.is_alive() && bigScav.is_alive())
	{
		// ClapTrap
		if (bob.is_alive())
			bigFrag.meleeAttack(bob.getName());
		sep();		
		if (!bob.is_alive() && ob)
		{
			bigFrag.beRepaired(bigFrag.getMeleeAttackDamage());
			sep();
			ob = false;
		}
		bob.takeDamage(bigFrag.getMeleeAttackDamage());
		sep();
		bob.vaulthunter_dot_exe(bigFrag.getName());
		sep();		
		bigFrag.takeDamage(bob.getVaulhunterDamagePoints());
		sep();
		hacker.rangedAttack(bigFrag.getName());
		sep();
		bigFrag.takeDamage(hacker.getRangedAttackDamage());
		sep();

		// ScavTrap
		bigScav.meleeAttack(shrider.getName());
		sep();
		if (ov)
		{
			bigScav.beRepaired(bigScav.getMeleeAttackDamage());
			sep();
			ov = false;
		}
		shrider.takeDamage(bigScav.getMeleeAttackDamage());
		sep();
		shrider.challengeNewcomer(bigFrag.getName());
		sep();
		shrider.takeDamage(shrider.getChallengeNewComerPoints());
		sep();
		mark.rangedAttack(bigScav.getName());
		sep();
		bigScav.takeDamage(mark.getRangedAttackDamage());
		sep();
	}
	return 0;
}