/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/16 13:20:53 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_CLASS_H
# define POINT_CLASS_H

#include <iostream>
# include <cmath>
# include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	x;
		Fixed const	y;

	public:
		Point(void);
		Point(Point const & input);
		Point(const float a, const float b);
		~Point(void);

		Point & operator=(Point & input);
		Point const & operator=(Point const & input);
		float getX(void) const;
		float getY(void) const;

};

#endif