/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:11:43 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/18 18:56:02 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &);
		Cure &operator=(const Cure &);
		virtual ~Cure();
		virtual Cure* clone() const = 0;
		virtual void use(ICharacter& target);

};

#endif // !CURE_H