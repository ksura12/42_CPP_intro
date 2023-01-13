/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:28:30 by ksura             #+#    #+#             */
/*   Updated: 2023/01/13 10:35:44 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/HumanA.hpp"


void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}


HumanA::HumanA(std::string name, Weapon & type) : _name(name), _weapon(type)
{
	return;
}

HumanA::~HumanA(void)
{
	std::cout << "Human A was destroyed" << std::endl;
	return;
}