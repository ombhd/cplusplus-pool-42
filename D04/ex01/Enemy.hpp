/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:49:33 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/12 12:56:48 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

class Enemy
{
	public:
		Enemy();
		Enemy(int hp, std::string const & type);
		Enemy(const Enemy &src);
		virtual ~Enemy();
		Enemy 			&operator=(const Enemy &src);
		
		std::string		getType() const;
		int 			getHP() const;
		
		virtual void takeDamage(int);
	
	private:
		int			_hitPoints;
		std::string	_type;
		
};

#endif // !ENEMY_H