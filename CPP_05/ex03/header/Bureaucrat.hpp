/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/23 12:43:32 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

#include <iostream>
#include "colors.h"
#include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

		static int const	_maxgrade = 1;
		static int const	_mingrade = 150;

	public:
		Bureaucrat(std::string const & name, int grade);
		Bureaucrat(Bureaucrat const & input);
		Bureaucrat & operator=(Bureaucrat const & input);
		~Bureaucrat(void);

		std::string const &	getName(void) const;
		int			getGrade(void) const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm & form);
		void				signForm(AForm * form);
		void				executeForm(AForm const & form);
		void				executeForm(AForm const * form);

		class GradeTooHighExeption : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Bureacrat::GradeTooHighExeption");
				}
		};

		class GradeTooLowExeption : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Bureacrat::GradeTooLowExeption");
				}
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const * input);
std::ostream & operator<<(std::ostream & o, Bureaucrat const & input);

#endif