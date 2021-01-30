/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:51:08 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/30 17:28:52 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_PHONEBOOK_CLASS_H
# define MY_PHONEBOOK_CLASS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

#include "contact.class.hpp"

class		PhoneBook
{
	Contact		contacts[8];
	int 		noc;
	
public:

	PhoneBook(void);
	~PhoneBook(void);
	
	void		add_contact(void);
	void		print_column(std::string str);
	void		print_contact(Contact ct);
	int			get_index(void);
	void		search_contact(void);
};

#endif // !MY_PHONEBOOK_CLASS_H