/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sed.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:32:06 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/01 19:14:29 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>


int 		main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error : [USAGE]==> { ./MySed  file_name  old_term  term_to_replace_old_term }" << std::endl;
		return (1);
	}

	std::ifstream origFile (av[1], std::ios::in);
	if (!origFile.is_open())
	{
		std::cout << "Can't open the file " << av[1] << std::endl;
		return (1);
	}
	
	std::string repFileName = av[1];   
	repFileName += ".replace";
	std::ofstream repFile (repFileName, std::ios::out);
	if (!repFile.is_open())
	{
		std::cout << "Can't Create the replacement file " << repFileName << std::endl;
		return (1);
	}
	
	std::string buff;   
	std::string oldWord = av[2];
	std::string newWord = av[3];
	size_t i;
	size_t oldWordLen = oldWord.length();
	size_t newWordLen = newWord.length();

	while (std::getline(origFile, buff))
	{	
		i = 0;
		while ((i = buff.find(oldWord, i)) != std::string::npos)
		{
			buff.replace(i, oldWordLen, newWord);
			i += newWordLen;
		}
		repFile << buff << std::endl;
	}
	
	origFile.close();
	repFile.close();
	
	return 0;    
}