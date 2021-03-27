/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:52:31 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/27 18:40:15 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "whatever.hpp"


int main( void ) 
{
	std::cout << " \n\033[33mINT\033[0m " << std::endl << std::endl;
	{
		int a = 2;
		int b = 3;

		std::cout << "Before swap: a = " << a << " , b = " << b << std::endl;
		::swap( a, b );
		std::cout << "After swap:  a = " << a << " , b = " << b << std::endl;
		
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	
	std::cout << " \n\033[33mSTRING\033[0m " << std::endl << std::endl;
	{
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "Before swap: c = " << c << " , d = " << d << std::endl;
		
		::swap(c, d);
		std::cout << "After swap:  c = " << c << " , d = " << d << std::endl;
		
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	
	std::cout << " \n\033[33mFLOAT\033[0m " << std::endl << std::endl;
	{
		float a = 13.37;
		float b = 42.01;
		std::cout << "Before swap: a = " << a << " , b = " << b << std::endl;

		::swap( a, b );
		std::cout << "After swap:  a = " << a << " , b = " << b << std::endl;
		
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}

	std::cout << " \n\033[33mCHARACTER\033[0m " << std::endl << std::endl;
	{
		char a = 'a';
		char b = 'b';
		std::cout << "Before swap: a = '" << a << "' , b = '" << b << "'" << std::endl;

		::swap( a, b );
		std::cout << "After swap:  a = '" << a << "' , b = '" << b << "'" << std::endl;
		
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}

	return 0;
}