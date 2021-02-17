/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:20:02 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/17 19:22:03 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_SQUAD_H
#define I_SQUAD_H

#include "ISpaceMarine.hpp"

class ISquad
{
	public:
	virtual ~ISquad() {}
	virtual int getCount() const = 0;
	virtual ISpaceMarine* getUnit(int) const = 0;
	virtual int push(ISpaceMarine*) = 0;
};


#endif // !I_SQUAD_H