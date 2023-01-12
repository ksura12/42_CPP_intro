/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:36:54 by ksura             #+#    #+#             */
/*   Updated: 2023/01/12 13:43:47 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int main()
{
	int i = 0;
	Zombie *zombie_horde = zombieHorde(5, "OneOfThose");
	while (i++ < 5)
	{
		zombie_horde[i].announce();
	}
	delete[] zombie_horde;
}