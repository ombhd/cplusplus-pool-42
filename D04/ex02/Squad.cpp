/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:18:58 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/18 10:43:57 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad():
_spaceMarine(NULL)
{
	return ;
}

Squad::~Squad()
{
	spMarine *tmp;
	
	while (this->_spaceMarine)
	{
		tmp = this->_spaceMarine;
		this->_spaceMarine = this->_spaceMarine->next;
		delete tmp;
	}
	return ;
}

Squad::Squad(const Squad &)
{
	return ;
}

Squad &Squad::operator=(const Squad &sq)
{
	return *this;
}

int Squad::getCount() const
{
	spMarine *tmp;
	int length;
	
	tmp = this->_spaceMarine;
	if (!tmp)
		return (0);
	length = 0;
	while (tmp->next)
	{
		length++;
		tmp = tmp->next;
	}
	return length;	
}

ISpaceMarine* Squad::getUnit(int N) const
{
	int len;
	spMarine *tmp;

	len = this->getCount();
	if (N < 0 || N >= len)
		return NULL;
	tmp = this->_spaceMarine;
	while (tmp->next)
	{
		if (N == 0)
			break ;
		tmp = tmp->next;
	}
	return tmp->marine;
}

void	insert(spMarine **lst, ISpaceMarine *marine)
{
	*lst = new spMarine;
	if (!lst)
	{
		std::cout << "Can't insert the new marine, memory allocation failed!" << std::endl;
		return ;
	}
	(*lst)->marine= marine;
	(*lst)->next = NULL;
}

int Squad::push(ISpaceMarine *newMarine)
{
	int len;
	spMarine *tmp;

	if (newMarine)
	{
		if (this->_spaceMarine == NULL)
			insert(&this->_spaceMarine, newMarine);
		else
		{
			tmp = this->_spaceMarine;
			if (tmp->marine == newMarine)
				return this->getCount();
			while (tmp->next)
			{
				if (tmp->marine == newMarine)
					return this->getCount();
				tmp = tmp->next;
			}
			insert(&tmp->next, newMarine);
		}
	}
	return this->getCount();
}
