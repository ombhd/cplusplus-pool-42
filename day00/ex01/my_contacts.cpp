/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_contacts.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:20:02 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/09 18:46:46 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_contacts.hpp"

int		main(int ac, char **av)
{
	contacts	cts;
	std::string	cmd;

	std::cout << "============ Welcome to My Contacts Program ============" << std::endl;
	std::cout << "noc =|" << cts.noc << "| i =|" << cts.i << "| first_name[0]=|" << cts.contacts[0].first_name << std::endl;
	get_command(cmd);
	while (true)
	{
		if (cmd == "ADD" || cmd == "add")
			add_contact(cts);
		if (cmd == "SEARCH" || cmd == "search")
			search_contact(cts);
		if (cmd == "EXIT" || cmd == "exit")
			break ;
	}
	return (0);
}