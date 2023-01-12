/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:36:54 by ksura             #+#    #+#             */
/*   Updated: 2023/01/12 13:36:18 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	int i = 0;
	Zombie *zombie = new Zombie[N];
	while (i++ < N)
		zombie[i].set_name(name);
	return (zombie);
}