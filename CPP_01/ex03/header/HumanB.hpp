/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/13 10:34:50 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_CLASS_H
# define HUMAN_B_CLASS_H

#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	_name;
		Weapon		*_weapon;

	public:

		HumanB(std::string name);
		void	setWeapon(Weapon & weapon);
		void	attack(void);
		~HumanB(void);
};

#endif