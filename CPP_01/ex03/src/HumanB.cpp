/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:28:30 by ksura             #+#    #+#             */
/*   Updated: 2023/01/13 10:36:38 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/HumanB.hpp"


void	HumanB::attack()
{
	std::cout << this->_name << " attacks with their ";
	if(_weapon)
		std::cout << this->_weapon->getType() << std::endl;
	else
		std::cout << "hands" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon_type)
{
	this->_weapon = &weapon_type;
	return;
}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	return;
}

HumanB::~HumanB(void)
{
	std::cout << "Human B was destroyed" << std::endl;
	return;
}