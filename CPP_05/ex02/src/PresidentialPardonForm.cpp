/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:58:37 by ksura             #+#    #+#             */
/*   Updated: 2023/01/23 14:11:46 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) 
	: AForm(target, _grade_to_sign, _grade_to_ex), _ftype("PresidentialPardonForm")
{
	if (DEBUG)
		std::cout << YELLOW << "[PresidentialPardonForm] default constructor called" 
			<< COLOR_DEFAULT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & input) : AForm(input), _ftype("PresidentialPardonForm")
{
	if (DEBUG)
		std::cout << YELLOW << "[PresidentialPardonForm] copy constructor called" 
			<< COLOR_DEFAULT << std::endl;
	
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & input)
{
	if (DEBUG)
		std::cout << YELLOW << "[PresidentialPardonForm] assignmet constructor called" 
			<< COLOR_DEFAULT << std::endl;

	setSig(input.getSig());
	setGrade_e(input.getGrade_e());
	setGrade_s(input.getGrade_s());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (DEBUG)
		std::cout << YELLOW << "[PresidentialPardonForm] deconstructor called" 
			<< COLOR_DEFAULT << std::endl;
}

void				PresidentialPardonForm::beSigned(Bureaucrat & name)
{
	if (getSig() == true)
	{
		throw AlreadySignedExeption();
		return ;
	}
	if (getGrade_s() >= name.getGrade())
	{
		std::cout << MAGENTA << "[PresidentialPardonForm]" << getName() <<" was signed by [Bureaucrat] " 
			<< name.getName() << COLOR_DEFAULT << std::endl;
		setSig(true);
	}
	else
	{
		throw GradeTooHighExeption();
		std::cout << MAGENTA << "[PresidentialPardonForm]" << getName() << " could not be signed by [Bureaucrat] " 
			<< name.getName() << " , because its Grade is to high for the Bureaucrat" << COLOR_DEFAULT << std::endl;
	}
}

void				PresidentialPardonForm::beSigned(Bureaucrat * name)
{
	beSigned(*name);
}

void		PresidentialPardonForm::formAction() const
{
		std::cout << getName() << " has been pardoned by Zaphrod Beebelbrox" << std::endl;
}


