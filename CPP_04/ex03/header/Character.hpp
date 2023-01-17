/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:12:35 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 20:41:05 by ksura            ###   ########.fr       */
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
		Character(std::string const & name);
		Character(Character const & input);
		Character & operator=(Character const & input);
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
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