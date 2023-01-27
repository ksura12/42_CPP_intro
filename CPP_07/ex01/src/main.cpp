/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:09:08 by ksura             #+#    #+#             */
/*   Updated: 2023/01/26 19:40:01 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/iter.hpp"
#include "../header/colors.h"
#include <climits>

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };  // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
  Awesome tab2[5];

  iter( tab, 5, print<int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}

// int main()
// {
// 	int			int_array[5] = {42, -42, 1, INT_MIN, INT_MAX};
// 	long		long_array[5] = {42, -42, 1, LONG_MIN, LONG_MAX};
// 	float		float_array[5] = {1.2343, -3.4242, 0.0, -4.2f, 24667.1f};
// 	char		char_array[5] = {'a', 'A', '&', 'Z', '<'};
// 	std::string	string_array[5] = {"This", "is", "the", "best", "ARRAY"};
	
// 	std::cout << GREEN << "---Int Array testing---" << COLOR_DEFAULT << std::endl;
// 	::iter(int_array, sizeof(int_array) / sizeof(int_array[0]), &printing);
// 	std::cout << std::endl;
// 	::iter(int_array, sizeof(int_array) / sizeof(int_array[0]), &increment);
// 	::iter(int_array, sizeof(int_array) / sizeof(int_array[0]), &printing);
// 	std::cout << std::endl;

// 	std::cout << GREEN << "---Long Array testing---" << COLOR_DEFAULT << std::endl;
// 	::iter(long_array, sizeof(long_array) / sizeof(long_array[0]), &printing);
// 	std::cout << std::endl;
// 	::iter(long_array, sizeof(long_array) / sizeof(long_array[0]), &increment);
// 	::iter(long_array, sizeof(long_array) / sizeof(long_array[0]), &printing);
// 	std::cout << std::endl;

// 	std::cout << GREEN << "---Float Array testing---" << COLOR_DEFAULT << std::endl;
// 	::iter(float_array, sizeof(float_array) / sizeof(float_array[0]), &printing);
// 	std::cout << std::endl;
// 	::iter(float_array, sizeof(float_array) / sizeof(float_array[0]), &increment);
// 	::iter(float_array, sizeof(float_array) / sizeof(float_array[0]), &printing);
// 	std::cout << std::endl;

// 	std::cout << GREEN << "---Char Array testing---" << COLOR_DEFAULT << std::endl;
// 	::iter(char_array, sizeof(char_array) / sizeof(char_array[0]), &printing);
// 	std::cout << std::endl;
// 	::iter(char_array, sizeof(char_array) / sizeof(char_array[0]), &increment);
// 	::iter(char_array, sizeof(char_array) / sizeof(char_array[0]), &printing);
// 	std::cout << std::endl;

// 	std::cout << GREEN << "---String Array testing---" << COLOR_DEFAULT << std::endl;
// 	::iter(string_array, sizeof(string_array) / sizeof(string_array[0]), &printing);
// 	std::cout << std::endl;
// 	return 0;
// }

