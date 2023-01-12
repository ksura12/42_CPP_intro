/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:28:30 by ksura             #+#    #+#             */
/*   Updated: 2023/01/12 18:07:35 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/HumanB.hpp"


void	HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

void	HumanB::getweapon(Weapon &weapon)
{
	this->_weapon = weapon;
	return;
}

HumanB::HumanB(std::string name) : _name(name)
{
	return;
}

HumanB::~HumanB(void)
{
	std::cout << "Human B was destroyed" << std::endl;
	return;
}