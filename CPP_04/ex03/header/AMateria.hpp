/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:24:44 by ksura             #+#    #+#             */
/*   Updated: 2023/01/18 11:19:15 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_CLASS_H
# define AMATERIA_CLASS_H
#include "ICharacter.hpp"

#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
	
	private:
		AMateria(void);

	public:
		AMateria(std::string const & type);
		AMateria(AMateria const & input);
		virtual ~AMateria(void);
		AMateria & operator=(AMateria const & input);
		
		std::string const & 	getType() const; //Returns the materia type
		virtual AMateria* 		clone() const = 0;
		virtual void 			use(ICharacter& target);
};
#endif