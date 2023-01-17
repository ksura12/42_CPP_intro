/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 10:54:15 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/DiamondTrap.hpp"


DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name +"_clap_name"), FragTrap(name + "_clap_name")
{
	this->_Name = name;
	this->_Hit_points = FragTrap::get_Hit();
	this->_Energie_points = ScavTrap::get_Energie();
	this->_Attack_damage = FragTrap::get_Attack();
	std::cout << "DiamondTrap " << this->_Name << " was made " << std::endl;
	return;
}


DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_Name << " was destroyed" << std::endl;
	return;
}

DiamondTrap::DiamondTrap(DiamondTrap const & input) : ClapTrap(input._Name +"_clap_name")
	, ScavTrap(input._Name + "_clap_name")
	, FragTrap(input._Name + "_clap_name")
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = input;
	return;
}


DiamondTrap & DiamondTrap::operator=(DiamondTrap const & input)
{
	// std::cout << "Assignment operator called" << std::endl;
	this->_Name = input._Name;
	this->_Hit_points = input.get_Hit();
	this->_Energie_points = input.get_Energie();
	this->_Attack_damage = input.get_Attack();
	return (*this);
}

void	DiamondTrap::get_status(void) const
{
	std::cout << "DiamondTrap Name: " << this->_Name
		<< "	Hit Points: " << this->_Hit_points
		<< "	Energie points: " << this->_Energie_points
		<< std::endl;
}

void DiamondTrap::attack(const std::string & target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	if (this->_Energie_points > 0)
	{
		this->_Energie_points--;
		std::cout << "DiamondTrap name: " << this->_Name
			<< " ClapTrap name: " << ClapTrap::get_Name() << std::endl;
	}
	else
		std::cout << "FragTrap " << this->_Name
			<< " tried to highFive you Guys, but is out of energie"
			<< std::endl;
}