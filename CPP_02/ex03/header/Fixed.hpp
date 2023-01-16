/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/16 11:58:32 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int	_n;
		static const int	_digits = 8;

	public:
		Fixed(Fixed const & input);
		Fixed(const int input);
		Fixed(const float input);
		Fixed(void);
		~Fixed(void);

		Fixed & operator=(Fixed const & input);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator>(Fixed const & input);
		bool operator<(Fixed const & input);
		bool operator>=(Fixed const & input);
		bool operator<=(Fixed const & input);
		bool operator==(Fixed const & input);
		bool operator!=(Fixed const & input);
		
		Fixed operator+(Fixed const & input);
		Fixed operator-(Fixed const & input);
		Fixed operator*(Fixed const & input);
		Fixed operator/(Fixed const & input);

		Fixed operator++(void);
		Fixed operator++(int);
		Fixed operator--(void);
		Fixed operator--(int);
		
		static Fixed & min(Fixed & a, Fixed & b);
		static Fixed const & min(Fixed const & a, Fixed const & b);
		static Fixed & max(Fixed & a, Fixed & b);
		static Fixed const & max(Fixed const & a, Fixed const & b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & input);

#endif