/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:07:21 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/01 10:14:32 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPtr = &str;
	std::string &strRef = str;

	std::cout << "\nDisplay str using Pointer to it   :|" << *strPtr << "|\n" << std::endl;
	std::cout << "Display str using Reference to it :|" << strRef << "|\n" << std::endl;
	
	return 0;
}