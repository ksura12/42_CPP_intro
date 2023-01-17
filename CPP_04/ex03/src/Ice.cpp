/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 19:12:24 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Ice.hpp"
#include "../header/colors.h"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
	return;
}

Ice::Ice(std::string const & type) : AMateria(type)
{
	std::cout << "Ice constructor called" << std::endl;
	return;
}

Ice::~Ice(void)
{
	std::cout << "Ice was destroyed" << std::endl;
	return;
}

Ice::Ice(Ice const & input) : AMateria("ice_copy")
{
	std::cout << "Ice-Copy constructor called" << std::endl;
	*this = input;
	return;
}

Ice & Ice::operator=(Ice const & input)
{
	std::cout << "Ice-Assignment operator called" << std::endl;
	this->_type = input._type;
	return (*this);
}

Ice* 			Ice::clone(void) const
{
	return (new Ice("ice"));
}

void 			Ice::use(ICharacter& target)
{
	std::cout << BLUE << "* shoots an ice bolt at " 
		<< target.getName() << " *\n" << COLOR_DEFAULT;
}

std::string		Ice::getType(void) const
{
	return(this->_type);
}
