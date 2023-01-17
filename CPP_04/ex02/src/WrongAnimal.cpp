/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 14:25:11 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal was made" << std::endl;
	return;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->_type = type;
	std::cout << "WrongAnimal type constructor called" << std::endl;
	return;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal was destroyed" << std::endl;
	return;
}

WrongAnimal::WrongAnimal(WrongAnimal const & input)
{
	std::cout << "WrongAnimal-Copy constructor called" << std::endl;
	*this = input;
	return;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & input)
{
	std::cout << "WrongAnimal-Assignment operator called" << std::endl;
	this->_type = input._type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return(this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Some WrongAnimal noise" << std::endl;
	return;
}