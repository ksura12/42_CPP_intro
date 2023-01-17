/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:33:16 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 14:47:00 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Animal.hpp"
#include "../header/Cat.hpp"
#include "../header/Dog.hpp"
#include "../header/WrongAnimal.hpp"
#include "../header/WrongCat.hpp"

#include <iostream>

int main( void ) 
{
	std::cout << "--------------------ex00 - main test----------------------" << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	std::cout << std::endl;
	std::cout << "--------------------ex00 - WrongAnimal tests----------------------" << std::endl;
	std::cout << std::endl;

	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();
	std::cout << wi->getType() << " " << std::endl;
	wi->makeSound(); //will output the cat sound!
	wmeta->makeSound();
	
	std::cout << std::endl;
	std::cout << "--------------------ex00 - Additional tests----------------------" << std::endl;
	std::cout << std::endl;
	
	const Animal* animal = new Animal();
	std::cout << "Hey, I am a " << animal->getType() << std::endl;
	animal->makeSound();
	std::cout << std::endl;

	const WrongAnimal* wanimal = new WrongAnimal();
	std::cout << "Hey, I am a " << wanimal->getType() << std::endl;
	wanimal->makeSound();
	delete wanimal;
	std::cout << std::endl;
	
	const WrongAnimal* wcatA = new WrongCat();;
	std::cout << "Hey, I am a " << wcatA->getType() << std::endl;
	wcatA->makeSound();
	delete wcatA;
	std::cout << std::endl;
	
	
	return 0;
}