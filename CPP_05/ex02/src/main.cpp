/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:26:52 by ksura             #+#    #+#             */
/*   Updated: 2023/01/23 14:19:24 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
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
void invalidSign4(void);

void	test_constructor(void)
{
	printing("====BASIC BUREAUCRATS CREATION====");
	printing("______VALID BUREAUCRATS________");
	Bureaucrat	*person1 = new Bureaucrat("person1", 15);
	std::cout << person1 << std::endl;
	Bureaucrat person2("person2", 149);
	std::cout << person2 << std::endl;
	Bureaucrat *person3 = new Bureaucrat("person3", 2);
	std::cout << person3 << std::endl;
	
	// printing("______COPIE BUREAUCRATS________");
	// Bureaucrat	*person4 = new Bureaucrat(person3);
	// std::cout << person3 << std::endl;
	
	printing("______VALID FORMS Shrubbery________");
	ShrubberyCreationForm *sfa = new ShrubberyCreationForm("SFA");
	std::cout << sfa << std::endl;
	printing("______VALID FORMS Robotomy________");
	RobotomyRequestForm *rrf = new RobotomyRequestForm("Robot");
	std::cout << rrf << std::endl;
	printing("______VALID FORMS Presidential________");
	PresidentialPardonForm *ppf = new PresidentialPardonForm("PreaPa");
	std::cout << ppf << std::endl;
	// Form formb("FormB", 150, 150);
	// std::cout << formb << std::endl;
	// Form formc = formb;
	// std::cout << formc << std::endl;
	
	printing("______VALID SIGNS & Executions SHRUBBERY________");
	person1->signForm(sfa);
	person1->executeForm(sfa);
	printing("______VALID SIGNS & EXECUTIONS ROBOTOMY________");
	person1->signForm(rrf);
	person1->executeForm(rrf);
	person1->executeForm(rrf);
	person1->executeForm(rrf);
	person1->executeForm(rrf);
	printing("______VALID SIGNS & EXECUTIONS PRESIDENT________");
	person3->signForm(ppf);
	person3->executeForm(ppf);
	// person2.signForm(formb);
	
	printing("______INVALID SIGNS Shrubbery________");
	try_catch(&invalidSign1);
	printing("______INVALID SIGNS Robotomy________");
	try_catch(&invalidSign2);
	printing("______INVALID SIGNS President________");
	try_catch(&invalidSign3);
	try_catch(&invalidSign4);
	
	// printing("______deleting BUREAUCRATS & FORMS________");
	delete person1;
	delete person3;
	delete sfa;
	delete rrf;

}

void invalidSign1(void)
{
	ShrubberyCreationForm formS("FormS");
	std::cout << formS << std::endl;
	Bureaucrat b1("Heinz", 145);
	std::cout << b1 << std::endl;
	formS.beSigned(b1);
	formS.execute(b1);
}

void invalidSign2(void)
{
	RobotomyRequestForm formR("Ronald");
	std::cout << formR << std::endl;
	Bureaucrat b1("Heinz", 101);
	std::cout << b1 << std::endl;
	formR.beSigned(b1);
	formR.execute(b1);
}

void invalidSign3(void)
{
	PresidentialPardonForm formP("Kevin");
	std::cout << formP << std::endl;
	Bureaucrat b1("Heinz", 25);
	std::cout << b1 << std::endl;
	formP.beSigned(b1);
	formP.execute(b1);
	PresidentialPardonForm formP2("K2");
	std::cout << formP2 << std::endl;
	formP2.execute(b1);
}

void invalidSign4(void)
{
	Bureaucrat b1("Heinz", 25);
	std::cout << b1 << std::endl;
	PresidentialPardonForm formP2("K2");
	std::cout << formP2 << std::endl;
	formP2.execute(b1);
}

// void invalidSign3(void)
// {
// 	Form formx("FormX", 102, 102);
// 	std::cout << formx << std::endl;
// 	Bureaucrat b1("Heinz", 101);
// 	std::cout << b1 << std::endl;
// 	formx.beSigned(b1);
// 	formx.beSigned(b1);
// }

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