/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:12:35 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 19:31:50 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_H
# define CHARACTER_CLASS_H

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{
	public:
		~Character(void);
		Character(std::string const & type);
		Character(Character const & input);
		Character & operator=(Character const & input);
		
		std::string const & getName();
		void equip(AMateria* m) = 0;
		void unequip(int idx) = 0;
		void use(int idx, ICharacter& target);
	
	private:
		Character(void);

		void drop(AMateria * m);
		std::string	_name;
		AMateria * _slot[4];
		AMateria * _floor[4];
		int	_indexFloor;
};

#endif