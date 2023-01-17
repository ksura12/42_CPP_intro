/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 14:08:41 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal was made" << std::endl;
	return;
}

Animal::Animal(std::string type)
{
	this->_type = type;
	std::cout << "Animal type constructor called" << std::endl;
	return;
}

Animal::~Animal(void)
{
	std::cout << "Animal was destroyed" << std::endl;
	return;
}

Animal::Animal(Animal const & input)
{
	std::cout << "Animal-Copy constructor called" << std::endl;
	*this = input;
	return;
}

Animal & Animal::operator=(Animal const & input)
{
	std::cout << "Animal-Assignment operator called" << std::endl;
	this->_type = input._type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return(this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Some Animal noise" << std::endl;
	return;
}