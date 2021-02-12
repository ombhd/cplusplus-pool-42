/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:53:29 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/12 12:46:14 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMA_RIFLE_H
#define PLASMA_RIFLE_H

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
	public:
		PlasmaRifle();
		PlasmaRifle(const PlasmaRifle &src);
		virtual ~PlasmaRifle();
		PlasmaRifle 		&operator=(const PlasmaRifle &src);
		
		void	attack() const;


};


#endif // !PLASMA_RIFLE_H