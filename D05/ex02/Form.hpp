/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:03:04 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/22 16:54:56 by obouykou         ###   ########.fr       */
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
	Form(std::string, int, int, std::string);
	Form(const Form &);
	Form &operator=(const Form &);
	virtual ~Form();
	std::string 	getName() const;
	int				getSignGrade() const;
	int				getExecGrade() const;
	std::string		getTarget() const;
	bool			_isFormSigned() const;
	void			beSigned(const Bureaucrat);
	void			execute(Bureaucrat const & executor) const;
	virtual void 	action() const = 0;

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

	class UnsignedFormException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

private:
	const	std::string	_name;
	std::string			_target;
	const int			_signGrade;
	const int			_execGrade;
	bool				_isSigned;
	 
};

std::ostream &operator<<(std::ostream &, const Form &);

#endif // !FORM_H