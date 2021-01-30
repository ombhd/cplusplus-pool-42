/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:48:42 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/29 11:09:50 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <string>

class Contact
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string login;
	std::string postalAddress;
	std::string emailAddress;
	std::string phoneNumber;
	std::tm		birthdayDate;
	std::string favMeal;
	std::string underwearColor;
	std::string darkestSecret;

public:
	
	Contact(void);
	~Contact(void);
	std::string	getFirstName();
	void		setFirstName(std::string);
	std::string	getLastName();
	void		setLastName(std::string);
	std::string	getNickname();
	void		setNickname(std::string);
	std::string	getLogin();
	void		setLogin(std::string);
	std::string	getPostalAdress();
	void		setPostalAdress(std::string);
	std::string	getEmailAdress();
	void		setEmailAdress(std::string);
	std::string	getPhoneNumber();
	void		setPhoneNumber(std::string);
	std::tm		getBirthdayDate();
	void		setBirthdayDate(std::tm);
	std::string	getFavMeal();
	void		setFavMeal(std::string);
	std::string	getUnderwearColor();
	void		setUnderwearColor(std::string);
	std::string	getDarkestSecret();
	void		setDarkestSecret(std::string);
	

};

#endif // !CONTACT_CLASS_HPP
