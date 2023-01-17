/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 15:05:19 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H

#include <iostream>

class	Brain
{
	public:
		Brain(Brain const & input);
		Brain & operator=(Brain const & input);
		Brain(void);
		~Brain(void);

		void			setIdea(unsigned int index, std::string idea);
		std::string		getIdea(unsigned int index);

	private:
		std::string _ideas[100];
};

#endif