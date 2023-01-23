/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:58:37 by ksura             #+#    #+#             */
/*   Updated: 2023/01/23 14:25:15 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AForm.hpp"


AForm::AForm(std::string const & name, const int grade_s, const int grade_e) 
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

AForm::AForm(AForm const & input) : _name(input._name + "_copy"), _sig(input._sig), _grade_s(input._grade_s), _grade_e(input._grade_e)
{
	if (DEBUG)
		std::cout << YELLOW << "[Form] copy constructor called" 
			<< COLOR_DEFAULT << std::endl;
}

AForm & AForm::operator=(AForm const & input)
{
	if (DEBUG)
		std::cout << YELLOW << "[Form] assignmet constructor called" 
			<< COLOR_DEFAULT << std::endl;
	_sig = input._sig;
	_grade_s = input._grade_s;
	_grade_e = input._grade_e;
	return (*this);
}

AForm::~AForm(void)
{
	if (DEBUG)
		std::cout << YELLOW << "[Form] deconstructor called" 
			<< COLOR_DEFAULT << std::endl;
}

const std::string &	AForm::getName(void) const
{
	return (_name);
}

int			AForm::getGrade_e(void) const
{
	return (_grade_e);
}

int			AForm::getGrade_s(void) const
{
	return (_grade_s);
}

bool		AForm::getSig(void) const
{
	return(_sig);
}

// void		AForm::setName(const std::string name)
// {
// 	_name = name;
// }

void		AForm::setSig(bool signature)
{
	_sig = signature;
}

void		AForm::setGrade_s(const int grade_s)
{
	_grade_s = grade_s;
}

void		AForm::setGrade_e(const int grade_e)
{
	_grade_e = grade_e;
}

void				AForm::beSigned(Bureaucrat & name)
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

void				AForm::beSigned(Bureaucrat * name)
{
	beSigned(*name);
}

void		AForm::execute(Bureaucrat const & executer) const
{
	if (_sig == true && executer.getGrade() <= _grade_e)
	{
		formAction();
		std::cout << GREEN << executer.getName() << "  executed "
			<< _name << COLOR_DEFAULT << std::endl;
	}
	else if (_sig == false)
	{
		std::cout << RED << _name << " can't be executed because it's not signed" << COLOR_DEFAULT << std::endl;
		throw NotSignedExeption();
	}
		
	else if (executer.getGrade() > _grade_e)
	{
		std::cout << RED << executer.getName() << "  has no authority to execute "
			<< _name << COLOR_DEFAULT << std::endl;
		throw GradeTooLowExeption();
	}
}

void		AForm::execute(Bureaucrat const * executer) const
{
	execute(*executer);
}

std::ostream & operator<<(std::ostream & o, AForm const * input)
{
	o << input->getName() << ", with grade to execute :[" << input->getGrade_e()
		<< "] and the Grade to sign: [" << input->getGrade_s() <<"] and signature status: "
		<< input->getSig();
	return (o);
}

std::ostream & operator<<(std::ostream & o, AForm const & input)
{
	o << input.getName() << ", with grade to execute :[" << input.getGrade_e()
		<< "] and the Grade to sign: [" << input.getGrade_s() << "] and signature status: "
		<< input.getSig();
	return (o);
}
