/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:55:52 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/31 19:30:49 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H

#include <unistd.h>
#include <ctime>

#include "Zombie.hpp"

class ZombieHorde
{
private:
	std::string	genRandomString(void);

public:
	ZombieHorde(int N);
	~ZombieHorde();
};


#endif // !ZOMBIE_HORDE_H