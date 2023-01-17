/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 14:03:21 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_H
# define ANIMAL_CLASS_H

#include <iostream>

class	Animal
{
	protected:
		std::string	_type;

	public:
		Animal(Animal const & input);
		Animal & operator=(Animal const & input);
		Animal(void);
		Animal(std::string type);
		~Animal(void);

		std::string	getType(void) const;
		virtual void	makeSound(void) const;
};

#endif