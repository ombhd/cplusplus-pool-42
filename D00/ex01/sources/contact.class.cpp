/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:48:48 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/30 17:58:48 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/contact.class.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::getFirstName(void)
{
	return firstName;
}

void		Contact::setFirstName(std::string firstName)	
{
	this->firstName = firstName;
}

std::string	Contact::getLastName(void)	
{
	return lastName;
}

void		Contact::setLastName(std::string lastName)	
{
	this->lastName = lastName;
}

std::string	Contact::getNickname(void)	
{
	return nickname;
}

void		Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

std::string	Contact::getLogin(void)	
{
	return login;
}

void		Contact::setLogin(std::string login)	
{
	this->login = login;
}

std::string	Contact::getPostalAdress(void)	
{
	return postalAddress;
}

void		Contact::setPostalAdress(std::string postalAddress)	
{
	this->postalAddress = postalAddress;
}

std::string	Contact::getEmailAdress(void)	
{
	return emailAddress;
}

void		Contact::setEmailAdress(std::string emailAddress)	
{
	this->emailAddress = emailAddress;
}

std::string	Contact::getPhoneNumber(void)	
{
	return phoneNumber;
}

void		Contact::setPhoneNumber(std::string phoneNumber)	
{
	this->phoneNumber = phoneNumber;
}

std::tm		Contact::getBirthdayDate(void)	
{
	return birthdayDate;
}

void		Contact::setBirthdayDate(std::tm birthdayDate)	
{
	this->birthdayDate = birthdayDate;
}

std::string	Contact::getFavMeal(void)	
{
	return favMeal;
}

void		Contact::setFavMeal(std::string favMeal)	
{
	this->favMeal = favMeal;
}

std::string	Contact::getUnderwearColor(void)	
{
	return underwearColor;
}

void		Contact::setUnderwearColor(std::string underwearColor)	
{
	this->underwearColor = underwearColor;
}

std::string	Contact::getDarkestSecret(void)	
{
	return darkestSecret;
}

void		Contact::setDarkestSecret(std::string darkestSecret)	
{
	this->darkestSecret = darkestSecret;
}
