/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 19:16:02 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cure.hpp"
#include "../header/colors.h"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
	return;
}

Cure::Cure(std::string const & type) : AMateria(type)
{
	std::cout << "Cure constructor called" << std::endl;
	return;
}

Cure::~Cure(void)
{
	std::cout << "Cure was destroyed" << std::endl;
	return;
}

Cure::Cure(Cure const & input) : AMateria("cure_copy")
{
	std::cout << "Cure-Copy constructor called" << std::endl;
	*this = input;
	return;
}

Cure & Cure::operator=(Cure const & input)
{
	std::cout << "Cure-Assignment operator called" << std::endl;
	this->_type = input._type;
	return (*this);
}

Cure* 			Cure::clone(void) const
{
	return (new Cure("cure"));
}

void 			Cure::use(ICharacter& target)
{
	std::cout << RED << "* heals <name>"
		<< target.getName() << "’s wounds *\n" << COLOR_DEFAULT;
}

std::string		Cure::getType(void) const
{
	return(this->_type);
}
