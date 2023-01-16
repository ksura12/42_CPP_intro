/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/16 13:22:44 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area = Fixed(0.5f) *(-b.getX()*c.getX() + a.getY() * (-b.getX() \
		+ c.getX()) + a.getX() * (b.getY() -c.getY()) + b.getX() * c.getY());
	Fixed	s = Fixed(1) / (Fixed(2) * area) * (a.getY() * c.getX() - a.getX() \
		* c.getY() + (c.getY() - a.getY()) * point.getX() + (a.getX() -c.getX()) \
		* point.getY());
	Fixed	t = Fixed(1) / (Fixed(2) * area) * (a.getX() * b.getY() - a.getY() \
		* b.getX() + (a.getY() - b.getY()) * point.getX() + (b.getX() - a.getX())\
		* point.getY());
	
	if (s > 0 && t > 0 && (Fixed(1) - s - t) > 0)
		return (true);
	return (false);
}
