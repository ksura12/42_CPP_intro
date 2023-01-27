/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:09:08 by ksura             #+#    #+#             */
/*   Updated: 2023/01/27 11:32:34 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Span.hpp"
#include "../header/colors.h"

static void	try_catch_ls(Span const & obj, unsigned int (Span::*f)(void) const);
static void	try_catch_ss(Span const & obj, unsigned int (Span::*f)(void) const);
static void	try_catch_number(Span & obj, int number);

int main(void)
{
    {   
        std::cout << GREEN << "---TEST 1: ADD SINGLE NUMBERS--- " << COLOR_DEFAULT << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        std::cout << std::endl;
        std::cout << GREEN << "---TEST 2: SPAN OBJECT[1] WITH ONLY ONE ELEMENT--- " << COLOR_DEFAULT << std::endl;
        Span sp = Span(1);
        sp.addNumber(1499);
        std::cout << GREEN << "Trying to get the longest and shortes span " << COLOR_DEFAULT << std::endl;
        try_catch_ss(sp, &Span::shortestSpan);
        try_catch_ls(sp, &Span::longestSpan);
        std::cout << GREEN << "Trying to add a secon element " << COLOR_DEFAULT << std::endl;
        try_catch_number(sp, INT_MIN);
    }
    {
        std::cout << std::endl;
        std::cout << GREEN << "---TEST 3: SPAN OBJECT[4] WITH ONLY ONE ELEMENT--- " << COLOR_DEFAULT << std::endl;
        Span sp = Span(4);
        sp.addNumber(2);
        std::cout << GREEN << "Printing elements" << COLOR_DEFAULT << std::endl;
        sp.printElements();
        std::cout << GREEN << "Trying to get the longest and shortes span " << COLOR_DEFAULT << std::endl;
        try_catch_ss(sp, &Span::shortestSpan);
        try_catch_ls(sp, &Span::longestSpan);
        std::cout << GREEN << "Trying to add a secon element " << COLOR_DEFAULT << std::endl;
        try_catch_number(sp, INT_MAX);
        std::cout << GREEN << "Trying to get the longest and shortes span " << COLOR_DEFAULT << std::endl;
        try_catch_ss(sp, &Span::shortestSpan);
        try_catch_ls(sp, &Span::longestSpan);
        std::cout << GREEN << "Assigning the span" << COLOR_DEFAULT << std::endl;
        Span sp2 = sp;
        std::cout << GREEN << "Printing elements of new Span Object" << COLOR_DEFAULT << std::endl;
        sp2.printElements();
        std::cout << GREEN << "Trying to get the longest and shortes span " << COLOR_DEFAULT << std::endl;
        try_catch_ss(sp2, &Span::shortestSpan);
        try_catch_ls(sp2, &Span::longestSpan);
        std::cout << GREEN << "Trying to add a third element " << COLOR_DEFAULT << std::endl;
        try_catch_number(sp2, INT_MIN);
    }
    {
        std::cout << std::endl;
        std::cout << GREEN << "---TEST 4: SPAN OBJECT[5] WITH NO ELEMENTS--- " << COLOR_DEFAULT << std::endl;
        Span sp = Span(5);
        std::cout << GREEN << "Printing elements" << COLOR_DEFAULT << std::endl;
        sp.printElements();
        std::cout << GREEN << "Trying to add elements " << COLOR_DEFAULT << std::endl;
        try_catch_number(sp, 2);
        try_catch_number(sp, 42);
        try_catch_number(sp, 442);
        try_catch_number(sp, 4442);
        try_catch_number(sp, 44442);
        std::cout << GREEN << "Trying to get the longest and shortes span " << COLOR_DEFAULT << std::endl;
        try_catch_ss(sp, &Span::shortestSpan);
        try_catch_ls(sp, &Span::longestSpan);
        std::cout << GREEN << "Printing elements of new Span Object" << COLOR_DEFAULT << std::endl;
        sp.printElements();
        std::cout << GREEN << "Trying to add another element " << COLOR_DEFAULT << std::endl;
        try_catch_number(sp, INT_MIN);
    }
    {
        std::cout << std::endl;
        std::cout << GREEN << "---TEST 5: SPAN OBJECT[150] WITH RANDOM ELEMENTS--- " << COLOR_DEFAULT << std::endl;
        Span sp = Span(150);
        sp.randomFill();
        std::cout << GREEN << "Printing elements" << COLOR_DEFAULT << std::endl;
        sp.printElements();
        std::cout << GREEN << "Trying to get the longest and shortes span " << COLOR_DEFAULT << std::endl;
        try_catch_ss(sp, &Span::shortestSpan);
        try_catch_ls(sp, &Span::longestSpan);
    }
        {
        std::cout << std::endl;
        std::cout << GREEN << "---TEST 6: SPAN OBJECT[10.000] WITH RANDOM ELEMENTS--- " << COLOR_DEFAULT << std::endl;
        Span sp = Span(10000);
        sp.randomFill();
        // std::cout << GREEN << "Printing elements" << COLOR_DEFAULT << std::endl;
        // sp.printElements();
        std::cout << GREEN << "Trying to get the longest and shortes span " << COLOR_DEFAULT << std::endl;
        try_catch_ss(sp, &Span::shortestSpan);
        try_catch_ls(sp, &Span::longestSpan);
    }
    
    return 0;
}



static void	try_catch_ls(Span const & obj, unsigned int (Span::*f)(void) const)
{
	try
	{
		std::cout << "Longest Span: " << (obj.*f)() << "\n";
	}
	catch (std::exception & error)
	{
		std::cerr << RED << error.what() << COLOR_DEFAULT << std::endl;
	}
}

static void	try_catch_ss(Span const & obj, unsigned int (Span::*f)(void) const)
{
	try
	{
		std::cout << "Shortest Span: " << (obj.*f)() << "\n";
	}
	catch (std::exception & error)
	{
		std::cerr << RED << error.what() << COLOR_DEFAULT << std::endl;
	}
}

static void	try_catch_number(Span & obj, int number)
{
	try
	{
        obj.addNumber(number);
		std::cout << "Number: " << number << "\n";
	}
	catch (std::exception & error)
	{
		std::cerr << RED << error.what() << COLOR_DEFAULT << std::endl;
	}
}
