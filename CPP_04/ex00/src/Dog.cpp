/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 14:08:21 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Dog.hpp"
#include "../header/Animal.hpp"
#include "../header/colors.h"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << BLUE << "Dog was made" <<COLOR_DEFAULT << std::endl;
	return;
}

Dog::~Dog(void)
{
	std::cout << BLUE << "Dog was destroyed" <<COLOR_DEFAULT << std::endl;
	return;
}

Dog::Dog(Dog const & input)
{
	std::cout << BLUE << "Dog-Copy constructor called" <<COLOR_DEFAULT << std::endl;
	*this = input;
	return;
}

Dog & Dog::operator=(Dog const & input)
{
	std::cout << BLUE << "Dog-Assignment operator called" <<COLOR_DEFAULT << std::endl;
	this->_type = input._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << BLUE <<"Dog: WUFF WUFF" <<COLOR_DEFAULT << std::endl;
	return;
}