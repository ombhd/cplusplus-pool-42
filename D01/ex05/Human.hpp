/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:35:47 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/03 18:08:12 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_H
#define HUMAN_H

#include "Brain.hpp"

class Human
{
private:
	const Brain brain;

public:
	Human(void);
	~Human(void);
	const Brain	&getBrain(void);
	std::string identify(void);
};


#endif // !HUMAN_H