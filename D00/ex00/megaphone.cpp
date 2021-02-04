/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:20:02 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/03 19:24:28 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	*upper_it(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	return (str);
}

int		main(int ac, char **av)
{
	int i;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 0;
		while (++i < ac)
		{
			std::cout << upper_it(av[i]);
			if (i + 1 != ac)
				std::cout << ' ';
		}
	}
	std::cout << std::endl;
	return (0);
}