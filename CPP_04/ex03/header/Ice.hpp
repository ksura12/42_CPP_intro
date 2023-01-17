/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:24:44 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 19:09:27 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_CLASS_H
# define ICE_CLASS_H
#include "ICharacter.hpp"

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(std::string const & type);
		Ice(Ice const & input);
		~Ice(void);
		Ice & operator=(Ice const & input);

		Ice* 			clone() const;
		void 			use(ICharacter& target);

		std::string		getType() const;
};
#endif