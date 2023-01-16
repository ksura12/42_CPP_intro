/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:50:56 by ksura             #+#    #+#             */
/*   Updated: 2023/01/16 12:08:14 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->_n = 0;
	return;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & input)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = input;
	return;
}

Fixed::Fixed(const int input)
{
	// std::cout << "Integer constructor called" << std::endl;
	this->_n = input << this->_digits;
}

Fixed::Fixed(const float input)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_n = (int)roundf(input * (1 << this->_digits));
}

Fixed & Fixed::operator=(Fixed const & input)
{
	// std::cout << "Assignment operator called" << std::endl;
	this->_n = input.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits function called" << std::endl;
	return(this->_n);
}

void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits function called" << std::endl;
	this->_n = raw;
}

int Fixed::toInt( void ) const
{
	return(this->_n >> this->_digits);
}

float Fixed::toFloat( void ) const
{
	return((float)this->_n / (1 << this->_digits));
}

std::ostream & operator<<(std::ostream & o, Fixed const & input)
{
	o << input.toFloat();
	return(o);
}

bool	Fixed::operator>(Fixed const & input)
{
	if (this->_n > input._n)
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const & input)
{
	if (this->_n < input._n)
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const & input)
{
	if (this->_n >= input._n)
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const & input)
{
	if (this->_n <= input._n)
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const & input)
{
	if (this->_n == input._n)
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const & input)
{
	if (this->_n != input._n)
		return (true);
	return (false);
}

Fixed Fixed::operator+(Fixed const & input)
{
	return(Fixed(this->toFloat() + input.toFloat()));
}

Fixed Fixed::operator++(void)
{
	++(this->_n);
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);
	
	++(this->_n);
	return(tmp);
}

Fixed Fixed::operator-(Fixed const & input)
{
	return(Fixed(this->toFloat() - input.toFloat()));
}

Fixed Fixed::operator--(void)
{
	--(this->_n);
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp(*this);
	
	--(this->_n);
	return(tmp);
}

Fixed Fixed::operator*(Fixed const & input)
{
	return(Fixed(this->toFloat() * input.toFloat()));
}

Fixed Fixed::operator/(Fixed const & input)
{
	return(Fixed(this->toFloat() / input.toFloat()));
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if(a._n < b._n)
		return (a);
	return (b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if(a._n < b._n)
		return (b);
	return (a);
}

Fixed const & Fixed::min(Fixed const & a, Fixed  const & b)
{
	if(a._n < b._n)
		return (a);
	return (b);
}

Fixed const & Fixed::max(Fixed const & a, Fixed  const & b)
{
	if(a._n < b._n)
		return (b);
	return (a);
}