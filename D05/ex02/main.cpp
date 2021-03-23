/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:08:28 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/23 10:19:41 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

static void test(Bureaucrat & bur, Form & form)
{
    std::cout << "\n\033[33m" << form.getName() << "\033[0m form: " << std::endl;
    std::cout << "Signing by " << bur.getName() << std::endl;
    bur.signForm(form);
    std::cout << "Executing by " << bur.getName() << std::endl;
    bur.executeForm(form);
}

int main()
{
    Bureaucrat max("Max", 30);
    Bureaucrat henery("Henery", 1);
    Bureaucrat bob("Bob", 45);

    ShrubberyCreationForm shrub(max.getName());
    PresidentialPardonForm pardon(henery.getName());
    RobotomyRequestForm robot(bob.getName());

    std::cout << "\033[34mNormal\033[0m tests : " << std::endl;

    test(max, robot);
    test(henery, shrub);
    test(bob, pardon);

    std::cout << std::endl << "\033[34mAlreadySigned & ToLow\033[0m tests : " << std::endl;

    bob.decrementGrade();
    test(bob, robot);
    max = Bureaucrat("Bob", 100);
    test(max, pardon);

    return (0);
}

