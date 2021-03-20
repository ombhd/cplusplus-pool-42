/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:38:54 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/20 12:58:58 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{	
	std::cout << "First part" << std::endl;
	try {
		Bureaucrat max("Max", 120);
		Bureaucrat henery("Henery", 1);
		std::cout << max;
		max.decrementGrade(); 
		std::cout << "After decremeting " << max.getName() << "'s grade" << std::endl;
		std::cout << max; 
		henery.incrementGrade(); 
		std::cout << henery;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\nSecond part" << std::endl;
	try {
		Bureaucrat max("Max", 150);
		std::cout << max;
		max.decrementGrade(); 
		std::cout << max; 
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\nThird part" << std::endl;
	try {
		Bureaucrat max("Max", 151);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\nFourth part" << std::endl;
	try {
		Bureaucrat max("Max", -96);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
}