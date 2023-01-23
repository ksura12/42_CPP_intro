/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:58:37 by ksura             #+#    #+#             */
/*   Updated: 2023/01/20 13:31:31 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name)
{
	if (DEBUG)
		std::cout << YELLOW << "[Bereaucrat] default constructor called" 
			<< COLOR_DEFAULT << std::endl;
	if (grade > _mingrade)
		throw GradeTooLowExeption();
	if (grade < _maxgrade)
		throw GradeTooHighExeption();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & input) : _name(input._name + "_copy")
{
	if (DEBUG)
		std::cout << YELLOW << "[Bereaucrat] copy constructor called" 
			<< COLOR_DEFAULT << std::endl;
	*this = input;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & input)
{
	if (DEBUG)
		std::cout << YELLOW << "[Bereaucrat] assignmet constructor called" 
			<< COLOR_DEFAULT << std::endl;
	this->_grade = input._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	if (DEBUG)
		std::cout << YELLOW << "[Bereaucrat] deconstructor called" 
			<< COLOR_DEFAULT << std::endl;
}

std::string const &	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void				Bureaucrat::incrementGrade()
{
	if (DEBUG)
		std::cout << YELLOW << "[Bereaucrat] increment grade called" 
			<< COLOR_DEFAULT << std::endl;
	if (this->_grade == this->_maxgrade)
		throw GradeTooHighExeption();
	this->_grade--;
}

void				Bureaucrat::decrementGrade()
{
	if (DEBUG)
		std::cout << YELLOW << "[Bureaucrat] decrement grade called" 
			<< COLOR_DEFAULT << std::endl;
	if (this->_grade == this->_mingrade)
		throw GradeTooLowExeption();
	this->_grade++;
}

void				Bureaucrat::signForm(AForm & form)
{
	form.beSigned(*this);
}

void				Bureaucrat::signForm(AForm * form)
{
	form->beSigned(this);
}

void				Bureaucrat::executeForm(AForm const & form)
{
	form.execute(*this);
}

void				Bureaucrat::executeForm(AForm const * form)
{
	form->execute(this);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const * input)
{
	o << input->getName() << ", with grade " << input->getGrade();
	return (o);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & input)
{
	o << input.getName() << ", with grade " << input.getGrade();
	return (o);
}