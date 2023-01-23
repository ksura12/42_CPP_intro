/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/23 13:39:47 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP
# define SHRUBBERYCREATIONFORM_CLASS_HPP

#include <iostream>
#include "colors.h"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class	ShrubberyCreationForm : public AForm
{
	private:
		static int const	_grade_to_sign = 145;
		static int const	_grade_to_ex = 137;
		std::string const	_ftype;

	public:
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & input);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & input);
		~ShrubberyCreationForm(void);
		
		void		beSigned(Bureaucrat & name);
		void		beSigned(Bureaucrat * name);
		void		formAction() const;
		
};

#endif
