/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:31:12 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/25 19:34:27 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "includes/Conv.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "The program supports one and only one non-empty parameter" << std::endl;
		return -1;
	}
	try {
		Conv conv(argv[1]);
		conv.present();
	} catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
