/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:37:58 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/19 12:04:22 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"

#define MAX_INV 4

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character &);
		Character &operator=(const Character &);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		
	private:
		std::string	_name;
		AMateria	*_materiaInventory[MAX_INV];
		int			_numberOfMateria;
		void		_initInventory();
		void		_destroyInventory();
};


#endif // CHARACTER_H
