/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:24:23 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/29 12:55:08 by obouykou         ###   ########.fr       */
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

void		PhoneBook::add_contact(Contact &cts)
{
	std::string tmp;
	std::tm date;

	if (noc == 8)
	{
		std::cout << "You already reached the limits of your PhoneBook [max = 8 Contacts]" << std::endl;
		std::cout << "You Can type EXIT to start a new fresh PhoneBook, but you'll lose the current PhoneBook :(" << std::endl;
		return ;
	}
	std::cout << "First Name : ";
	std::cin >> tmp;
	contacts[noc].setFirstName(tmp);
	std::cout << "Last Name : ";
	std::cin >> tmp;
	contacts[noc].setLastName(tmp);
	std::cout << "Nickname : ";
	std::cin >> tmp;
	contacts[noc].setNickname(tmp);
	std::cout << "Login : ";
	std::cin >> tmp;
	contacts[noc].setLogin(tmp);
	std::cout << "Postal Adress : ";
	std::cin >> tmp;
	contacts[noc].setPostalAdress(tmp);
	std::cout << "Email Adress : ";
	std::cin >> tmp;
	contacts[noc].setEmailAdress(tmp);
	std::cout << "Phone Number : ";
	std::cin >> tmp;
	contacts[noc].setPhoneNumber(tmp);
	std::cout << "Birthday Date : "; // HOW TO CIN std::tm
	// std::cin >> date;
	contacts[noc].setBirthdayDate(date);
	std::cout << "Favourite Meal : ";
	std::cin >> tmp;
	contacts[noc].setFavMeal(tmp);
	std::cout << "Underwear Color : ";
	std::cin >> tmp;
	contacts[noc].setUnderwearColor(tmp);
	std::cout << "Darkest Secret : ";
	std::cin >> tmp;
	contacts[noc].setDarkestSecret(tmp);
	noc++;
}

void		PhoneBook::search_contact(Contact &cts)
{
	
}
