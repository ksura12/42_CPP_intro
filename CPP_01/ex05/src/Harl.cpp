/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/13 13:32:06 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl came in." << std::endl;
	return;
}

Harl::~Harl(void)
{
	std::cout << "Harl left." << std::endl;
	return;
}

void	Harl::complain(std::string level)
{
	
	std::string const level_switch[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for(int i = 0; i < 4; i++)
	{
		if(level == level_switch[i])
			(this->*f[i])();
	}
	
}

void Harl::debug(void)
{
	std::cout << "Debug level:\n"
		<< "I love having extra bacon for my " 
		<< "7XL-double-cheese-triple-pickle-special-ketchup "
		<< "burger.\nI really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Debug level:\n"
		<< "I cannot believe adding extra bacon costs more money. You didn’t put "
		<< "enough bacon in my burger! If you did, "
		<< "I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "Debug level:\n"
		<< "I think I deserve to have some extra bacon for free."
		<< " I’ve been coming for years whereas you started working "
		<< "here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "Debug level:\n"
		<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}