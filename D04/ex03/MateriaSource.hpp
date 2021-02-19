/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:07:29 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/19 12:28:19 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_H
#define MATERIA_SOURCE_H

#include "IMateriaSource.hpp"

#define  MAX_INV 4 

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &);
		MateriaSource &operator=(const MateriaSource &);
		~MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
	
	private:
		AMateria	*_materiaInventory[MAX_INV];
		int			_numberOfMateria;
		void		_initInventory();
		void		_destroyInventory();
};

#endif // !MATERIA_SOURCE_H