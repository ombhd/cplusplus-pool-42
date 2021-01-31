/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 11:11:18 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/31 11:29:24 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Pony
{
	std::string name;
	int			mainColor;
	int			height;
	
public:
	Pony();
	Pony(std::string);
	~Pony(void);
	void	setName(std::string);
	std::string		getName(void);
	void	setHeight(int);
	int		getHeight(void);
	void	setMainColor(int);
	int		getMainColor(void);
	Pony	*ponyOnTheHeap(void);
	Pony	ponyOnTheStack(void);
};
