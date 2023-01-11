/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/11 11:29:26 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/PhoneBook.class.hpp"


int	PhoneBook::addcontact(int index){
	
	contactlist[index].set_contactdetails();
	index++;
	return (index);
}

std::string	PhoneBook::format_contact(std::string str)
{
	std::string	detail;
	int i;
	int i2;

	detail = "          ";
	i = str.length() - 1;
	i2 = 9;
	if (i > 9)
	{
		detail = str.substr(0,9);
		detail.append(".");
	}
	else if (i < 10)
	{
		detail = str;
		while (i2 < 10)
		{
			detail.insert(0, " ");
			i2 = detail.length();
		}
	}
	return (detail);
}

void	PhoneBook::search(int list)
{

	std::string s_first_name;
	std::string s_last_name;
	std::string s_nickname;

	s_first_name = format_contact(contactlist[list].get_contactdetails(1));
	s_last_name = format_contact(contactlist[list].get_contactdetails(2));
	s_nickname = format_contact(contactlist[list].get_contactdetails(3));
	std::cout << "         " << list + 1 << "|" << s_first_name << "|" << s_last_name << "|" << s_nickname << std::endl;
}

void	PhoneBook::all_details(int i)
{
	std::cout << "First Name: " << contactlist[i].get_contactdetails(1) << std::endl;
	std::cout << "Last Name: " << contactlist[i].get_contactdetails(2) << std::endl;
	std::cout << "NickName: " << contactlist[i].get_contactdetails(3) << std::endl;
	std::cout << "Phone Name: " << contactlist[i].get_contactdetails(4) << std::endl;
	std::cout << "Darkest Secret: " << contactlist[i].get_contactdetails(5) << std::endl;
}

PhoneBook::PhoneBook(void) {

	return;
}

PhoneBook::~PhoneBook(void) {
	
	return;
}