/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:33:16 by ksura             #+#    #+#             */
/*   Updated: 2023/01/13 12:38:28 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

std::string	replace_line(std::string line, std::string to_replace, std::string replacement)
{
	for(int i = 0; i < (int)line.length(); i++)
	{
		if(line.compare(i, to_replace.length(), to_replace) == 0)
		{
			std::string tmp;
			int i2;
			for(i2 = 0; i2 < i; i2++)
			{
				tmp.push_back(line[i2]);
			}
			tmp.append(replacement);
			for (i2 += to_replace.length(); i2 < (int)line.length(); i2++)
			{
				tmp.push_back(line[i2]);
			}
			line = tmp;
		}
	}
	return line;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of Arguments \n Please use: ./ex04 <filename> <toberapalced> <replacement>" << std::endl;
		return 0;
	}
	std::string		to_replace = argv[2];
	std::string		replacement = argv[3];
	std::ifstream	file;
	std::string		line;

	file.open(argv[1]);
	if (file.is_open())
	{
		std::string _new_file = argv[1];
		_new_file.append(".replace");
		std::ofstream new_file(_new_file);

		if (!new_file.is_open())
		{
			std::cout << argv[1] << ".replace could not have been created" << std::endl;
			return 0;
		}
		while(getline(file, line))
		{
			new_file << replace_line(line, to_replace, replacement);
			new_file << std::endl;
		}
		
	}
	else
		std::cout << argv[1] << " could not have been opened" << std::endl;
	return 0;
}