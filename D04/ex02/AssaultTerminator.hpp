/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:28:35 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/18 15:53:02 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULT_TERMINATOR_H
#define ASSAULT_TERMINATOR_H

#include <iostream>

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
	public:
		AssaultTerminator();
		AssaultTerminator(const AssaultTerminator &);
		AssaultTerminator &operator=(const AssaultTerminator &);
		~AssaultTerminator();
		ISpaceMarine *clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;

	private:
	
};


#endif // !ASSAULT_TERMINATOR_H