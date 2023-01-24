/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/24 17:02:21 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BASE_CLASS_HPP
# define BASE_CLASS_HPP

#include <iostream>
#include "colors.h"


class	Base
{
	public:
		virtual ~Base();
};

class	A : public Base
{};

class	B : public Base
{};

class	C : public Base
{};

#endif