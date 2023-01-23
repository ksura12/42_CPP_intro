/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:58:37 by ksura             #+#    #+#             */
/*   Updated: 2023/01/23 15:26:37 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Intern.hpp"

Intern::Intern()
{
	if (DEBUG)
		std::cout << YELLOW << "[Intern] default constructor called" 
			<< COLOR_DEFAULT << std::endl;
}

Intern::Intern(Intern const & input)
{
	if (DEBUG)
		std::cout << YELLOW << "[Intern] copy constructor called" 
			<< COLOR_DEFAULT << std::endl;
	*this = input;
}

Intern & Intern::operator=(Intern const & input)
{
	(void) input;
	if (DEBUG)
		std::cout << YELLOW << "[Intern] assignmet constructor called" 
			<< COLOR_DEFAULT << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	if (DEBUG)
		std::cout << YELLOW << "[Intern] deconstructor called" 
			<< COLOR_DEFAULT << std::endl;
}

AForm *		Intern::makeForm(std::string form_name, std::string form_target)
{
	std::string const forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	formChoice = -1;
	AForm * newForm = NULL;

	for (int i = 0; i < 3; i++)
	{
		if(form_name == forms[i])
			{
				formChoice = i;
				break;
			}
	}
	switch (formChoice)
	{
	case 0:
		newForm = new ShrubberyCreationForm(form_target);
		std::cout << "Intern creates a ShrubberyCreationForm" << std::endl;
		break;
	case 1:
		newForm = new RobotomyRequestForm(form_target);
		std::cout << "Intern creates a RobotomyRequestForm" << std::endl;
		break;
	case 2:
		newForm = new PresidentialPardonForm(form_target);
		std::cout << "Intern creates a PresidentialPardonForm" << std::endl;
		break;
	default:
		std::cout << "Intern creates nothing. The form: " << form_target 
			<< " does not exist" << std::endl;
		break;
	}
	return newForm;
}
