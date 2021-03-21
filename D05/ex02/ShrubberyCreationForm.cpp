/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:38:29 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/21 19:35:43 by obouykou         ###   ########.fr       */
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

void	ShrubberyCreationForm::execute()
{
	std::ofstream myfile((this->getTarget() + "_shrubbery"), std::ios::out);
	if (!myfile.is_open())
	{
		std::cout << "Can't Create the target file" << std::endl;
		return ;
	}
	myfile << "	             ,@@@@@@@,";
	myfile << "      ,,,.   ,@@@@@@/@@,  .oo8888o.";
	myfile << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o";
	myfile << "  ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'";
	myfile << "  %&&%&%&/%&&%@@\@@/ /@@@88888\88888'";
	myfile << "  %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'";
	myfile << "  `&%\ ` /%&'    |.|        \ '|8'";
	myfile << "      |o|        | |         | |";
	myfile << "      |.|        | |         | |";
	myfile << "___ \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_";
	myfile << "";
	myfile << "------------------------------------------------";
	myfile.close();
}