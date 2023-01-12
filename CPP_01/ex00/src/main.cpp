/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:45:42 by ksura             #+#    #+#             */
/*   Updated: 2023/01/12 12:00:36 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Zombie.hpp"

int main()
{
	Zombie *zombie(0);
	zombie = zombie->newZombie("FRED");
	zombie->announce();
	delete(zombie);
	zombie = zombie->newZombie("DERF");
	zombie->announce();
	delete(zombie);
	zombie->randomChump("HORST");
}