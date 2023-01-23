/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:58:37 by ksura             #+#    #+#             */
/*   Updated: 2023/01/23 13:47:40 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) 
	: AForm(target, _grade_to_sign, _grade_to_ex), _ftype("RobotomyRequestForm")
{
	if (DEBUG)
		std::cout << YELLOW << "[RobotomyRequestForm] default constructor called" 
			<< COLOR_DEFAULT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & input) : AForm(input), _ftype("RobotomyRequestForm")
{
	if (DEBUG)
		std::cout << YELLOW << "[RobotomyRequestForm] copy constructor called" 
			<< COLOR_DEFAULT << std::endl;
	
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & input)
{
	if (DEBUG)
		std::cout << YELLOW << "[RobotomyRequestForm] assignmet constructor called" 
			<< COLOR_DEFAULT << std::endl;

	setSig(input.getSig());
	setGrade_e(input.getGrade_e());
	setGrade_s(input.getGrade_s());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (DEBUG)
		std::cout << YELLOW << "[RobotomyRequestForm] deconstructor called" 
			<< COLOR_DEFAULT << std::endl;
}

void				RobotomyRequestForm::beSigned(Bureaucrat & name)
{
	if (getSig() == true)
	{
		throw AlreadySignedExeption();
		return ;
	}
	if (getGrade_s() >= name.getGrade())
	{
		std::cout << MAGENTA << "[RobotomyRequestForm]" << getName() <<" was signed by [Bureaucrat] " 
			<< name.getName() << COLOR_DEFAULT << std::endl;
		setSig(true);
	}
	else
	{
		throw GradeTooHighExeption();
		std::cout << MAGENTA << "[RobotomyRequestForm]" << getName() << " could not be signed by [Bureaucrat] " 
			<< name.getName() << " , because its Grade is to high for the Bureaucrat" << COLOR_DEFAULT << std::endl;
	}
}

void				RobotomyRequestForm::beSigned(Bureaucrat * name)
{
	beSigned(*name);
}

void		RobotomyRequestForm::formAction() const
{
	if (rand() % 2 == 0)
	{
		std::cout << getName() << " has successfully been robotomized" << std::endl;
	}
	else
		std::cout << "Robotomy failed" << std::endl;
	
}


