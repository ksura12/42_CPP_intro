/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 10:00:43 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/FragTrap.hpp"


FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
	this->_Hit_points = 100;
	this->_Energie_points = 100;
	this->_Attack_damage = 30;
	std::cout << "FragTrap " << this->_Name << "was made " << std::endl;
	return;
}


FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_Name << " was destroyed" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const & input)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = input;
	return;
}


FragTrap & FragTrap::operator=(FragTrap const & input)
{
	// std::cout << "Assignment operator called" << std::endl;
	this->_Name = input._Name;
	this->_Hit_points = input.get_Hit();
	this->_Energie_points = input.get_Energie();
	this->_Attack_damage = input.get_Attack();
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (this->_Energie_points > 0)
	{
		this->_Energie_points--;
		std::cout << "FragTrap " << this->_Name
			<< " wants to highFive you Guys!" << std::endl;
	}
	else
		std::cout << "FragTrap " << this->_Name
			<< " tried to highFive you Guys, but is out of energie"
			<< std::endl;
}

void FragTrap::attack(const std::string & target)
{
	if (this->_Energie_points > 0 && this->_Hit_points > 0)
	{
		this->_Energie_points--;
		std::cout	<< "FragTrap " << this->_Name 
			<< " attacked " << target << " and caused "
			<< this->_Attack_damage << " damage"<< std::endl;
	}
	else if (this->_Energie_points <= 0)
		std::cout	<< "FragTrap " << this->_Name 
			<< " tried to attack, but had no energie" << std::endl;
	else
		std::cout	<< "FragTrap " << this->_Name 
			<< " tried to attack, but is already destroyed" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->_Energie_points > 0 && this->_Hit_points > 0)
	{
		this->_Energie_points--;
		if (amount + _Hit_points >= 100)
			this->_Hit_points = 100;
		else
			this->_Hit_points += amount;
		std::cout	<< "FragTrap " << this->_Name 
			<< " was repaired by " << amount << " points "
			<< std::endl;
	}
	else if (this->_Energie_points <= 0)
		std::cout	<< "FragTrap " << this->_Name 
			<< " tried to repair, but had no energie" << std::endl;
	else
		std::cout	<< "FragTrap " << this->_Name 
			<< " tried to repair, but is already destroyed" << std::endl;
}

void	FragTrap::get_status(void) const
{
	std::cout << "FragTrap Name: " << this->_Name
		<< "	Hit Points: " << this->_Hit_points
		<< "	Energie points: " << this->_Energie_points
		<< std::endl;
}