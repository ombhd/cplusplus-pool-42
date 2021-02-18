/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:17:20 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/18 16:22:43 by obouykou         ###   ########.fr       */
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
		~Squad();
		Squad &operator=(const Squad &);
		int getCount() const;
		ISpaceMarine* getUnit(int) const;
		int push(ISpaceMarine*);

	private:
		spMarine	*_spaceMarine;
		void		_insert(spMarine **lst, ISpaceMarine *marine);
		spMarine	*_destroySpaceMarine(spMarine *sMar);
};


#endif // !SQUAD_H
