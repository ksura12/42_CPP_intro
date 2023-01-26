/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:09:08 by ksura             #+#    #+#             */
/*   Updated: 2023/01/26 12:29:33 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/easyfind.hpp"
#include "../header/colors.h"
#include <iostream>
#include <iterator>
#include <list>
#include <deque>
#include <algorithm>

static int  rand_number();
static void	print(int & number);

int main(void)
{
    std::vector<int>    int_vector(100);
    std::list<int>      int_list(100);
    std::deque<int>     int_deque(100);
    std::srand(time(NULL));

    std::cout << GREEN << "---FILL CONTAINERS---" << COLOR_DEFAULT << std::endl;
    std::generate(int_vector.begin(), int_vector.end(), rand_number);
    std::generate(int_list.begin(), int_list.end(), rand_number);
    std::generate(int_deque.begin(), int_deque.end(), rand_number);


    std::cout << GREEN << "---PRINTING INT VECTOR CONTENT---" << COLOR_DEFAULT << std::endl;
    int_vector.push_back(111);
    for_each(int_vector.begin(), int_vector.end(), print);

    std::cout << GREEN << "---TRY TO FIND NUMBER 100---" << COLOR_DEFAULT << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(int_vector, 100);
        std::cout << "Element found at adress" << it.base() << ", with index: " << std::distance(int_vector.begin(), it) << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << RED << e.what() << '\n' << COLOR_DEFAULT;
    }
    std::cout << GREEN << "---TRY TO FIND NUMBER 111---" << COLOR_DEFAULT << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(int_vector, 111);
        std::cout << "Element found at adress" << it.base() << ", with index: " << std::distance(int_vector.begin(), it) << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << RED << e.what() << '\n' << COLOR_DEFAULT;
    }
    
 std::cout << GREEN << "---PRINTING INT LIST CONTENT---" << COLOR_DEFAULT << std::endl;
    int_list.push_back(111);
    for_each(int_list.begin(), int_list.end(), print);
    std::cout << GREEN << "---TRY TO FIND NUMBER 100---" << COLOR_DEFAULT << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(int_list, 100);
        std::cout << "Element found at adress " << it.operator->() << ", with index: " << std::distance(int_list.begin(), it)  << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << RED << e.what() << '\n' << COLOR_DEFAULT;
    }
    std::cout << GREEN << "---TRY TO FIND NUMBER 111---" << COLOR_DEFAULT << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(int_list, 111);
        std::cout << "Element found at adress " << it.operator->() << ", with index: " << std::distance(int_list.begin(), it) << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << RED << e.what() << '\n' << COLOR_DEFAULT;
    }

 std::cout << GREEN << "---PRINTING INT DEQUE CONTENT---" << COLOR_DEFAULT << std::endl;
    int_deque.push_back(111);
    for_each(int_deque.begin(), int_deque.end(), print);
    std::cout << GREEN << "---TRY TO FIND NUMBER 100---" << COLOR_DEFAULT << std::endl;
    try
    {
        std::deque<int>::iterator it = easyfind(int_deque, 100);
        std::cout << "Element found at adress " << it.operator->() << ", with index: " << std::distance(int_deque.begin(), it)  << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << RED << e.what() << '\n' << COLOR_DEFAULT;
    }
    std::cout << GREEN << "---TRY TO FIND NUMBER 111---" << COLOR_DEFAULT << std::endl;
    try
    {
        std::deque<int>::iterator it = easyfind(int_deque, 111);
        std::cout << "Element found at adress " << it.operator->() << ", with index: " << std::distance(int_deque.begin(), it) << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << RED << e.what() << '\n' << COLOR_DEFAULT;
    }
    return 0;
}

static int  rand_number()
{
    return (std::rand() % 100);
}

static void	print(int & number)
{
	std::cout << number << " ";
}