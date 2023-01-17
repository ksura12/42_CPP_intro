/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 14:08:17 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_H
# define DOG_CLASS_H

#include <iostream>
#include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog(Dog const & input);
		Dog & operator=(Dog const & input);
		Dog(void);
		~Dog(void);

		virtual void	makeSound(void) const;
};

#endif