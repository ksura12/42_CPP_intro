/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:33:16 by ksura             #+#    #+#             */
/*   Updated: 2023/01/16 13:21:50 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Fixed.hpp"
#include "../header/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
const Point	a(0,0);
const Point	b(4,0);
const Point	c(0,4);
const Point	point(1,0.1);

if (bsp(a, b, c, point))
	std::cout << "The point is inside" << std::endl;
else
	std::cout << "The point is NOT inside" << std::endl;
return 0;
}