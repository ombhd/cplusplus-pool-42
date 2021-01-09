/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:57:18 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/09 18:14:16 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_contacts.hpp"

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
		std::cout << "Type a command : \n◊ [ ADD ]\n◊ [ SEARCH ]\n◊ [ EXIT ]" << std::endl;
		std::cout << "========>> ";
		std::cin >> cmd;
		if (!(b = is_cmd_valid(cmd)))
			std::cout << "Please, type a valid command!" << std::endl;
	}
	while (!b);
}