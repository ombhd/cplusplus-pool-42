/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:53:29 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/12 12:47:25 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWER_FIST_H
#define POWER_FIST_H

#include <iostream>

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	public:
		PowerFist();
		PowerFist(const PowerFist &src);
		virtual ~PowerFist();
		PowerFist 		&operator=(const PowerFist &src);
		
		void			attack() const;

};


#endif // !POWER_FIST_H