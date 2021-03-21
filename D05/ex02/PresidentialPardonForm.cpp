/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:38:29 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/21 19:21:59 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Robotomy Request", 72, 45, target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & fr) : Form(fr)
{
	*this = fr;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm & fr)
{
	this->Form::operator=(fr);
	return *this;
}

void	PresidentialPardonForm::pardon(const Bureaucrat br)
{
	std::cout << br.getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}