/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:53:49 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/17 15:32:39 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(): Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;   
	return ;
}

RadScorpion::RadScorpion(const RadScorpion &src)
{
	*this = src;
	return ;
}

RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *" << std::endl;
	return ;
}

RadScorpion 		&RadScorpion::operator=(const RadScorpion &src)
{
	if (this != &src)
		Enemy::operator=(src);
	return *this;
}
