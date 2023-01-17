/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 14:08:12 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_H
# define CAT_CLASS_H

#include <iostream>
#include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat(Cat const & input);
		Cat & operator=(Cat const & input);
		Cat(void);
		~Cat(void);

		virtual void	makeSound(void) const;
};

#endif