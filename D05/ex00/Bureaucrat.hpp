/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:36:26 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/20 12:29:53 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string, int);
	Bureaucrat(const Bureaucrat &);
	Bureaucrat &operator=(const Bureaucrat &);
	~Bureaucrat();
	std::string 	getName() const;
	int				getGrade() const;
	void			incrementGrade();
	void			decrementGrade();

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
	int					_grade;
	 
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif // !BUREAUCRAT_H