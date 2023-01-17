/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:24:44 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 19:13:31 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_CLASS_H
# define CURE_CLASS_H
#include "ICharacter.hpp"

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(std::string const & type);
		Cure(Cure const & input);
		~Cure(void);
		Cure & operator=(Cure const & input);

		Cure* 			clone() const;
		void 			use(ICharacter& target);

		std::string		getType() const;
};
#endif
