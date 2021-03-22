/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:38:29 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/22 17:03:39 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request", 72, 45, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & fr) : Form(fr)
{
	*this = fr;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm & fr)
{
	this->Form::operator=(fr);
	return *this;
}

void	RobotomyRequestForm::action() const 
{
	std::cout << "⛏⛏⛏✨⛏🔧⛏⛏✨⛏🔧⛏⛏⛏✨⛏🔧⛏⛏✨⛏⛏" << std::endl;
	std::cout << "⛏🔧✨⛏🔧⛏⛏✨⛏🔧⛏⛏🔧✨⛏🔧⛏⛏✨⛏🔧⛏" << std::endl;
	std::cout << "⛏⛏⛏⛏✨⛏🔧⛏✨⛏🔧⛏⛏✨⛏🔧⛏⛏✨⛏🔧⛏" << std::endl;
	if (rand() % 1000 + 1 % 2)
		std::cout << this->getTarget() << " has been robotomized successfully 50% of the time." << std::endl;
	else
		std::cout << "Failed to robotomize " << this->getTarget() << std::endl;
}