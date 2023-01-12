/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/12 18:02:14 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_CLASS_H
# define HUMAN_B_CLASS_H

#include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon		&_weapon;
		std::string	_name;

	public:
		void	attack(void);
		void	getweapon(Weapon &weapon);
		HumanB(std::string name);
		~HumanB(void);
};

#endif