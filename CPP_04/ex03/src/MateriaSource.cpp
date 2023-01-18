/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/18 12:58:46 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		this->_slot[i] = NULL;
	}
	std::cout << "MateriaSource constructor called" << std::endl;
	return;
}

MateriaSource::MateriaSource(MateriaSource const & input)
{
	*this = input;
	std::cout << "MateriaSource copy constructor called" << std::endl;
	return;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] != NULL)
			delete this->_slot[i];
	}
	std::cout << "MateriaSource was destroyed" << std::endl;
	return;
}

MateriaSource const & MateriaSource::operator=(MateriaSource const & input)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] != NULL)
			this->_slot[i] = input._slot[i]->clone();
		else
			this->_slot[i] = NULL;
	}
	std::cout << "MateriaSource-Assignment operator called" << std::endl;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria * m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] == NULL)
		{
			this->_slot[i] = m;
			m = NULL;
			break;
			std::cout << "MateriaSource learned " << m->getType()
				<< std::endl;
		}
		if (m != NULL)
		{
			std::cout << "MateriaSource tried to learn " << m->getType()
				<<" but slots are full" << std::endl;
			delete m;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] != NULL && this->_slot[i]->getType() == type)
		{
			return (this->_slot[i]->clone());
		}
	}
	return (0);
}