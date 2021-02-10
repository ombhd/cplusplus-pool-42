/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:04:23 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/08 18:49:44 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_H
#define SUPERTRAP_H

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
	SuperTrap();
	SuperTrap(std::string name);
	SuperTrap(const SuperTrap &);
	SuperTrap &operator=(const SuperTrap &);
	~SuperTrap();
// Attacks
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
private:
	void			init(void);
};

#endif // !SUPERTRAP_H