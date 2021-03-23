/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:08:28 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/23 11:47:05 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


int main()
{

    Intern 	someRandomIntern;
	Bureaucrat bob("Bob", 150);
	Bureaucrat max("Max", 20);
	Form 	*roboto = NULL;

	roboto = someRandomIntern.makeForm("robotomy request", "Bob");
    bob.signForm(*roboto);
    bob.executeForm(*roboto);
    max.signForm(*roboto);
    max.executeForm(*roboto);
    delete roboto;

    roboto = NULL;
	roboto = someRandomIntern.makeForm("invalid form name", "Max");
    delete roboto;
	return 0;
}

