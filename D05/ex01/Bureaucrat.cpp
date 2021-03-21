/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:39:13 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/21 18:28:11 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
_name("default"),
_grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade):
_name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & br):
_name(br._name)
{
	*this = br;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Burecrat " << this->getName() << " died" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat & br)
{
	if (this != &br)
		this->_grade = br._grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int			Bureaucrat::getGrade() const
{
	return _grade;
}

void		Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	else
		--this->_grade;
}

void		Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	else
		++this->_grade;
}

void			Bureaucrat::signForm(Form &fr)
{
	try {
		fr.beSigned(*this);
		std::cout << this->_name << " has signed " << fr.getName() << " form successfully" << std::endl;
	} catch (std::exception &e)
	{
		std::cout << this->_name << " can NOT sign " << fr.getName() << " form because its " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &br)
{
	out << br.getName() << ", bureaucrat grade " << br.getGrade() << std::endl;
	return out;
}

