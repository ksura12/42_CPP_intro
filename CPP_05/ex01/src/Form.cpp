/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:58:37 by ksura             #+#    #+#             */
/*   Updated: 2023/01/19 14:34:54 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Form.hpp"


Form::Form(std::string const & name, const int grade_s, const int grade_e) 
	: _name(name), _sig(false)
{
	if (DEBUG)
		std::cout << YELLOW << "[Form] default constructor called" 
			<< COLOR_DEFAULT << std::endl;
	if (grade_e > _mingrade || grade_s > _mingrade)
		throw GradeTooLowExeption();
	if (grade_e < _maxgrade || grade_s < _maxgrade)
		throw GradeTooHighExeption();
	_grade_e = grade_e;
	_grade_s = grade_s;
}

Form::Form(Form const & input) : _name(input._name + "_copy"), _sig(input._sig), _grade_s(input._grade_s), _grade_e(input._grade_e)
{
	if (DEBUG)
		std::cout << YELLOW << "[Form] copy constructor called" 
			<< COLOR_DEFAULT << std::endl;
}

Form & Form::operator=(Form const & input)
{
	if (DEBUG)
		std::cout << YELLOW << "[Form] assignmet constructor called" 
			<< COLOR_DEFAULT << std::endl;
	_sig = input._sig;
	_grade_s = input._grade_s;
	_grade_e = input._grade_e;
	return (*this);
}

Form::~Form(void)
{
	if (DEBUG)
		std::cout << YELLOW << "[Form] deconstructor called" 
			<< COLOR_DEFAULT << std::endl;
}

const std::string &	Form::getName(void) const
{
	return (_name);
}

int			Form::getGrade_e(void) const
{
	return (_grade_e);
}

int			Form::getGrade_s(void) const
{
	return (_grade_s);
}

bool				Form::getSig(void) const
{
	return(_sig);
}

void				Form::beSigned(Bureaucrat & name)
{
	if (_sig == true)
	{
		throw AlreadySignedExeption();
		return ;
	}
	if (_grade_s >= name.getGrade())
	{
		std::cout << MAGENTA << "[Form]" << _name <<" was signed by [Bureaucrat] " 
			<< name.getName() << COLOR_DEFAULT << std::endl;
		_sig = true;
	}
	else
	{
		throw GradeTooHighExeption();
		std::cout << MAGENTA << "[Form]" << _name << " could not be signed by [Bureaucrat] " 
			<< name.getName() << " , because its Grade is to high for the Bureaucrat" << COLOR_DEFAULT << std::endl;
	}
}

void				Form::beSigned(Bureaucrat * name)
{
	beSigned(*name);
}

std::ostream & operator<<(std::ostream & o, Form const * input)
{
	o << input->getName() << ", with grade to execute :[" << input->getGrade_e()
		<< "] and the Grade to sign: [" << input->getGrade_s() <<"] and signature status: "
		<< input->getSig();
	return (o);
}

std::ostream & operator<<(std::ostream & o, Form const & input)
{
	o << input.getName() << ", with grade to execute :[" << input.getGrade_e()
		<< "] and the Grade to sign: [" << input.getGrade_s() << "] and signature status: "
		<< input.getSig();
	return (o);
}
