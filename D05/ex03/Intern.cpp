/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:39:13 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/23 11:45:13 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern & br)
{
	*this = br;
}

Intern::~Intern()
{
}

Intern	&Intern::operator=(const Intern & br)
{
	(void)br;
	return *this;
}

Form	*Intern::makeForm(const std::string formName, const std::string target)
{
	std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	size_t i;
	for (i = 0; i < 3; i++)
		if (formName == forms[i])
			break ;
	if (i < 3)
		std::cout << "Intern creates " << formName << " form." << std::endl;
	switch (i)
	{
		case 0:
			return new RobotomyRequestForm(target);
		case 1:
			return new PresidentialPardonForm(target);
		case 2:
			return new ShrubberyCreationForm(target);
		default:
			std::cout << "⛔ invalid form name" << std::endl;
			return NULL;
	}
}