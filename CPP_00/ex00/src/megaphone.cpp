/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/10 12:14:26 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

int	main(int argc, char **argv)
{
	int i;
	int	i2;

	i = 1;
	while(argc > i)
	{
		i2 = 0;
		while(argv[i][i2] != '\0')
		{
			std::cout << (char)toupper(argv[i][i2]);
			i2++;
		}
		i++;
	}
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
	else
		std::cout << std::endl;
	
	return 0;
}