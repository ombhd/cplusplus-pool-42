/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:08:28 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/22 17:25:51 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

static void test(Bureaucrat & bur, Form & form)
{
    std::cout << std::endl << "Sign & Execute \033[33m" << form.getName() << "\033[0m : " << std::endl;
    bur.signForm(form);
    bur.executeForm(form);
}

int main()
{
    Bureaucrat max("Max", 50);
    Bureaucrat henery("Henery", 1);
    Bureaucrat bob("Bob", 120);

    ShrubberyCreationForm shrub(max.getName());
    PresidentialPardonForm pardon(henery.getName());
    RobotomyRequestForm robot(bob.getName());

    std::cout << "\033[31mNormal\033[0m tests : " << std::endl;

    test(max, robot);
    test(henery, shrub);
    test(bob, pardon);

    std::cout << std::endl << "\033[31mAlreadySigned & ToLow\033[0m tests : " << std::endl;

    test(bob, pardon);

    return (0);
}

