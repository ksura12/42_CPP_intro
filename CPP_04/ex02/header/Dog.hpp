/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 17:03:03 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_H
# define DOG_CLASS_H

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog : public AAnimal
{
	public:
		Dog(Dog const & input);
		Dog const & operator=(Dog const & input);
		Dog(void);
		~Dog(void);

		virtual void	makeSound(void) const;
		void			setIdea(unsigned int index, std::string idea);
		std::string		getIdea(unsigned int index);
		
	private:
		Brain *			_dog_brain;
};

#endif