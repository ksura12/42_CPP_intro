/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/16 15:42:22 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Hit_points(10), _Energie_points(10), _Attack_damage(0)
{
	std::cout << "Default constructor called fo ClapTrap" << this->_Name << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _Hit_points(10), _Energie_points(10), _Attack_damage(0)
{
	std::cout << "Default constructor called fo ClapTrap" << std::endl;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Claptrap " << this->_Name << " was destroyed" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & input)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = input;
	return;
}

std::string	ClapTrap::get_Name(void) const
{
	return(this->_Name);
}

int	ClapTrap::get_Hit(void) const
{
	return(this->_Hit_points);
}

int	ClapTrap::get_Energie(void) const
{
	return(this->_Energie_points);
}

int	ClapTrap::get_Attack(void) const
{
	return(this->_Attack_damage);
}

ClapTrap & ClapTrap::operator=(ClapTrap const & input)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_Name = input._Name;
	this->_Hit_points = input.get_Hit();
	this->_Energie_points = input.get_Energie();
	this->_Attack_damage = input.get_Attack();
	return (*this);
}

void ClapTrap::attack(const std::string & target)
{
	if (this->_Energie_points > 0 && this->_Hit_points > 0)
	{
		this->_Energie_points--;
		std::cout	<< "ClapTrap " << this->_Name 
			<< " attacked " << target << " and caused "
			<< this->_Attack_damage << " damage"<< std::endl;
	}
	else if (this->_Energie_points <= 0)
		std::cout	<< "ClapTrap " << this->_Name << " tried to attack, but had no energie" << std::endl;
	else
		std::cout	<< "ClapTrap " << this->_Name << " tried to attack, but  is already destroyed" << std::endl;
	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)amount > this->_Hit_points)
		this->_Hit_points = 0;
	else
		this->_Hit_points -= amount;
	std::cout	<< "ClapTrap " << this->_Name 
		<< " has taken " << amount << " of damage"
		<< std::endl;
	if (this->_Hit_points <= 0)
		std::cout	<< "ClapTrap " << this->_Name 
			<< " has to much damage and has been destroyed "
			<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Energie_points > 0 && this->_Hit_points > 0)
	{
		this->_Energie_points--;
		if (amount + _Hit_points >= 10)
			this->_Hit_points = 10;
		else
			this->_Hit_points += amount;
		std::cout	<< "ClapTrap " << this->_Name 
			<< " was repaired by " << amount << " points "
			<< std::endl;
	}
	else if (this->_Energie_points <= 0)
		std::cout	<< "ClapTrap " << this->_Name 
			<< " tried to repair, but had no energie" << std::endl;
	else
		std::cout	<< " ClapTrap " << this->_Name 
			<< " tried to repair, but is already destroyed" << std::endl;
	
}

void	ClapTrap::get_status(void) const
{
	std::cout << "Name: " << this->_Name
		<< "	Hit Points: " << this->_Hit_points
		<< "	Energie points: " << this->_Energie_points
		<< std::endl;
}