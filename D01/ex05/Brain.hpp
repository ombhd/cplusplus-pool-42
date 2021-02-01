/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:19:24 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/01 12:08:01 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define	BRAIN_H

#include <string>
#include <iostream>
#include <sstream>

class Brain
{
private:
	int 		iq;
	std::string	toupperAdress(std::string str) const;

public:
	Brain(void);
	~Brain(void);
	void		setIQ(int iq);
	int			getIQ(void);
	std::string identify(void) const;

};


#endif // !BRAIN_H