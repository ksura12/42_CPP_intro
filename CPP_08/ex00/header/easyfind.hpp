/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:35:57 by ksura             #+#    #+#             */
/*   Updated: 2023/01/26 10:53:08 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
 #define EASYFIND_HPP
 
# include <vector>
# include <stdexcept>
# include <algorithm>

template<typename T>
typename T::iterator	easyfind(T & container, int target)
{
	typename T::iterator it = std::find(container.begin(), container.end(), target);
	
	if (it == container.end())
		throw std::invalid_argument("easyfind::Container does not contain target element");
	return (it);
};

#endif