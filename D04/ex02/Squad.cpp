/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:18:58 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/18 16:50:35 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad():
_spaceMarine(NULL)
{
	return ;
}

spMarine *Squad::_destroySpaceMarine(spMarine *sMar)
{
	spMarine *tmp;

	while (sMar)
	{
		tmp = sMar;
		sMar = sMar->next;
		delete tmp->marine;
		delete tmp;
	}
	return NULL;
}

Squad::~Squad()
{
	this->_spaceMarine = this->_destroySpaceMarine(this->_spaceMarine);
	return ;
}

Squad::Squad(const Squad &src)
{
	*this = src;
	return ;
}

Squad &Squad::operator=(const Squad &sq)
{
	if (this != &sq)
	{
		this->_spaceMarine = this->_destroySpaceMarine(this->_spaceMarine);
		spMarine *tmp;
		this->_spaceMarine = NULL;
		if ((tmp = sq._spaceMarine))
		{
			this->push(tmp->marine);
			while (tmp->next)
			{
				tmp = tmp->next;
				this->push(tmp->marine);
			}
		}
	}
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
	while (tmp)
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
		N--;
	}
	return tmp->marine;
}

void	Squad::_insert(spMarine **lst, ISpaceMarine *marine)
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
	spMarine *tmp;

	if (newMarine)
	{
		if (this->_spaceMarine == NULL)
			_insert(&this->_spaceMarine, newMarine);
		else
		{
			tmp = this->_spaceMarine;
			if (tmp->marine == newMarine)
				return this->getCount();
			while (tmp->next)
			{
				tmp = tmp->next;
				if (tmp->marine == newMarine)
					return this->getCount();
			}
			_insert(&(tmp->next), newMarine);
		}
	}
	return this->getCount();
}
