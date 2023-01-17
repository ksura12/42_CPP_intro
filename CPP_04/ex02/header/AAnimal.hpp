/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 17:01:46 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_CLASS_H
# define AANIMAL_CLASS_H

#include <iostream>

class	AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal(AAnimal const & input);
		AAnimal & operator=(AAnimal const & input);
		AAnimal(void);
		AAnimal(std::string type);
		virtual ~AAnimal(void);

		std::string	getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif