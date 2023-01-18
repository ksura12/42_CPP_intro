/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/18 11:20:19 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "AMateria constructor called" << std::endl;
	return;
}

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	std::cout << "AMateria type constructor called" << std::endl;
	return;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria was destroyed" << std::endl;
	return;
}

AMateria::AMateria(AMateria const & input)
{
	std::cout << "AMateria-Copy constructor called" << std::endl;
	*this = input;
	return;
}

AMateria & AMateria::operator=(AMateria const & input)
{
	std::cout << "AMateria-Assignment operator called" << std::endl;
	this->_type = input._type;
	return (*this);
}

std::string const &	AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	(void) target;
}