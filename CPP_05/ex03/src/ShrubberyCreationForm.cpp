/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:58:37 by ksura             #+#    #+#             */
/*   Updated: 2023/01/23 13:39:15 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) 
	: AForm(target, _grade_to_sign, _grade_to_ex), _ftype("ShrubberyCreationForm")
{
	if (DEBUG)
		std::cout << YELLOW << "[ShrubberyCreationForm] default constructor called" 
			<< COLOR_DEFAULT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & input) : AForm(input), _ftype("ShrubberyCreationForm")
{
	if (DEBUG)
		std::cout << YELLOW << "[ShrubberyCreationForm] copy constructor called" 
			<< COLOR_DEFAULT << std::endl;
	
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & input)
{
	if (DEBUG)
		std::cout << YELLOW << "[ShrubberyCreationForm] assignmet constructor called" 
			<< COLOR_DEFAULT << std::endl;

	setSig(input.getSig());
	setGrade_e(input.getGrade_e());
	setGrade_s(input.getGrade_s());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (DEBUG)
		std::cout << YELLOW << "[ShrubberyCreationForm] deconstructor called" 
			<< COLOR_DEFAULT << std::endl;
}

void				ShrubberyCreationForm::beSigned(Bureaucrat & name)
{
	if (getSig() == true)
	{
		throw AlreadySignedExeption();
		return ;
	}
	if (getGrade_s() >= name.getGrade())
	{
		std::cout << MAGENTA << "[ShrubberyCreationForm]" << getName() <<" was signed by [Bureaucrat] " 
			<< name.getName() << COLOR_DEFAULT << std::endl;
		setSig(true);
	}
	else
	{
		throw GradeTooHighExeption();
		std::cout << MAGENTA << "[ShrubberyCreationForm]" << getName() << " could not be signed by [Bureaucrat] " 
			<< name.getName() << " , because its Grade is to high for the Bureaucrat" << COLOR_DEFAULT << std::endl;
	}
}

void				ShrubberyCreationForm::beSigned(Bureaucrat * name)
{
	beSigned(*name);
}

void		ShrubberyCreationForm::formAction() const
{
	std::ifstream	file;
	std::string _new_file = getName() + "_shrubbery";
	std::ofstream new_file(_new_file);
	if (!new_file.is_open())
	{
		std::cout << getName() << "_shrubbery could not have been created" << std::endl;
		return ;
	}
		new_file << "                                                         .\n";
		new_file << "                                              .         ;  \n";
		new_file << "                 .              .              ;%     ;;   \n";
		new_file << "                   ,           ,                :;%  %;   \n";
		new_file << "                    :         ;                   :;%;'     .,   \n";
		new_file << "           ,.        %;     %;            ;        %;'    ,;\n";
		new_file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
		new_file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
		new_file << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
		new_file << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
		new_file << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
		new_file << "                    `:%;.  :;bd%;          %;@%;'\n";
		new_file << "                      `@%:.  :;%.         ;@@%;'   \n";
		new_file << "                        `@%.  `;@%.      ;@@%;         \n";
		new_file << "                          `@%%. `@%%    ;@@%;        \n";
		new_file << "                            ;@%. :@%%  %@@%;       \n";
		new_file << "                              %@bd%%%bd%%:;     \n";
		new_file << "                                #@%%%%%:;;\n";
		new_file << "                                %@@%%%::;\n";
		new_file << "                                %@@@%(o);  . '         \n";
		new_file << "                                %@@@o%;:(.,'         \n";
		new_file << "                            `.. %@@@o%::;         \n";
		new_file << "                               `)@@@o%::;         \n";
		new_file << "                                %@@(o)::;        \n";
		new_file << "                               .%@@@@%::;         \n";
		new_file << "                               ;%@@@@%::;.          \n";
		new_file << "                              ;%@@@@%%:;;;. \n";
		new_file << "                          ...;%@@@@@%%:;;;;,.. \n";
}

