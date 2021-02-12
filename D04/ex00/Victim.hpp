/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:58:42 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/12 10:22:36 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_H
#define VICTIM_H

#include <iostream>
#include <string>

class Victim
{
public:
	Victim();
	Victim(std::string name);
	Victim(const Victim &);
	virtual ~Victim();
	Victim &operator=(const Victim &);
	std::string getName() const;
	virtual void getPolymorphed() const;
protected:
	std::string _name;
};

std::ostream &operator<<(std::ostream &, const Victim &);


#endif // !VICTIM_H