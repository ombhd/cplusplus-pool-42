/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:31:12 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/26 18:47:29 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

struct Data
{
	std::string	*strPtr0;
	int			*intPtr;
	std::string	*strPtr1;
};


std::string	genRandomString(const int len)
{
    std::string randomString;
    const char randomCharArr[] = "QWERTYUIOPASDFGHJKLZXCVBNMabcdefghijklmnopqrstuvwxyz123456789~!@#$%^&*()__+-=`}{:?><.,/';][";
    
    randomString.reserve(len);
    for (int i = 0; i < len; ++i)
	{
        randomString += randomCharArr[rand() % (sizeof(randomCharArr) - 1)];
	}
	return randomString;
}

void * serialize(void)
{
	Data;
	std::string str0 = genRandomString(13);
	std::string	*strPtr0 = &str0;
	int			*i = new int(rand() % 13371337);
	std::string str1 = genRandomString(37);
	std::string	*strPtr1 = &str1;

	void *ret = strPtr0;
	return ret;
}

Data * deserialize(void *raw)
{
	
}

int main()
{
	Data data;
	srand(time(NULL));
	return 0;
}
