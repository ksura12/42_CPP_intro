/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:24:28 by ksura             #+#    #+#             */
/*   Updated: 2023/01/24 13:57:25 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../header/Converter.hpp"


int	 main(int const argc, char const **argv)
{
	if (argc != 2)
	{
		std::cout << "Error\nOnly one argument needed.\nchar, int float or double in decimal notation\n";
		return -1;
	}
	Converter	userInput(argv[1]);

	userInput.convert();
	std::cout << userInput;
	return 0;
}