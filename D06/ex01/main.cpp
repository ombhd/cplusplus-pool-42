/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:31:12 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/27 14:22:05 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

struct Data
{
	std::string	*strPtr0;
	int			i;
	std::string	*strPtr1;
};


std::string	genRandomString(const int len)
{
    std::string randomString;
    const char randomCharArr[] = "QWERTYUIOPASDFGHJKLZXCVBNMabcdefghijklmnopqrstuvwxyz123456789";
    
    randomString.reserve(len);
    for (int i = 0; i < len; ++i)
	{
        randomString += randomCharArr[rand() % (sizeof(randomCharArr) - 1)];
	}
	return randomString;
}

void	outputData(Data *data)
{
	std::cout << "first string  : |" << *data->strPtr0 << "|" << std::endl;
	std::cout << "int           : |" << data->i << "|" << std::endl;
	std::cout << "second string : |" << *data->strPtr1 << "|" << std::endl;
}

void	*serialize(void)
{
	std::cout << " \n\033[33mSerializing\033[0m ===========> ";
	
	Data *data = new Data;
	
	data->strPtr0 = new std::string;
	*data->strPtr0 = genRandomString(13);
	
	data->i = rand() % 13371337;
	
	data->strPtr1 = new std::string;
	*data->strPtr1 = genRandomString(37);
	
	void *ret = static_cast<void *>(data);
	std::cout << "Done" << std::endl << std::endl;

	std::cout << "=====  serialized data  =====" << std::endl;
	outputData(data);
	
	return ret;
}

Data	*deserialize(void *raw)
{
	std::cout << " \n\033[33mDeserializing\033[0m =========> ";
	
	Data *data = reinterpret_cast<Data *>(raw);
	std::cout << "Done" << std::endl << std::endl;
	
	std::cout << "===== Deserialized data =====" << std::endl;
	outputData(data);
	return data;
}



int		main()
{
	Data *data;
	void *raw;

	srand(time(NULL));
	
	raw = serialize();
	data = deserialize(raw);

	delete data->strPtr0;
	delete data->strPtr1;
	delete data;
	// delete reinterpret_cast<Data*>(raw);
	std::cout << std::endl;
	return 0;
}
