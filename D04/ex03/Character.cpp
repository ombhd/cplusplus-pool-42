/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:38:03 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/19 12:04:01 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character():
_name("default"),
_numberOfMateria(0)
{
	_initInventory();
	return ;
}

Character::Character(std::string name):
_name(name),
_numberOfMateria(0)
{
	_initInventory();
	return ;
}

Character::Character(const Character &src)
{
	*this = src;
}

Character &Character::operator=(const Character &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		_destroyInventory();
		this->_numberOfMateria = src._numberOfMateria;
		for (int i = 0; i < _numberOfMateria; i++)
			_materiaInventory[i] = src._materiaInventory[i];
	}
	return *this;
}


Character::~Character()
{
	_destroyInventory();
	return ;
}

void		Character::_initInventory()
{
	for (int i = 0; i < MAX_INV; i++)
		_materiaInventory[i] = NULL;
}

void		Character::_destroyInventory()
{
	for (int i = 0; i < _numberOfMateria; i++)
	{
		delete _materiaInventory[i];
		_materiaInventory[i] = NULL;
	}
}

std::string const & Character::getName() const
{
	return _name;
}

void		Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < _numberOfMateria)
		_materiaInventory[idx]->use(target);
	else
		std::cout << "invalid index!" << std::endl;
}

void Character::equip(AMateria* m)
{
	if (m && _numberOfMateria < MAX_INV)
		_materiaInventory[_numberOfMateria++] = m;
	else if (!m)
		std::cout << "You are trying to equip non-existent Materia!" << std::endl;
	else
		std::cout << "inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < _numberOfMateria)
	{
		if (idx == MAX_INV - 1)
			_materiaInventory[idx] = NULL;
		else	
			for (; idx < _numberOfMateria; idx++)
				_materiaInventory[idx] = _materiaInventory[idx + 1];
		_numberOfMateria--;
	}
	else
		std::cout << "invalid index!" << std::endl;
}

