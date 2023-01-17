/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 15:29:38 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Brain.hpp"
#include "../header/colors.h"

Brain::Brain(void)
{
	for (unsigned int i = 0; i < 100; i++)
	{
		_ideas[i] = "--still no idea--";
	}
	std::cout << MAGENTA << "A Brain was made" << COLOR_DEFAULT << std::endl;
	return;
}

Brain::~Brain(void)
{
	std::cout << MAGENTA << "A Brain was destroyed" << COLOR_DEFAULT << std::endl;
	return;
}

Brain::Brain(Brain const & input)
{
	std::cout << MAGENTA << "Brain-Copy constructor called" << COLOR_DEFAULT << std::endl;
	*this = input;
	return;
}

Brain & Brain::operator=(Brain const & input)
{
	std::cout << MAGENTA << "Brain-Assignment operator called" << COLOR_DEFAULT << std::endl;
	for (unsigned int i = 0; i < 100; i++)
	{
		this->_ideas[i] = input._ideas[i];
	}
	return (*this);
}

std::string	Brain::getIdea(unsigned int index)
{
	return(this->_ideas[index]);
}

void	Brain::setIdea(unsigned int index , std::string idea)
{
	this->_ideas[index] = idea;
	return;
}
