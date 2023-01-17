/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/16 18:42:07 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
	this->_Hit_points = 100;
	this->_Energie_points = 50;
	this->_Attack_damage = 20;
	std::cout << "ScavTrap " << this->_Name << "was made " << std::endl;
	return;
}


ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_Name << " was destroyed" << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const & input)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = input;
	return;
}


ScavTrap & ScavTrap::operator=(ScavTrap const & input)
{
	// std::cout << "Assignment operator called" << std::endl;
	this->_Name = input._Name;
	this->_Hit_points = input.get_Hit();
	this->_Energie_points = input.get_Energie();
	this->_Attack_damage = input.get_Attack();
	return (*this);
}

void ScavTrap::guardGate(void)
{
	if (this->_Energie_points > 0)
	{
		this->_Energie_points--;
		std::cout << "ScavTrap " << this->_Name
			<< " is in Gate keeper mode" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_Name
			<< " tried to g into Gate keeper mode, but is out of energie"
			<< std::endl;
}

void ScavTrap::attack(const std::string & target)
{
	if (this->_Energie_points > 0 && this->_Hit_points > 0)
	{
		this->_Energie_points--;
		std::cout	<< "SkavTrap " << this->_Name 
			<< " attacked " << target << " and caused "
			<< this->_Attack_damage << " damage"<< std::endl;
	}
	else if (this->_Energie_points <= 0)
		std::cout	<< "SkavTrap " << this->_Name 
			<< " tried to attack, but had no energie" << std::endl;
	else
		std::cout	<< "SkavTrap " << this->_Name 
			<< " tried to attack, but is already destroyed" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_Energie_points > 0 && this->_Hit_points > 0)
	{
		this->_Energie_points--;
		if (amount + _Hit_points >= 100)
			this->_Hit_points = 100;
		else
			this->_Hit_points += amount;
		std::cout	<< "ClapTrap " << this->_Name 
			<< " was repaired by " << amount << " points "
			<< std::endl;
	}
	else if (this->_Energie_points <= 0)
		std::cout	<< "ScavTrap " << this->_Name 
			<< " tried to repair, but had no energie" << std::endl;
	else
		std::cout	<< " ScavTrap " << this->_Name 
			<< " tried to repair, but is already destroyed" << std::endl;
}

void	ScavTrap::get_status(void) const
{
	std::cout << "ScavTrap Name: " << this->_Name
		<< "	Hit Points: " << this->_Hit_points
		<< "	Energie points: " << this->_Energie_points
		<< std::endl;
}