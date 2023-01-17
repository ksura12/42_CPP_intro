/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 14:27:00 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/WrongCat.hpp"
#include "../header/WrongAnimal.hpp"
#include "../header/colors.h"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << GREEN << "WrongCat was made" <<COLOR_DEFAULT << std::endl;
	return;
}

WrongCat::~WrongCat(void)
{
	std::cout << GREEN << "WrongCat was destroyed" <<COLOR_DEFAULT << std::endl;
	return;
}

WrongCat::WrongCat(WrongCat const & input)
{
	std::cout << GREEN << "WrongCat-Copy constructor called" <<COLOR_DEFAULT << std::endl;
	*this = input;
	return;
}

WrongCat & WrongCat::operator=(WrongCat const & input)
{
	std::cout << GREEN << "WrongCat-Assignment operator called" <<COLOR_DEFAULT << std::endl;
	this->_type = input._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << GREEN <<"WrongCat: Miau Miau" <<COLOR_DEFAULT << std::endl;
	return;
}