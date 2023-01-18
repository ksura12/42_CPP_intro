/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:33:16 by ksura             #+#    #+#             */
/*   Updated: 2023/01/18 13:06:07 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AMateria.hpp"
#include "../header/Character.hpp"
#include "../header/Cure.hpp"
#include "../header/Ice.hpp"
#include "../header/MateriaSource.hpp"
#include "../header/colors.h"
#include "../header/IMateriaSource.hpp"

#include <iostream>

int main( void ) 
{

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	// tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	// me->use(1, *bob);
	delete bob;
	// delete me;
	// delete src;
	return 0;
}