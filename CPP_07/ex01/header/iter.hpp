/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:57:55 by ksura             #+#    #+#             */
/*   Updated: 2023/01/25 11:37:01 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
 #define ITER_HPP
 #include<cstddef>
 #include <iostream>
 
template<typename T>
void	iter(T * array, size_t size, void (*f)(T &arg))
{
	if (!array)
		return ;
	for (size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}
};

template<typename T>
void	increment(T & a)
{
	a++;
};

template<typename T>
void	printing(T & a)
{
	std::cout << "[" << a << "] ";
};

#endif
