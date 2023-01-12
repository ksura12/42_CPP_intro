/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:28:30 by ksura             #+#    #+#             */
/*   Updated: 2023/01/12 15:08:59 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Weapon.hpp"

const std::string&	Weapon::getType()
{
	const std::string& REF = this->type;
	return (REF);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}


Weapon::Weapon(std::string type)
{
	setType(type);
	return;
}

Weapon::~Weapon(void)
{
	std::cout << "Weappn was destroyed" << std::endl;
	return;
}