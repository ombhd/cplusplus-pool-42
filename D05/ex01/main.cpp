/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:38:54 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/21 18:26:43 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{

	std::cout << "First part" << std::endl;
	try {
		Bureaucrat max("Max", 60);
		Bureaucrat henery("Henery", 1);
		Form state("state", 12, 10);
		Form college("college", 70, 12);
		henery.signForm(state);
		max.signForm(state);
		max.incrementGrade(); 
		std::cout << "After incremeting " << max.getName() << "'s grade" << std::endl;
		std::cout << max; 
		max.signForm(college);
		henery.decrementGrade(); 
		std::cout << henery;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\nSecond part" << std::endl;
	try {
		Bureaucrat max("Max", 100);
		Form college("college", 70, 12);
		std::cout << max;
		college.beSigned(max);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
}

