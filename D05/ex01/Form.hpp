/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:03:04 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/20 18:33:53 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form();
	Form(std::string, int, int);
	Form(const Form &);
	Form &operator=(const Form &);
	~Form();
	std::string 	getName() const;
	int				getSignGrade() const;
	int				getExecGrade() const;
	bool			_isFormSigned() const;
	void			beSigned(const Bureaucrat);

	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

private:
	const	std::string	_name;
	const int			_signGrade;
	const int			_execGrade;
	bool				_isSigned;
	 
};

std::ostream &operator<<(std::ostream &, const Form &);

#endif // !FORM_H