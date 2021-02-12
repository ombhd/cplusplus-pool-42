/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:58:42 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/12 10:14:54 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_H
#define PEON_H

#include <iostream>
#include <string>

#include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon();
	Peon(std::string name);
	Peon(const Peon &);
	~Peon();
	Peon &operator=(const Peon &);
	virtual void getPolymorphed() const;

};



#endif // !PEON_H