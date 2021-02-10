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

#ifndef NINJATRAP_H
#define NINJATRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
public:
	NinjaTrap();
	NinjaTrap(std::string name);
	NinjaTrap(const NinjaTrap &);
	NinjaTrap &operator=(const NinjaTrap &);
	~NinjaTrap();

// Getters


// Special Attack
	void			ninjaShoebox(ClapTrap &);
	void			ninjaShoebox(FragTrap &);
	void			ninjaShoebox(ScavTrap &);
	void			ninjaShoebox(NinjaTrap &);

private:
	void			init(void);
};

#endif // !NINJATRAP_H