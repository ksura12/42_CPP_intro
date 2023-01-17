/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 09:53:40 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_CLASS_H
# define FRAGTRAP_CLASS_H

#include <iostream>
#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{



	public:
		FragTrap(FragTrap const & input);
		FragTrap & operator=(FragTrap const & input);
		FragTrap(std::string name);
		~FragTrap(void);
		
		void	highFivesGuys(void);
		void	attack(const std::string & target);
		void	beRepaired(unsigned int amount);
		void	get_status(void) const;

};

#endif