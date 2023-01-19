/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/19 14:30:46 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

#include <iostream>
#include "colors.h"
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	private:
		const std::string 	_name;
		bool				_sig;
		int			_grade_s;
		int			_grade_e;

		static int const	_maxgrade = 1;
		static int const	_mingrade = 150;

	public:
		Form(std::string const & name, const int grade_s, const int grade_e);
		Form(Form const & input);
		Form & operator=(Form const & input);
		~Form(void);

		const std::string &	getName(void) const;
		bool				getSig(void) const;
		int			getGrade_s(void) const;
		int			getGrade_e(void) const;

		void				beSigned(Bureaucrat & name);
		void				beSigned(Bureaucrat * name);

		class GradeTooHighExeption : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Form::GradeTooHighExeption");
				}
		};

		class GradeTooLowExeption : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Form::GradeTooLowExeption");
				}
		};
		
		class AlreadySignedExeption : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Form::AlreadySignedExeption");
				}
		};
};

std::ostream & operator<<(std::ostream & o, Form const * input);
std::ostream & operator<<(std::ostream & o, Form const & input);

#endif