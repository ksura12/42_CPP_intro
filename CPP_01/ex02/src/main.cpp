/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:36:54 by ksura             #+#    #+#             */
/*   Updated: 2023/01/12 14:20:03 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value stringPTR is pointing to: " << *stringPTR << std::endl;
	std::cout << "Value stringREF is refering to: " << stringREF << std::endl;
}