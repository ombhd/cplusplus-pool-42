/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:28:35 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/18 16:16:34 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICAL_MARINE_H
#define TACTICAL_MARINE_H

#include <iostream>

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
	public:
		TacticalMarine();
		TacticalMarine(const TacticalMarine &);
		TacticalMarine &operator=(const TacticalMarine &);
		~TacticalMarine();
		ISpaceMarine *clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;

	private:
	
};


#endif // !TACTICAL_MARINE_H