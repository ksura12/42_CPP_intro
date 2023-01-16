/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/16 12:34:00 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Point.hpp"

Point::Point(void) :x(0), y(0)
{
	return;
}

Point::Point(const float a, const float b) :x(a), y(b)
{
	return;
}

Point::~Point(void)
{
	// std::cout << "Destructor called" << std::endl;
	return;
}

Point::Point(Point const & input): x(input.x), y(input.y)
{
	return;
}

Point & Point::operator=(Point & input)
{
	(void) input;
	return (*this);
}

Point const & Point::operator=(Point const & input)
{
	(void) input;
	return (*this);
}

float	Point::getX(void) const
{
	return(this->x.toFloat());
}

float	Point::getY(void) const
{
	return(this->y.toFloat());
}