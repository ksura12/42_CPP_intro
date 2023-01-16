/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/16 10:12:23 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>

class	Fixed
{
	private:
		int	_n;
		static const int	_digits = 8;

	public:
		Fixed(Fixed const & input);
		Fixed(void);
		~Fixed(void);

		Fixed & operator=(Fixed const & input);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif