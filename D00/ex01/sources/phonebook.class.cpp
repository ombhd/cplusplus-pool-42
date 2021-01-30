/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:24:23 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/30 19:20:48 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.class.hpp"

PhoneBook::PhoneBook(void)
{
	this->noc = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void		PhoneBook::add_contact(void)
{
	std::string tmp;
	std::tm date;

	std::cout << "\n-------------- Adding a contact ---------------\n" << std::endl;
	if (noc == 8)
	{
		std::cout << "You already reached the limits of your PhoneBook [max = 8 Contacts]" << std::endl;
		std::cout << "You Can type EXIT to start a new fresh PhoneBook, but you'll lose the current PhoneBook :(" << std::endl;
		return ;
	}
	std::getline(std::cin, tmp);
	std::cout << "First Name      : ";
	std::getline(std::cin, tmp);
	contacts[noc].setFirstName(tmp);
	std::cout << "Last Name       : ";
	std::getline(std::cin, tmp);
	contacts[noc].setLastName(tmp);
	std::cout << "Nickname        : ";
	std::getline(std::cin, tmp);
	contacts[noc].setNickname(tmp);
	std::cout << "Login           : ";
	std::getline(std::cin, tmp);
	contacts[noc].setLogin(tmp);
	std::cout << "Postal Adress   : ";
	std::getline(std::cin, tmp);
	contacts[noc].setPostalAdress(tmp);
	std::cout << "Email Adress    : ";
	std::getline(std::cin, tmp);
	contacts[noc].setEmailAdress(tmp);
	std::cout << "Phone Number    : ";
	std::getline(std::cin, tmp);
	contacts[noc].setPhoneNumber(tmp);
	do
	{
		std::cout << "Birthday Date [day-month-year] (Numbers ONLY) : ";
		if (!(std::cin >> std::get_time(&date,"%d-%m-%Y")))
		{
			std::cout << "Error reading date, Please provide a valid date in this form [day-month-year]" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
		else
			break ;
	} while (1);
	contacts[noc].setBirthdayDate(date);
	std::getline(std::cin, tmp);
	std::cout << "Favourite Meal  : ";
	std::getline(std::cin, tmp);
	contacts[noc].setFavMeal(tmp);
	std::cout << "Underwear Color : ";
	std::getline(std::cin, tmp);
	contacts[noc].setUnderwearColor(tmp);
	std::cout << "Darkest Secret  : ";
	std::getline(std::cin, tmp);
	contacts[noc].setDarkestSecret(tmp);
	noc++;
	std::cout << std::endl << "---------------------------------------" << std::endl;
	std::cout << "-- Contact has been added succefully --" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}

void		PhoneBook::print_column(std::string str)
{
	std::cout << "|";
	std::cout << std::setw(10);
	if (str.length() > 10)
	{
		std::cout << std::setw(9);
		std::cout << str.substr(0, 9) << ".";
	}
	else
		std::cout << str;
}

int			PhoneBook::get_index()
{
	int i;
	
	do
	{
		std::cout << "To get full infos, Type an index from the list above: ";
		std::cin >> i;
		if (i < 0 || i > noc)
			std::cout << "Invalid index" << std::endl;
	} while (i < 0 || i > noc);
	return (i);
}

void		PhoneBook::print_contact(Contact ct)
{
	std::tm date;

	std::cout << std::endl << "------------------------------------------------------" << std::endl;
	std::cout << "\tFirst Name      : " << ct.getFirstName() << std::endl;
	std::cout << std::endl << "\tLast Name       : " << ct.getLastName() << std::endl;
	std::cout << std::endl << "\tNickname        : " << ct.getNickname() << std::endl;
	std::cout << std::endl << "\tLogin           : " << ct.getLogin() << std::endl;
	std::cout << std::endl << "\tPostal Adress   : " << ct.getPostalAdress() << std::endl;
	std::cout << std::endl << "\tEmail Adress    : " << ct.getEmailAdress() << std::endl;
	std::cout << std::endl << "\tPhone Number    : " << ct.getPhoneNumber() << std::endl;
	date = ct.getBirthdayDate();
	std::cout << std::endl << "\tBirthday Date   : " << std::put_time(&date, "%d - %m - %Y") << std::endl;
	std::cout << std::endl << "\tFavourite Meal  : " << ct.getFavMeal() << std::endl;
	std::cout << std::endl << "\tUnderwear Color : " << ct.getUnderwearColor() << std::endl;
	std::cout << std::endl << "\tDarkest Secret  : " << ct.getDarkestSecret();
	std::cout << std::endl << "------------------------------------------------------\n\n";
}

void		PhoneBook::search_contact()
{
	Contact ct;
	int		i;

	std::cout << std::endl << std::endl;
	std::cout << "            ------ PhoneBook ------          " << std::endl;
	std::cout << "  ___________________________________________" << std::endl;
	std::cout << " |          |          |          |          |" << std::endl;
	std::cout << " |   index  |first name| last name| nickname |" << std::endl;
	std::cout << " |----------|----------|----------|----------|" << std::endl;
	if (!noc)
	{
		std::cout << " |                                           |" << std::endl;
		std::cout << " |              Empty PhoneBook              |" << std::endl;
		std::cout << " |___________________________________________|" << std::endl;
		return ;
	}
	for(i = 0; i < noc; i++)
	{
		ct = contacts[i];
		std::cout << " |";
		std::cout << std::setw(10);
		std::cout << i;
		print_column(ct.getFirstName());
		print_column(ct.getLastName());
		print_column(ct.getNickname());
		std::cout << "|" << std::endl;
		if (i < noc - 1)
			std::cout << " |----------|----------|----------|----------|" << std::endl;
	}
	std::cout << " |__________|__________|__________|__________|" << std::endl << std::endl;
	i = get_index();
	PhoneBook::print_contact(contacts[i]);
}
