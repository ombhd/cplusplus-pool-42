/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:17:33 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/31 18:55:26 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string name;
	std::string type;
	
public:
	Zombie();
	~Zombie();
	void 		setName(std::string);
	std::string getName(void);
	void 		setType(std::string);
	std::string getType(void);
	void		announce();
};


#endif // !ZOMBIE_H