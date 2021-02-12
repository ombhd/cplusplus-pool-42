/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:58:42 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/12 09:52:55 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_H
#define SORCERER_H

#include <iostream>
#include <string>

#include "Victim.hpp"

class Sorcerer
{
public:
	Sorcerer();
	Sorcerer(std::string name, std::string title);
	Sorcerer(const Sorcerer &);
	~Sorcerer();
	Sorcerer &operator=(const Sorcerer &);
	std::string getName() const;
	std::string getTitle() const;
	void polymorph(Victim const &) const;
private:
	std::string _name;
	std::string _title;
};

std::ostream &operator<<(std::ostream &, const Sorcerer &);


#endif // !SORCERER_H