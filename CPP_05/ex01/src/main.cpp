/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:26:52 by ksura             #+#    #+#             */
/*   Updated: 2023/01/19 14:38:06 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/Bureaucrat.hpp"
#include "../header/Form.hpp"
#include <iostream>
#include <limits.h>

static void	printing(std::string content);
static void	try_catch(void (*f)(void));


void	test_constructor(void);

int	main(void)
{
	test_constructor();


	return 0;
}


void invalidSign1(void);
void invalidSign2(void);
void invalidSign3(void);

void	test_constructor(void)
{
	printing("====BASIC BUREAUCRATS CREATION====");
	printing("______VALID BUREAUCRATS________");
	Bureaucrat	*person1 = new Bureaucrat("person1", 15);
	std::cout << person1 << std::endl;
	Bureaucrat person2("person2", 149);
	std::cout << person2 << std::endl;
	
	printing("______COPIE BUREAUCRATS________");
	Bureaucrat person3(person2);
	std::cout << person3 << std::endl;
	Bureaucrat	*person4 = new Bureaucrat(person3);
	std::cout << person3 << std::endl;
	
	printing("______VALID FORMS________");
	Form *forma = new Form("FormA", 20, 20);
	std::cout << forma << std::endl;
	Form formb("FormB", 150, 150);
	std::cout << formb << std::endl;
	Form formc = formb;
	std::cout << formc << std::endl;
	
	printing("______VALID SIGNS________");
	person1->signForm(forma);
	person2.signForm(formb);
	
	printing("______INVALID SIGNS________");
	try_catch(&invalidSign1);
	try_catch(&invalidSign2);
	try_catch(&invalidSign3);
	
	printing("______deleting BUREAUCRATS & FORMS________");
	delete person1;
	delete person4;
	delete forma;

}

void invalidSign1(void)
{
	Form formx("FormX", 10, 10);
	std::cout << formx << std::endl;
	Bureaucrat b1("Heinz", 15);
	std::cout << b1 << std::endl;
	formx.beSigned(b1);
}

void invalidSign2(void)
{
	Form formx("FormX", 100, 100);
	std::cout << formx << std::endl;
	Bureaucrat b1("Heinz", 101);
	std::cout << b1 << std::endl;
	formx.beSigned(b1);
}

void invalidSign3(void)
{
	Form formx("FormX", 102, 102);
	std::cout << formx << std::endl;
	Bureaucrat b1("Heinz", 101);
	std::cout << b1 << std::endl;
	formx.beSigned(b1);
	formx.beSigned(b1);
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