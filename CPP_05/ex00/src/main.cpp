/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:26:52 by ksura             #+#    #+#             */
/*   Updated: 2023/01/19 13:49:27 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/Bureaucrat.hpp"
#include <iostream>
#include <limits.h>

static void	printing(std::string content);
static void	try_catch(void (*f)(void));


void	test_constructor(void);
void	test_decrement(void);
void	test_increment(void);

int	main(void)
{
	test_constructor();
	test_decrement();
	test_increment();

	return 0;
}


void	invalidBuros1(void);
void	invalidBuros2(void);
void	invalidBuros3(void);
void	invalidBuros4(void);
void	invalidBuros5(void);

void	test_constructor(void)
{
	printing("====BASIC BUREAUCRATS CREATION====");
	printing("______VALID BUREAUCRATS________");
	Bureaucrat	*person1 = new Bureaucrat("person1", 1);
	std::cout << person1 << std::endl;
	Bureaucrat person2("person2", 149);
	std::cout << person2 << std::endl;
	printing("______COPIE BUREAUCRATS________");
	Bureaucrat person3(person2);
	std::cout << person3 << std::endl;
	Bureaucrat	*person4 = new Bureaucrat(person3);
	std::cout << person3 << std::endl;
	printing("______deleting BUREAUCRATS________");
	delete person1;
	delete person4;

	printing("______NON VALID BUREAUCRATS________");

	try_catch(&invalidBuros1);
	try_catch(&invalidBuros2);
	try_catch(&invalidBuros3);
	try_catch(&invalidBuros4);
	try_catch(&invalidBuros5);
}

void	invalidBuros1(void)
{
	Bureaucrat invalid1("invalid1", 151);
	std::cout << invalid1 << std::endl;
}

void	invalidBuros2(void)
{
	Bureaucrat invalid2("invalid2", 0);
	std::cout << invalid2 << std::endl;
}

void	invalidBuros3(void)
{
	Bureaucrat invalid3("invalid3", INT_MAX);
	std::cout << invalid3 << std::endl;
}

void	invalidBuros4(void)
{
	Bureaucrat invalid4("invalid4", INT_MIN);
	std::cout << invalid4 << std::endl;

}

void	invalidBuros5(void)
{

	Bureaucrat invalid5("invalid5", 552211);
	std::cout << invalid5 << std::endl;
}
 
 //-------------------------------------------------------

void	invalidincrement1(void);

void	test_increment(void)
{
	printing("====INCREMENTS====");
	printing("______BUREAUCRAT CREATION________");
	Bureaucrat	*person1 = new Bureaucrat("person1", 29);
	std::cout << person1 << std::endl;
	Bureaucrat person2("person2", 111);
	std::cout << person2 << std::endl;
	printing("______BUREAUCRAT INCREMENTATION________");
	person1->incrementGrade();
	std::cout << person1 << std::endl;
	person1->incrementGrade();
	std::cout << person1 << std::endl;
	person2.incrementGrade();
	std::cout << person2 << std::endl;
	person2.incrementGrade();
	std::cout << person2 << std::endl;
	printing("______deleting BUREAUCRATS________");
	delete person1;

	printing("______NON VALID BUREAUCRATS INCREMENTS________");

	try_catch(&invalidincrement1);
}

void	invalidincrement1(void)
{

	Bureaucrat invalid1("invalid5", 1);
	std::cout << invalid1 << std::endl;
	invalid1.incrementGrade();
	std::cout << invalid1 << std::endl;
}

//-------------------------------------------------------
void	invaliddecrement1(void);

void	test_decrement(void)
{
	printing("====DECREMENTS====");
	printing("______BUREAUCRAT CREATION________");
	Bureaucrat	*person1 = new Bureaucrat("person1", 29);
	std::cout << person1 << std::endl;
	Bureaucrat person2("person2", 111);
	std::cout << person2 << std::endl;
	printing("______BUREAUCRAT INCREMENTATION________");
	person1->decrementGrade();
	std::cout << person1 << std::endl;
	person1->decrementGrade();
	std::cout << person1 << std::endl;
	person2.decrementGrade();
	std::cout << person2 << std::endl;
	person2.decrementGrade();
	std::cout << person2 << std::endl;
	printing("______deleting BUREAUCRATS________");
	delete person1;

	printing("______NON VALID BUREAUCRATS INCREMENTS________");

	try_catch(&invaliddecrement1);
}

void	invaliddecrement1(void)
{

	Bureaucrat invalid1("invalid5", 150);
	std::cout << invalid1 << std::endl;
	invalid1.decrementGrade();
	std::cout << invalid1 << std::endl;
}
static void	try_catch(void (*f)(void))
{
	try
	{
		f();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << COLOR_DEFAULT << '\n';
	}
	
}

static void	printing(std::string content)
{
	std::cerr << GREEN << "\n" << content << COLOR_DEFAULT << std::endl;
}