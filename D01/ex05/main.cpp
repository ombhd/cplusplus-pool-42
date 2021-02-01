/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:16:09 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/01 12:57:51 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main()
{
	Human lmahjoub;
	Human l3arbi;

	std::cout << lmahjoub.identify() << std::endl;
	std::cout << lmahjoub.getBrain().identify() << std::endl;
	
	std::cout << l3arbi.identify() << std::endl;
	std::cout << l3arbi.getBrain().identify() << std::endl;
	
	return (0);
}