/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:10:35 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/29 17:05:27 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <iterator>

#include "span.hpp"

int main()
{
    // FULL SPAN
    Span sp_full = Span(2);

    sp_full.addNumber(5);
    sp_full.addNumber(8);
    
    try
    {
        sp_full.addNumber(9);     
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error : " << e.what() <<  std::endl;
    }
    
    Span sp_short = Span(5);
    sp_short.addNumber(5);
    sp_short.addNumber(3);
    sp_short.addNumber(17);
    sp_short.addNumber(-8925);
    sp_short.addNumber(11);

    std::cout << sp_short.shortestSpan() << std::endl;

    Span sp_short_hard = Span(2);
    sp_short_hard.addNumber(2147483647);
    sp_short_hard.addNumber(-2147483648);

    std::cout << sp_short_hard.shortestSpan() << std::endl;

    Span sp_empty = Span(80);
    
    try
    {
        std::cout << sp_empty.shortestSpan() << std::endl;
    }
        catch(const std::exception& e)
    {
        std::cerr << "Error : " << e.what() <<  std::endl;
    }

    sp_empty.addNumber(5);

    try
    {
        std::cout << sp_empty.shortestSpan() << std::endl;
    }
        catch(const std::exception& e)
    {
        std::cerr << "Error : " << e.what() <<  std::endl;
    }

    Span sp_long = Span(4);
    sp_long.addNumber(8);
    sp_long.addNumber(-3);
    sp_long.addNumber(80);
    sp_long.addNumber(-8);

    try
    {
        std::cout << sp_long.longestSpan() << std::endl;
    }
        catch(const std::exception& e)
    {
        std::cerr << "Error : " << e.what() <<  std::endl;
    }

    Span sp_long_hard = Span(4);
    sp_long_hard.addNumber(2147483647);
    sp_long_hard.addNumber(-2147483648);

    try
    {
        std::cout << sp_long_hard.longestSpan() << std::endl;
    }
        catch(const std::exception& e)
    {
        std::cerr << "Error : " << e.what() <<  std::endl;
    }

    try
    {
        std::cout << sp_empty.longestSpan() << std::endl;
    }
        catch(const std::exception& e)
    {
        std::cerr << "Error : " << e.what() <<  std::endl;
    }

    Span sp_long_long = Span(50000);
    std::vector<int> range(50000, 10);
    range[3256] = 40;
    range[6554] = 400;
    sp_long_long.addNumber(range.begin(), range.end());

    try
    {
        std::cout << sp_long_long.longestSpan() << std::endl;
    }
        catch(const std::exception& e)
    {
        std::cerr << "Error : " << e.what() <<  std::endl;
    }

    try
    {
        std::cout << sp_long_long.shortestSpan() << std::endl;
    }
        catch(const std::exception& e)
    {
        std::cerr << "Error : " << e.what() <<  std::endl;
    }
}