/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:35:57 by ksura             #+#    #+#             */
/*   Updated: 2023/01/30 15:12:44 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_CLASS_HPP
 # define MUTANTSTACK_CLASS_HPP
 # include <stack>

template<typename T>
class	MutantStack : public std::stack<T>
{

		
	public:
		MutantStack(void){};
		MutantStack(MutantStack const & input){ *this = input;};
		virtual ~MutantStack(void) {};

		MutantStack & operator=(MutantStack const & input)
		{
			std::stack<T>::operator=(input);
			return (*this);
		}
		
		typedef typename std::stack<T>::container_type::iterator	iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;

		iterator begin(void) {return (std::stack<T>::c.begin()); }
		iterator end(void) {return (std::stack<T>::c.end()); }
		
		reverse_iterator rbegin(void) {return (std::stack<T>::c.rbegin()); }
		reverse_iterator rend(void) {return (std::stack<T>::c.rend()); }

};
#endif