/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:26:52 by ksura             #+#    #+#             */
/*   Updated: 2023/01/23 15:31:01 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"
#include "../header/Intern.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include <iostream>
#include <limits.h>


static void	printing(std::string content);


void	test_constructor(void);

int	main(void)
{
	printing("====BASIC INTERN CREATION====");
	Intern	*intern1 = new Intern();

	printing("______VALID FORMS Creation________");
	AForm * form1 = intern1->makeForm("shrubbery creation", "trees");
	AForm * form2 = intern1->makeForm("robotomy request", "rob");
	AForm * form3 = intern1->makeForm("presidential pardon", "vice president");
	intern1->makeForm("wrong Form", "wrong");

	Bureaucrat	*person1 = new Bureaucrat("person1", 4);
	std::cout << person1 << std::endl;

	printing("______VALID SIGNS & Executions SHRUBBERY________");
	person1->signForm(form1);
	person1->executeForm(form1);
	person1->signForm(form2);
	person1->executeForm(form2);
	person1->signForm(form3);
	person1->executeForm(form3);

	delete intern1;
	delete person1;
	delete form1;
	delete form2;
	delete form3;

	return 0;
}

static void	printing(std::string content)
{
	std::cerr << GREEN << "\n" << content << COLOR_DEFAULT << std::endl;
}