/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:33:16 by ksura             #+#    #+#             */
/*   Updated: 2023/01/16 15:42:03 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ClapTrap.hpp"



#include <iostream>

int main( void ) 
{
	ClapTrap	trapA("Clappy");
	ClapTrap	trapB("Trappy");

	trapA.attack(trapB.get_Name());
	trapB.takeDamage(1);
	trapB.attack(trapA.get_Name());
	trapA.takeDamage(3);
	trapA.attack(trapB.get_Name());
	trapB.takeDamage(4);

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

	return 0;
}