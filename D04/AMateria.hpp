/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:11:43 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/18 18:25:38 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>

#include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &);
		AMateria &operator=(const AMateria &);
		virtual ~AMateria();
		std::string const & getType() const;
		unsigned int getXP() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	private:
		unsigned int	_xp;
		std::string		_type;
};

#endif // !AMATERIA_H