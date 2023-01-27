/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:35:57 by ksura             #+#    #+#             */
/*   Updated: 2023/01/26 17:31:08 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_CLASS_HPP
 #define EASYFIND_CLASS_HPP
 
# include <vector>
# include <iostream>
# include <numeric>
# include <stdexcept>
# include <algorithm>


class	Span
{

		
	public:
		Span(unsigned int N);
		Span(Span const & input);
		Span & operator=(Span const & input);
		~Span(void);

		void			addNumber(int number);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		void			randomFill(void);
		void			printElements();
		
	private:
		Span();
		unsigned int	_size;
		unsigned int	_index;
		std::vector<int> *	_vector;
		static void			absolut(int & a);
		static int			randomNumber();
		static void			printElement( int const & number);
};

#endif