/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/23 14:00:17 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_CLASS_HPP
# define PRESIDENTIALPARDONFORM_CLASS_HPP

#include <iostream>
#include "colors.h"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class	PresidentialPardonForm : public AForm
{
	private:
		static int const	_grade_to_sign = 25;
		static int const	_grade_to_ex = 5;
		std::string const	_ftype;

	public:
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & input);
		PresidentialPardonForm & operator=(PresidentialPardonForm const & input);
		~PresidentialPardonForm(void);
		
		void		beSigned(Bureaucrat & name);
		void		beSigned(Bureaucrat * name);
		void		formAction() const;
		
};

#endif
