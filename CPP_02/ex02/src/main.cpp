/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:33:16 by ksura             #+#    #+#             */
/*   Updated: 2023/01/18 17:07:48 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Fixed.hpp"



int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << "------------------standard tests ------------------" << std::endl;
std::cout << " a = " << a << std::endl;
std::cout << " ++a = " << ++a << std::endl;
std::cout << " a = " << a << std::endl;
std::cout << " a++ = " << a++ << std::endl;
std::cout << " a = " << a << std::endl;
std::cout << " b = " << b << std::endl;
std::cout << " maximum of a or b: " << Fixed::max( a, b ) << std::endl;
std::cout << " minimum of a or b: " << Fixed::min( a, b ) << std::endl;
std::cout << std::endl;
std::cout << "------------------additional tests ------------------" << std::endl;
std::cout << std::endl;

std::cout << " --a = " << --a << std::endl;
std::cout << " a = " << a << std::endl;
std::cout << " a-- = " << a-- << std::endl;
std::cout << " a = " << a << std::endl;

Fixed c = 3;
std::cout << " c = " << c << std::endl;
std::cout << " c * 2.5f =  " << c * 2.5f << std::endl;
std::cout << " c / 4.2f =  " << c / 4.2f << std::endl;

std::cout << " c + 2.5f =  " << c + 2.5f << std::endl;
std::cout << " c - 1.2f =  " << c - 1.2f << std::endl;
return 0;

}