/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:09:08 by ksura             #+#    #+#             */
/*   Updated: 2023/01/25 16:41:04 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Array.hpp"
#include "../header/colors.h"
#include <climits>
#include <iostream>

#define MAX_VAL 750
int main(int, char**)
{
	std::cout << GREEN << "---Creating Arrays---" << COLOR_DEFAULT << std::endl;
    Array<int>	empty;
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
	
	std::cout << BLUE << "Size of numbers array :" << empty.size() << COLOR_DEFAULT << std::endl;
	std::cout << BLUE << "Value of numbers[15] :" << numbers[15] << COLOR_DEFAULT << std::endl;
	std::cout << BLUE << "Size of empty array :" << numbers.size() << COLOR_DEFAULT << std::endl;

	std::cout << GREEN << "Assignign random numbers" << COLOR_DEFAULT << std::endl;
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

	std::cout << GREEN << "Comparing the values" << COLOR_DEFAULT << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	std::cout << GREEN << "Trial of accessing negativ index elements of the array" << COLOR_DEFAULT << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << GREEN << "Trial of accessing a to high index element" << COLOR_DEFAULT << std::endl;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << BLUE << "Value of numbers[105] :" << numbers[105] << COLOR_DEFAULT << std::endl;
	std::cout << GREEN << "Reassignign random numbers" << COLOR_DEFAULT << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	std::cout << BLUE << "Value of numbers[105] :" << numbers[105] << COLOR_DEFAULT << std::endl;
	std::cout << GREEN << "deleting arrays" << COLOR_DEFAULT << std::endl;
    delete [] mirror;
    return 0;
}