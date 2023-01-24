/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:45:49 by ksura             #+#    #+#             */
/*   Updated: 2023/01/24 17:28:29 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Base.hpp"

Base * generate()
{
	Base * BaseOut = NULL;

	int		number = -1;

	number = rand() % 3;
	
	switch (number)
	{
	case 0:
		BaseOut = new A();
		std::cout << MAGENTA << "A created" << COLOR_DEFAULT << std::endl;
		break;
	case 1:
		BaseOut = new B();
		std::cout << BLUE << "B created" << COLOR_DEFAULT << std::endl;
		break;
	case 2:
		BaseOut = new C();
		std::cout << YELLOW << "C created" << COLOR_DEFAULT << std::endl;
		break;
	default:
		BaseOut = NULL;
		break;
	}
	return BaseOut;
}

void identify(Base * p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << MAGENTA << "The class type is A" << COLOR_DEFAULT << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << BLUE << "The class type is B" << COLOR_DEFAULT << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << YELLOW << "The class type is C" << COLOR_DEFAULT << std::endl;
}

void identify(Base & p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << MAGENTA << "The class type is A" << COLOR_DEFAULT << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << COLOR_DEFAULT << '\n';
	}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << BLUE << "The class type is B" << COLOR_DEFAULT << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << COLOR_DEFAULT << '\n';
	}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << YELLOW << "The class type is C" << COLOR_DEFAULT << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << COLOR_DEFAULT << '\n';
	}
	
}

int main()
{
	Base * testobject = NULL;
	for (int i = 0; i < 10; i++)
	{
		std::cout << GREEN << "___Generating a random Object___" << COLOR_DEFAULT << std::endl;
		testobject = generate();
		std::cout << GREEN << "___Identify the random Object by Reference___" << COLOR_DEFAULT << std::endl;
		identify(testobject);
		std::cout << GREEN << "___Identify the random Object by Pointer___" << COLOR_DEFAULT << std::endl;
		identify(*testobject);
		std::cout << GREEN << "___Delete the Object___" << COLOR_DEFAULT << std::endl;
		delete testobject;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	return 0;
}