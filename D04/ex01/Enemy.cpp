/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:53:49 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/12 12:59:53 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy()
{
	return ;
}

Enemy::Enemy(int hp, std::string const & type):
_hitPoints(hp),
_type(type)
{
	return ;
}

Enemy::Enemy(const Enemy &src)
{
	*this = src;
	return ;
}

Enemy::~Enemy()
{
	return ;
}

Enemy 		&Enemy::operator=(const Enemy &src)
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_hitPoints = src._hitPoints;
	}
	return *this;
}

std::string  Enemy::getType() const
{
	return this->_type;
}

int Enemy::getHP() const
{
	return this->_hitPoints;
}


void Enemy::takeDamage(int damage)
{
	if (damage > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= damage;
	return ;
}
