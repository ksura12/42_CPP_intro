/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/19 10:19:11 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

#include <iostream>
#include "colors.h"

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

		class GradTooHighExeption : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Bureacrat::GradeTooHighExeption");
				}
		};

		class GradTooLowExeption : public std::exception
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