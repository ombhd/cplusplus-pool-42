/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:10:35 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/30 17:54:32 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <iterator>

#include "span.hpp"

template <typename T>
void    print(std::vector<T> &vec)
{
    std::cout << "size: " << vec.size() << std::endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << "vec[" << i << "] = " << vec.at(i) << std::endl;
    }
}

void    printSpans(Span &sp)
{
    // print(sp._array);
    std::cout << "====> Shortest span : " << sp.shortestSpan() << std::endl;
    // print(sp._array);
    std::cout << "====================> Longest span : " << sp.longestSpan() << std::endl;
}

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
        std::cerr << "Error : " << e.what() <<  std::endl <<  std::endl;
    }
    
    Span sp_short = Span(5);
    sp_short.addNumber(5);
    sp_short.addNumber(3);
    sp_short.addNumber(17);
    sp_short.addNumber(-85);
    sp_short.addNumber(11);
    try {
        sp_short.addNumber(11);
    } catch (std::exception &e) {
        std::cout << "error : " << e.what() << std::endl;
    }
    std::cout << "sp short hard" << std::endl;
    printSpans(sp_short);


    Span sp_short_hard = Span(2);
    sp_short_hard.addNumber(2147483647);
    sp_short_hard.addNumber(-2147483648);
    
    std::cout << "sp short hard" << std::endl;
    printSpans(sp_short_hard);


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

    try
    {
        std::cout << sp_empty.longestSpan() << std::endl;
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

    std::cout << "\n\n======================================================\n" << std::endl;

    Span sp_long_long = Span(50000);
    std::vector<int> range(50000, 10);
    range[300] = 40;
    range[40004] = 400;
    // print(range);
    
    try 
    {
        sp_long_long.addNumber(range.begin(), range.end());
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try
    {
        printSpans(sp_long_long);
    }
        catch(const std::exception& e)
    {
        std::cerr << "Error : " << e.what() <<  std::endl;
    }

}