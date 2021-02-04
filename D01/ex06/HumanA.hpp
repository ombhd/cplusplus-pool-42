/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:16:39 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/03 18:22:12 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
#define HUMAN_A_H

#include "Weapon.hpp"
#include "iostream"

class HumanA
{
private:
	std::string name;
	Weapon		&weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void		setName(std::string);
	std::string	getName();
	void		setWeapon(Weapon weapon);
	Weapon		getWeapon();
	void		attack();
};



#endif // !HUMAN_A_H