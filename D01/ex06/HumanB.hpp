/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:16:39 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/01 16:00:30 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "Weapon.hpp"
#include "iostream"

class HumanB
{
private:
	std::string name;
	Weapon		*weapon;

public:
	HumanB(std::string name);
	~HumanB();
	void		setName(std::string);
	std::string	getName();
	void		setWeapon(Weapon &weapon);
	Weapon		getWeapon();
	void		attack();
};



#endif // !HUMAN_B_H