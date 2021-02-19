/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:07:31 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/19 12:27:11 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource():
_numberOfMateria(0)
{
	_initInventory();
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this != &src)
	{
		_destroyInventory();
		this->_numberOfMateria = src._numberOfMateria;
		for (int i = 0; i < _numberOfMateria; i++)
			_materiaInventory[i] = src._materiaInventory[i];
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	_destroyInventory();
	return ;
}

void		MateriaSource::_initInventory()
{
	for (int i = 0; i < MAX_INV; i++)
		_materiaInventory[i] = NULL;
}

void		MateriaSource::_destroyInventory()
{
	for (int i = 0; i < _numberOfMateria; i++)
	{
		delete _materiaInventory[i];
		_materiaInventory[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria *mat)
{
	if (mat && _numberOfMateria < MAX_INV)
		_materiaInventory[_numberOfMateria++] = mat->clone();
	else if (!mat)
		std::cout << "You are trying to equip non-existent Materia!" << std::endl;
	else
		std::cout << "inventory is full!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _numberOfMateria; i++)
	{
		if (_materiaInventory[i]->getType() == type)
			return _materiaInventory[i]->clone();
	}
	std::cout << "Couldn't find the Materia which has " << type  << " as its type" << std::endl;
	return 0;
}