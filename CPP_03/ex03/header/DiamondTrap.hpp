/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 10:45:06 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_CLASS_H
# define DIAMONDTRAP_CLASS_H

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap,  public FragTrap
{
	private:
		std::string	_Name;


	public:
		DiamondTrap(DiamondTrap const & input);
		DiamondTrap & operator=(DiamondTrap const & input);
		DiamondTrap(std::string name);
		~DiamondTrap(void);
		
		void	whoAmI();
		void	attack(const std::string & target);
		void	get_status(void) const;

};

#endif