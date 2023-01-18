/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:24:44 by ksura             #+#    #+#             */
/*   Updated: 2023/01/18 13:08:16 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : virtual public IMateriaSource
{
	public:

		MateriaSource(void);
		MateriaSource(MateriaSource const & input);
		MateriaSource const & operator=(MateriaSource const & input);
		~MateriaSource(void);
		
		void learnMateria(AMateria * m);
		AMateria * createMateria(std::string const & type);
	
	private:
		AMateria * _slot[4];
};
#endif