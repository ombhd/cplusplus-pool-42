/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:51:08 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/09 18:33:40 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_CONTACTS_H
# define MY_CONTACTS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

#include "contact.hpp"

class		contacts
{
public:
	Contact		contacts[8];
	int 		noc;

	void		add_contact(Contact &cts);
	void		search_contact(Contact &cts);
};

#endif // !MY_CONTACTS_H