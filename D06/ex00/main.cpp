/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:31:12 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/24 12:34:45 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "The program supports one and only one parameter" << std::endl;
		return -1;
	}
	std::string par = argv[1];
	
	return 0;
}
