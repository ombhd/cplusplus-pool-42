/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:53:49 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/17 15:32:39 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(): Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;   
	return ;
}

SuperMutant::SuperMutant(const SuperMutant &src)
{
	*this = src;
	return ;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
	return ;
}

SuperMutant 		&SuperMutant::operator=(const SuperMutant &src)
{
	if (this != &src)
	    Enemy::operator=(src);
	return *this;
}

void SuperMutant::takeDamage(int damage)
{
    damage -= 3;
	Enemy::takeDamage(damage);
	return ;
}
