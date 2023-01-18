/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:33:16 by ksura             #+#    #+#             */
/*   Updated: 2023/01/18 17:14:02 by ksura            ###   ########.fr       */
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
const Point	p1(1,0.1);
const Point	p2(4,0);
const Point	p3(5,0);

std::cout << "The three corners of the triangle are (0/0), (4/0) , (0/4)" << std::endl;
std::cout << "Point p1 = (1/0.1)" << std::endl;
std::cout << "Point p2 =  (4/0) -- corner point" << std::endl;
std::cout << "Point p3 =  (5/0)" << std::endl;
if (bsp(a, b, c, p1))
	std::cout << "The point p1 is inside" << std::endl;
else
	std::cout << "The point p1 is NOT inside" << std::endl;
if (bsp(a, b, c, p2))
	std::cout << "The point p2 is inside" << std::endl;
else
	std::cout << "The point p2 is NOT inside" << std::endl;
if (bsp(a, b, c, p3))
	std::cout << "The point p3 is inside" << std::endl;
else
	std::cout << "The point p3 is NOT inside" << std::endl;
return 0;
}