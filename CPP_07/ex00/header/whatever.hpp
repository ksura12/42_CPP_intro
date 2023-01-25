/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:35:57 by ksura             #+#    #+#             */
/*   Updated: 2023/01/25 10:52:20 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
 #define WHATEVER_HPP

template<typename T>
const T min(T const & a, T const & b)
{
	return(a < b ? a : b); // condition ? value_if_true : value_if_false
};

template<typename T>
const T max(T const & a, T const & b)
{
	return(a > b ? a : b);
};

template<typename T>
void swap(T & a, T & b)
{
	T tmp = a;
	a = b;
	b = tmp;
};


#endif