/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/16 16:30:00 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

#include <iostream>

class	ClapTrap
{
	protected:
		std::string	_Name;
		int			_Hit_points;
		int			_Energie_points;
		int			_Attack_damage;

	public:
		ClapTrap(ClapTrap const & input);
		ClapTrap & operator=(ClapTrap const & input);
		ClapTrap(void);
		~ClapTrap(void);

		ClapTrap(std::string name);
		void attack(const std::string & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string	get_Name(void) const;
		int			get_Hit(void) const;
		int			get_Energie(void) const;
		int			get_Attack(void) const;
		void		get_status(void) const;

};

#endif