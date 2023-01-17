/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 17:03:06 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_H
# define CAT_CLASS_H

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat : public AAnimal
{
	public:
		Cat(Cat const & input);
		Cat & operator=(Cat const & input);
		Cat(void);
		~Cat(void);

		virtual void	makeSound(void) const;
		void			setIdea(unsigned int index, std::string idea);
		std::string		getIdea(unsigned int index);
	
	private:
		Brain *			_cat_brain;
};

#endif