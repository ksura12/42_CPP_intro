/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/23 13:39:58 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_CLASS_HPP
# define ROBOTOMYREQUESTFORM_CLASS_HPP

#include <iostream>
#include "colors.h"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class	RobotomyRequestForm : public AForm
{
	private:
		static int const	_grade_to_sign = 72;
		static int const	_grade_to_ex = 45;
		std::string const	_ftype;

	public:
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const & input);
		RobotomyRequestForm & operator=(RobotomyRequestForm const & input);
		~RobotomyRequestForm(void);
		
		void		beSigned(Bureaucrat & name);
		void		beSigned(Bureaucrat * name);
		void		formAction() const;
		
};

#endif
