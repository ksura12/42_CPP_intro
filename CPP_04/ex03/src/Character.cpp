/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/18 12:24:05 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Character.hpp"
#include "../header/colors.h"

Character::Character(void)
{
	return ;
}

Character::Character(std::string const & name) : _name(name), _indexFloor(-1)
{
	for (int i = 0; i < 4; i++)
	{
		this->_slot[i] = NULL;
		this->_floor[i] = NULL;
	}
	std::cout << "Character constructor called" << std::endl;
	return ;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] != NULL)
			delete this->_slot[i];
		if (this->_floor[i] != NULL)
			delete this->_floor[i];
	}
	std::cout << "Character was destroyed" << std::endl;
	return ;
}

Character::Character(Character const & input)
{
	std::cout << "Character-Copy constructor called" << std::endl;
	*this = input;
	this->_name = input._name + "_copy";
	return ;
}

Character & Character::operator=(Character const & input)
{
	std::cout << "Cure-Assignment operator called" << std::endl;
	this->_name = input._name + "_assigned";
	for (int i = 0; i < 4; i++)
	{
		if (input._slot[i] != NULL)
			this->_slot[i] = input._slot[i]->clone();
		else
			this->_slot[i] = NULL;
		this->_floor[i] = NULL;
	}
	return (*this);
}

std::string	const & Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria * m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] == NULL)
		{
			this->_slot[i] = m;
			std::cout << this->_name << " equipped " << m->getType() << std::endl;
			m = NULL;
			break;
		}
	}
	if (m != NULL)
	{
		std::cout << this->_name << " tired to equipped " << m->getType()
		<< " but all slots are full " << std::endl;
		this->drop(m);
	}
}

void	Character::unequip(int idx)
{
	if (this->_slot[idx] != NULL)
	{
		std::cout << this->_name << " unequipped " << this->_slot[idx]->getType()
			<< std::endl;
		this->drop(this->_slot[idx]);
		this->_slot[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter & target)
{
	if (this->_slot[idx] != NULL)
	{
		std::cout << this->_name << " ";
		this->_slot[idx]->use(target);

	}
	else
	{
		std::cout << this->_name << " tried to use slot ["<< idx << "] but it is empty"
			<< std::endl;
	}
}

void	Character::drop(AMateria * m)
{
	this->_indexFloor++;
	if (this->_indexFloor == 4)
	{
		this->_indexFloor = 0;
		delete this->_floor[0];
	}
	this->_floor[this->_indexFloor] = m;
	std::cout << m->getType() << " dropped to floor[" << this->_indexFloor
		<< "]" << std::endl;
}
