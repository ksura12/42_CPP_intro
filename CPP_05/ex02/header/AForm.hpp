/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/23 13:39:42 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CLASS_HPP
# define AFORM_CLASS_HPP

#include <iostream>
#include "colors.h"
#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
	private:
		const std::string 	_name;
		bool				_sig;
		int			_grade_s;
		int			_grade_e;

		static int const	_maxgrade = 1;
		static int const	_mingrade = 150;

	public:
		AForm(std::string const & name, const int grade_s, const int grade_e);
		AForm(AForm const & input);
		AForm & operator=(AForm const & input);
		virtual ~AForm(void);

		const std::string &	getName(void) const;
		bool				getSig(void) const;
		int			getGrade_s(void) const;
		int			getGrade_e(void) const;

		// void		setName(const std::string name);
		void		setSig(bool signature);
		void		setGrade_s(const int grade_s);
		void		setGrade_e(const int grade_e);

		void				beSigned(Bureaucrat & name);
		void				beSigned(Bureaucrat * name);

		void		execute(Bureaucrat const & executer) const;
		void		execute(Bureaucrat const * executer) const;
		virtual void	formAction() const = 0 ;

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
		
		class NotSignedExeption : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Form::NotSignedExeption");
				}
		};
};

std::ostream & operator<<(std::ostream & o, AForm const * input);
std::ostream & operator<<(std::ostream & o, AForm const & input);

#endif