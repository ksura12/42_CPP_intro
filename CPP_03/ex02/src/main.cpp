/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:33:16 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 10:08:48 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ClapTrap.hpp"
#include "../header/ScavTrap.hpp"
#include "../header/FragTrap.hpp"

#include <iostream>

int main( void ) 
{
	ClapTrap	trapA("Clappy");
	ClapTrap	trapB("Trappy");
	ScavTrap	scavA("Scavvy");
	std::cout << std::endl;
	
	scavA.get_status();
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
	std::cout << std::endl;
	
	scavA.attack(trapA.get_Name());
	trapA.takeDamage(20);
	scavA.beRepaired(20);
	scavA.guardGate();
	scavA.get_status();
	
	std::cout << std::endl;
	std::cout << "--------------------ex02------------------------------" << std::endl;
	std::cout << std::endl;
	
	FragTrap	fragA("Fraggy");
	fragA.get_status();
	std::cout << std::endl;

	fragA.attack(scavA.get_Name());
	scavA.takeDamage(30);
	fragA.highFivesGuys();
	std::cout << std::endl;
	
	FragTrap	fragB("Fraggy2");
	fragB.get_status();
	fragB = fragA;
	fragB.get_status();
	std::cout << std::endl;

	return 0;
}