/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 16:53:21 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cat.hpp"
#include "../header/Animal.hpp"
#include "../header/Brain.hpp"
#include "../header/colors.h"

Cat::Cat(void) : Animal("Cat")
{
	_cat_brain = new Brain;
	std::cout << GREEN << "Cat was made" <<COLOR_DEFAULT << std::endl;
	return;
}

Cat::~Cat(void)
{
	delete _cat_brain;
	std::cout << GREEN << "Cat was destroyed" <<COLOR_DEFAULT << std::endl;
	return;
}

Cat::Cat(Cat const & input)
{
	std::cout << GREEN << "Cat-Copy constructor called" <<COLOR_DEFAULT << std::endl;
	*this = input;
	return;
}

Cat & Cat::operator=(Cat const & input)
{
	std::cout << GREEN << "Cat-Assignment operator called" <<COLOR_DEFAULT << std::endl;
	this->_type = input._type;
	this->_cat_brain = new Brain(*input._cat_brain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << GREEN <<"Cat: Miau Miau" <<COLOR_DEFAULT << std::endl;
	return;
}

std::string	Cat::getIdea(unsigned int index)
{
	return(this->_cat_brain->getIdea(index));
}

void	Cat::setIdea(unsigned int index , std::string idea)
{
	this->_cat_brain->setIdea(index, idea);
	return;
}