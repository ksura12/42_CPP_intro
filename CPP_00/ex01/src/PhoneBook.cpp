/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/12 10:59:47 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/PhoneBook.class.hpp"

int check_input(std::string str, int i, int contact_number)
{
	int i2;

	if (str.length() > 1 || str.length() < 1)
		return (1);
	if (!isdigit(str[0]))
		return (1);
	if (contact_number == 8)
	{
		if (str[0] > '8' || str[0] < '1' )
			return 1;
		else
			return (0);
	}
	else
	{
		std::istringstream ( str ) >> i2;
		if (i2 > i || str[0] < '1')
			return (1);
		else
			return (0);
		
	}
}

int	main()
{
	PhoneBook	pbook;
	std::string	command;
	std::string	input;
	int			contact_number;
	int			i;
	int			list;
	int			inumber;

	command = "START";
	i = 0;
	inumber = 0;
	contact_number = 0;
	while (command.compare("EXIT"))
	{
		std::cout << "To Add new Contact enter \"ADD\".\nTo Search for a Contact enter \"SEARCH\".\nTo Exit the Phonebook enter \"EXIT\"" << std::endl;
		getline(std::cin, command);
		if (!command.compare("ADD"))
		{
			i = pbook.addcontact(i);
			if (i > 7)
			{
				i = 0;
				contact_number = 8;
			}
		}
		else if (!command.compare("SEARCH"))
		{
			if (i == 0 && contact_number == 0)
				std::cout << "The crappy Phonebook is empty" << std::endl;
			else
			{
				list = 0;
				inumber = 0;
				while (list < contact_number || list < i)
				{
					pbook.search(list);
					list++;
				}
				while (inumber > list || inumber < 1)
				{
					std::cout << "Please Enter the Index Number: " << std::endl;
					getline(std::cin, input);
					if (!check_input(input, i, contact_number))
						std::istringstream ( input ) >> inumber;
				}
				pbook.all_details(inumber -1);
				list = 0;
				inumber = 0;
			}
		}
	}
	return 0;
}