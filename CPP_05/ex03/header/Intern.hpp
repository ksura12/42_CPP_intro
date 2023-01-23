/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/23 15:08:53 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

#include <iostream>
#include "colors.h"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern
{

	public:
		Intern();
		Intern(Intern const & input);
		Intern & operator=(Intern const & input);
		~Intern(void);

		AForm *		makeForm(std::string form_name, std::string form_target);
};


#endif