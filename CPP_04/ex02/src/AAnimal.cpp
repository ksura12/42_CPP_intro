/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 17:02:45 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal was made" << std::endl;
	return;
}

AAnimal::AAnimal(std::string type)
{
	this->_type = type;
	std::cout << "AAnimal type constructor called" << std::endl;
	return;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal was destroyed" << std::endl;
	return;
}

AAnimal::AAnimal(AAnimal const & input)
{
	std::cout << "AAnimal-Copy constructor called" << std::endl;
	*this = input;
	return;
}

AAnimal & AAnimal::operator=(AAnimal const & input)
{
	std::cout << "AAnimal-Assignment operator called" << std::endl;
	this->_type = input._type;
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return(this->_type);
}