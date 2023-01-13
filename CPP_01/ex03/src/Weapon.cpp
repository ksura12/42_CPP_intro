/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:28:30 by ksura             #+#    #+#             */
/*   Updated: 2023/01/13 10:38:44 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Weapon.hpp"

const std::string&	Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}


Weapon::Weapon(std::string type)
{
	this->type = type;
	return;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon was destroyed" << std::endl;
	return;
}