/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:51:30 by ksura             #+#    #+#             */
/*   Updated: 2023/01/24 16:06:57 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include "../header/colors.h"


typedef struct s_Data
{
	std::string		string;
	char			c;
	int				i;
	float			f;
	double			d;
}	Data;

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data * deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main()
{
	Data *	myData = new Data;
	uintptr_t	rawData;
	myData->c = 'z';
	myData->d = 912.46;
	myData->f = 11.22f;
	myData->i = 12345678;
	myData->string = "This is the example string!";

	std::cout << "string	: " << myData->string << std::endl;
	std::cout << "char	: " << myData->c << std::endl;
	std::cout << "int	: " << myData->i << std::endl;
	std::cout << "float	: " << myData->f << std::endl;
	std::cout << "double	: " << myData->d << std::endl;
	std::cout << RED << "pointer to data structure before serialisation " 
		<< &myData << COLOR_DEFAULT << std::endl;

	rawData = serialize(myData);
	std::cout << "serializing done" << std::endl;
	myData = deserialize(rawData);
	std::cout << "deserializing done" << std::endl;
	
	std::cout << RED << "pointer to data structure after deserialisation " 
		<< &myData << COLOR_DEFAULT << std::endl;
	std::cout << "string	: " << myData->string << std::endl;
	std::cout << "char	: " << myData->c << std::endl;
	std::cout << "int	: " << myData->i << std::endl;
	std::cout << "float	: " << myData->f << std::endl;
	std::cout << "double	: " << myData->d << std::endl;
	
	
	delete myData;
	return 0;
}