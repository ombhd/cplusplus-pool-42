/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:17:20 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/18 10:20:39 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_H
#define SQUAD_H

#include <iostream>
#include "ISquad.hpp"

struct spMarine
{
	ISpaceMarine	*marine;
	struct spMarine	*next;
};

class Squad : public ISquad
{	
	public:
		Squad();
		Squad(const Squad &);
		virtual ~Squad() {}
		Squad &operator=(const Squad &);
		int getCount() const;
		ISpaceMarine* getUnit(int) const;
		int push(ISpaceMarine*);

	private:
		spMarine *_spaceMarine;
};


#endif // !SQUAD_H
