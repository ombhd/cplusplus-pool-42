/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:21:00 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/17 19:21:39 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_SPACE_MARINE_H
#define I_SPACE_MARINE_H

class ISpaceMarine
{
	public:
	virtual ~ISpaceMarine() {}
	virtual ISpaceMarine* clone() const = 0;
	virtual void battleCry() const = 0;
	virtual void rangedAttack() const = 0;
	virtual void meleeAttack() const = 0;
};

#endif // !I_SPACE_MARINE_H