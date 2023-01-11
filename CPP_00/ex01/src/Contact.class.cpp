/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/11 11:43:25 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/Contact.class.hpp"

Contact::Contact(void)
{
	return;
}

int is_ascii(std::string str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((int)str[i] > 0 && (int)str[i] <= 127)
			return 1;
		i++;
	}
	return 0;
}

void Contact::enter_first_name(void)
{
	while(1)
	{
		std::cout <<"Please enter your First Name" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(std::cin, first_name);
		if (first_name.length() > 0)
		{
			if(is_ascii(first_name))
				break;
			else
				std::cout << "Please Use Ascii Characters only" << std::endl;
		}
		else
			std::cout << "Please insert your First Name" << std::endl;
	}
	return ;
}

void Contact::enter_last_name()
{
	while(1)
	{
		std::cout <<"Please enter your Last Name" << std::endl;
		getline(std::cin ,last_name);
		if (last_name.length() > 0)
		{
			if(is_ascii(last_name))
				break;
			else
				std::cout << "Please Use Ascii Characters only" << std::endl;
		}
		else
			std::cout << "Please insert your Last Name" << std::endl;
	}
	return ;
}

void Contact::enter_nickname()
{
	while(1)
	{
		std::cout <<"Please enter your Nickname" << std::endl;
		getline(std::cin ,nickname);
		if (last_name.length() > 0)
		{
			if(is_ascii(nickname))
				break;
			else
				std::cout << "Please Use Ascii Characters only" << std::endl;
		}
		else
			std::cout << "Please insert your Nickname" << std::endl;
	}
	return ;
}

void Contact::enter_phone()
{
	while(1)
	{
		std::cout <<"Please enter your Phone number" << std::endl;
		getline(std::cin ,phonenumber);
		if (last_name.length() > 0)
		{
			if(is_ascii(phonenumber))
				break;
			else
				std::cout << "Please Use Ascii Characters only" << std::endl;
		}
		else
			std::cout << "Please insert your Phone number" << std::endl;
	}
	return ;
}

void Contact::enter_secret()
{
	while(1)
	{
		std::cout <<"Please enter your darkest secret" << std::endl;
		getline(std::cin ,darkest_secret);
		if (last_name.length() > 0)
		{
			if(is_ascii(darkest_secret))
				break;
			else
				std::cout << "Please Use Ascii Characters only" << std::endl;
		}
		else
			std::cout << "Please insert your darkest secret" << std::endl;
	}
	return ;
}

void	Contact::set_contactdetails(void)
{
	enter_first_name();
	enter_last_name();
	enter_nickname();
	enter_phone();
	enter_secret();
	return ;
}

std::string	Contact::get_contactdetails(int i)
{
	std::string detail;

	if (i == 1)
		detail = first_name;
	if (i == 2)
		detail = last_name;
	if (i == 3)
		detail = nickname;
	if (i == 4)
		detail = phonenumber;
	if (i == 5)
		detail = darkest_secret;
	return (detail);
}



Contact::~Contact(void)
{
	return;
}