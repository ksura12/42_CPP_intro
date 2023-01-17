/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:33:16 by ksura             #+#    #+#             */
/*   Updated: 2023/01/17 17:13:25 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AAnimal.hpp"
#include "../header/Cat.hpp"
#include "../header/Dog.hpp"
#include "../header/WrongAnimal.hpp"
#include "../header/WrongCat.hpp"

#include <iostream>

int main( void ) 
{
	std::cout << "--------------------ex01 - making array----------------------" << std::endl;
	unsigned int array_size = 10;
	AAnimal *	shelter[array_size];
	
	for (unsigned int i = 0; i < array_size / 2; i++)
	{
		shelter[i] = new Dog();
		shelter[i + (array_size / 2)] = new Cat();
	}
	
	std::cout << std::endl;
	std::cout << "-------ex01 - making an animal-------" << std::endl;
	std::cout << std::endl;

	// Animal * animal = new Animal;
	// std::cout << "Hey, I am a " << animal->getType() << std::endl;
	// animal->makeSound();
	// delete animal;
	
	// its not working, because its an abstract class now

	std::cout << std::endl;
	std::cout << "-------ex01 - testing dogs and brains-------" << std::endl;
	std::cout << std::endl;
	
	Dog* dog = new Dog;
	std::cout << "Hey, I am a " << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << "I think of " << dog->getIdea(0) << std::endl;
	std::cout << "My new idea is : Eating sausages " << std::endl;
	dog->setIdea(0, "Eating sausages");
	std::cout << "I remember my idea again: " << dog->getIdea(0) << std::endl;
	Dog * dog_copy = new Dog(*dog);

	std::cout << "Hey, I am a " << dog_copy->getType() << std::endl;
	std::cout << "I think of " << dog_copy->getIdea(0) << std::endl;
	std::cout << "My new idea is : Playing " << std::endl;
	dog_copy->setIdea(1, "Playing");
	std::cout << "I remember my idea again: " << dog_copy->getIdea(0) << std::endl;
	std::cout << "My ideas are: " << dog_copy->getIdea(0) << " and " << dog_copy->getIdea(1)<< std::endl;
	delete	dog_copy;
	delete	dog;

		std::cout << std::endl;
	std::cout << "-------ex01 - testing cats and brains-------" << std::endl;
	std::cout << std::endl;
	
	Cat* cat = new Cat;
	cat->makeSound();
	std::cout << "Hey, I am a " << cat->getType() << std::endl;
	std::cout << "I think of " << cat->getIdea(0) << std::endl;
	std::cout << "My new idea is : Eating fish " << std::endl;
	cat->setIdea(0, "Eating fish");
	std::cout << "I remember my idea again: " << cat->getIdea(0) << std::endl;
	Cat * cat_copy = new Cat(*cat);

	std::cout << "Hey, I am a " << cat_copy->getType() << std::endl;
	std::cout << "I think of " << cat_copy->getIdea(0) << std::endl;
	std::cout << "My new idea is : Playing catch" << std::endl;
	cat_copy->setIdea(1, "Playing catch");
	std::cout << "I remember my idea again: " << cat_copy->getIdea(0) << std::endl;
	std::cout << "My ideas are: " << cat_copy->getIdea(0) << " and " << cat_copy->getIdea(1)<< std::endl;
	delete	cat_copy;
	delete	cat;

	std::cout << std::endl;
	std::cout << "-------ex01 - destroying animals and brains-------" << std::endl;
	std::cout << std::endl;
	for (unsigned int i = 0; i < array_size; i++)
	{
		delete shelter[i];
	}
	return 0;
}