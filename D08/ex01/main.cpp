/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:10:35 by obouykou          #+#    #+#             */
/*   Updated: 2021/03/30 19:01:14 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <iterator>

#include "span.hpp"

// template <typename T>
// void    print(std::vector<T> &vec)
// {
//     std::cout << "size: " << vec.size() << std::endl;
//     for (size_t i = 0; i < vec.size(); i++)
//     {
//         std::cout << "vec[" << i << "] = " << vec.at(i) << "  |  ";
//     }
//     std::cout << std::endl;
// }

void    printSpans(Span &sp)
{
    long int res;
    // trying shortestSpan
    try
    {
        res = sp.shortestSpan();
        std::cout << "=========> Shortest span : " << res << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ShortestSpan() ==> Error : " << e.what() <<  std::endl;
    }
    
    // trying longestSpan
    try
    {
        res = sp.longestSpan();
        std::cout << "=========> Longest span  : " << res << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "LongestSpan()  ==> Error : " << e.what() <<  std::endl;
    }
}

int main()
{
    // FULL SPAN
    {   
        Span sp_full = Span(2);
        sp_full.addNumber(5);
        sp_full.addNumber(8);
        try
        {
            std::cout << "\033[33mTEST FULL SPAN\033[0m" << std::endl;
            sp_full.addNumber(9);  
        }
        catch(const std::exception& e)
        {
            std::cerr << "==> Error : " << e.what() <<  std::endl;
        }
    }

    // shortest and longest span
    {
        std::cout << "\n\033[33mTEST LONGEST/SHORTEST SPAN WITH NORMAL SPAN\033[0m" << std::endl;
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(-85);
        sp.addNumber(11);
        
        printSpans(sp);
    }

    // 2 values span
    {
        std::cout << "\n\033[33mTEST LONGEST/SHORTEST SPAN WITH 2 VALUES SPAN\033[0m" << std::endl;
 
        Span shortSpan = Span(2);
        
        shortSpan.addNumber(2147483647);
        shortSpan.addNumber(-2147483648);
        
        printSpans(shortSpan);
    }

    // (Empty / only one value) Span
    {
        std::cout << "\n\033[33mTEST LONGEST/SHORTEST SPAN WITH EMPTY SPAN\033[0m" << std::endl;
        Span emptySpan = Span(80);
        printSpans(emptySpan);
        
        std::cout << "\n\033[33mTEST LONGEST/SHORTEST SPAN WITH ONLY ONE VALUE SPAN\033[0m" << std::endl;
        emptySpan.addNumber(13);
        printSpans(emptySpan);
    }

    // Negative and positive numbers
    {
        std::cout << "\n\033[33mTEST LONGEST/SHORTEST SPAN WITH NEGATIVE/POSITIVE NUMBERS SPAN\033[0m" << std::endl;
        Span sp = Span(4);
        sp.addNumber(8);
        sp.addNumber(-3);
        sp.addNumber(80);
        sp.addNumber(-8);
        
        printSpans(sp);
    }

    // Span filled with range of iterators
    {
        std::cout << "\n\033[33mTEST LONGEST/SHORTEST SPAN WITH RANGE FILLED SPAN\033[0m" << std::endl;

        std::vector<int> range(50000, 10);
        range[1337] = 70;
        
        Span maxSpan = Span(50000);
        maxSpan.addNumber(range.begin(), range.end());
        printSpans(maxSpan);
    }
    
    return 0;
}