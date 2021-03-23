/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:38:29 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/23 09:55:53 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation", 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & fr) : Form(fr)
{
	*this = fr;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm & fr)
{
	this->Form::operator=(fr);
	return *this;
}

void	ShrubberyCreationForm::action() const
{
	std::ofstream myfile((this->getTarget() + "_shrubbery"), std::ios::out);
	if (!myfile.is_open())
	{
		throw std::runtime_error("Could not create/open target file < " + this->getTarget() + "_shrubbery >");
	}
	myfile << std::endl;
	myfile << "              ,@@@@@@@," << std::endl;
	myfile << "      ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	myfile << "   ,&\\%\\%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	myfile << "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	myfile << "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	myfile << "  %&&%/ %&\\%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	myfile << "  `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	myfile << "      |o|        | |         | |" << std::endl;
	myfile << "      |.|        | |         | |" << std::endl;
	myfile << "___ \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	myfile << "---   -------- --------  --------  -----" << std::endl;
	myfile << "-  -----    ------ ----  ----- ------" << std::endl;
	myfile.close();
}
