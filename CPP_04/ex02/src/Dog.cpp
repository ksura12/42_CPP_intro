/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 17:04:40 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Dog.hpp"
#include "../header/AAnimal.hpp"
#include "../header/Brain.hpp"
#include "../header/colors.h"

Dog::Dog(void) : AAnimal("Dog")
{
	_dog_brain = new Brain;
	std::cout << BLUE << "Dog was made" <<COLOR_DEFAULT << std::endl;
	return;
}

Dog::~Dog(void)
{
	delete _dog_brain;
	std::cout << BLUE << "Dog was destroyed" <<COLOR_DEFAULT << std::endl;
	return;
}

Dog::Dog(Dog const & input) : AAnimal("Dog_copy")
{
	std::cout << BLUE << "Dog-Copy constructor called" <<COLOR_DEFAULT << std::endl;
	*this = input;
	this->_type = input._type + "_copy";
}

Dog const & Dog::operator=(Dog const & input)
{
	std::cout << BLUE << "Dog-Assignment operator called" <<COLOR_DEFAULT << std::endl;
	this->_type = input._type;
	this->_dog_brain = new Brain(*input._dog_brain);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << BLUE <<"Dog: WUFF WUFF" <<COLOR_DEFAULT << std::endl;
	return;
}

std::string	Dog::getIdea(unsigned int index)
{
	return(this->_dog_brain->getIdea(index));
}

void	Dog::setIdea(unsigned int index , std::string idea)
{
	this->_dog_brain->setIdea(index, idea);
	return;
}