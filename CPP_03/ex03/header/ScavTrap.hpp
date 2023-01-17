/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/16 18:43:23 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKAVTRAP_CLASS_H
# define SKAVTRAP_CLASS_H

#include <iostream>
#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{



	public:
		ScavTrap(ScavTrap const & input);
		ScavTrap & operator=(ScavTrap const & input);
		ScavTrap(std::string name);
		~ScavTrap(void);
		
		void	guardGate();
		void	attack(const std::string & target);
		void	beRepaired(unsigned int amount);
		void	get_status(void) const;

};

#endif