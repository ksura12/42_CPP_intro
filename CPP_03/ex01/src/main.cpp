/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:33:16 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 10:12:08 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ClapTrap.hpp"
#include "../header/ScavTrap.hpp"


#include <iostream>

int main( void ) 
{
	std::cout << std::endl;
	std::cout << "--------------------ex00------------------------------" << std::endl;
	std::cout << std::endl;
	ClapTrap	trapA("Clappy");
	ClapTrap	trapB("Trappy");
	std::cout << std::endl;
	
	trapA.attack(trapB.get_Name());
	trapB.takeDamage(1);
	trapB.attack(trapA.get_Name());
	trapA.takeDamage(3);
	trapA.attack(trapB.get_Name());
	trapB.takeDamage(4);
	std::cout << std::endl;
	
	trapB.get_status();
	trapB.attack(trapA.get_Name());
	trapA.takeDamage(6);
	trapA.get_status();
	trapA.beRepaired(4);
	trapA.get_status();
	std::cout << std::endl;
	
	trapB.attack(trapA.get_Name());
	trapA.takeDamage(6);
	
	std::cout << std::endl;
	trapA.get_status();
	trapB.get_status();
	
	ClapTrap	trapC("Crappy");
	trapC = trapA;
	trapC.get_status();

	std::cout << std::endl;
	std::cout << "--------------------ex01------------------------------" << std::endl;
	std::cout << std::endl;
	
	ScavTrap	scavA("Scavvy");
	scavA.get_status();
	std::cout << std::endl;
	
	scavA.attack(trapA.get_Name());
	trapA.takeDamage(20);
	scavA.beRepaired(20);
	scavA.guardGate();
	scavA.get_status();
	std::cout << std::endl;

	return 0;
}