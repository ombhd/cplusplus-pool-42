/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_phonebook.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:20:02 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/30 19:02:10 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/phonebook.class.hpp"

bool		is_cmd_valid(std::string cmd)
{
	return (cmd == "ADD" || cmd == "add" || cmd == "SEARCH" ||
			cmd == "search" || cmd == "EXIT" || cmd == "exit");
}

void		get_command(std::string &cmd)
{
	bool	b;

	do
	{
		std::cout << "\n\tType a command : \n\n\t◊ [ ADD ]\n\t◊ [ SEARCH ]\n\t◊ [ EXIT ]" << std::endl;
		std::cout << "\n==========================> ";
		std::cin >> cmd;
		if (!(b = is_cmd_valid(cmd)))
			std::cout << "\nPlease, type a valid command!" << std::endl;
	}
	while (!b);
}

int		main(void)
{
	std::string	cmd;
	PhoneBook my_phonebook;

	while (true)
	{
		std::cout << "\n\n============ MyPhoneBook ============\n";
		get_command(cmd);
		if (cmd == "ADD" || cmd == "add")
			my_phonebook.add_contact();
		else if (cmd == "SEARCH" || cmd == "search")
			my_phonebook.search_contact();
		else if (cmd == "EXIT" || cmd == "exit")
			break ;
	}
	return (0);
}