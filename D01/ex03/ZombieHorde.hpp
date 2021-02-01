/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:55:52 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/01 09:56:05 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H

#include <ctime>

#include "Zombie.hpp"

class ZombieHorde
{
private:
	Zombie *zombieHorde;
	int		numberOfZombies;
	std::string	genRandomString(void);

public:
	ZombieHorde(int N);
	~ZombieHorde();
	void	announce();
};


#endif // !ZOMBIE_HORDE_H