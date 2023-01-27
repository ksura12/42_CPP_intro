/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:52:13 by ksura             #+#    #+#             */
/*   Updated: 2023/01/27 11:33:03 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Span.hpp"
#include "../header/colors.h"

Span::Span(unsigned int N) : _size(N)
{
	if (DEBUG)
		std::cout << YELLOW << "[Span] constructor called" 
			<< COLOR_DEFAULT << std::endl;
	_vector = new std::vector<int>(N);
	if (_vector == NULL)
		throw std::bad_alloc();
	_index = 0;
}

Span::Span()
{
	if (DEBUG)
		std::cout << YELLOW << "[Span] default constructor called" 
			<< COLOR_DEFAULT << std::endl;
}

Span::Span(Span const & obj)
{
	if (DEBUG)
		std::cout << YELLOW << "[Span] copy constructor called" 
			<< COLOR_DEFAULT << std::endl;
	_size = 0;
	*this = obj;
}

Span & Span::operator=(Span const & input)
{
	if (DEBUG)
		std::cout << YELLOW << "[Span] assignmet constructor called" 
			<< COLOR_DEFAULT << std::endl;
	if (this == &input)
		return (*this);
	if (_size > 0)
		delete _vector;
	_size = input._size;
	_index = input._index;
	_vector = new std::vector<int>(_size);
	if (_vector == NULL)
		throw std::bad_alloc();
	for (unsigned int i = 0; i < _size; i++)
		_vector->at(i) = input._vector->at(i);
	return (*this);
}

Span::~Span(void)
{
	if (DEBUG)
		std::cout << YELLOW << "[Span] deconstructor called" 
			<< COLOR_DEFAULT << std::endl;
	delete _vector;
}


void			Span::addNumber(int number)
{
	if (_index == _size)
		throw std::out_of_range("Span::Maximum size reached");
	_vector->at(_index) = number;
	_index++;
}

unsigned int	Span::shortestSpan(void) const
{
	if (_index < 2)
		throw std::logic_error("Span::Not enough elements to compare");
	std::vector<int> vector_copy= *this->_vector;
	std::adjacent_difference(vector_copy.begin(), vector_copy.end(), vector_copy.begin());
	for_each(vector_copy.begin(), vector_copy.end(), Span::absolut);
	vector_copy[0]  = vector_copy[1];
	return (static_cast<unsigned int>(*std::min_element(vector_copy.begin(), vector_copy.end())));
}

unsigned int	Span::longestSpan(void) const
{
	if (_index < 2)
		throw std::logic_error("Span::Not enough elements to compare");
	int min = *std::min_element(_vector->begin(), _vector->end());
	int max = *std::max_element(_vector->begin(), _vector->end());
	return (static_cast<unsigned int>(max - min));
}

void			Span::randomFill(void)
{
	std::srand(time(NULL));
	std::generate(_vector->begin(), _vector->end(), Span::randomNumber);
	_index = _size;
}

void			Span::printElements()
{
	for_each(_vector->begin(), _vector->end(), Span::printElement);
	std::cout << std::endl;
}

void			Span::printElement( int const & number)
{
	std::cout << number << " ";
}

int				Span::randomNumber()
{
	int N = 0;
	
	N = (std::rand() % INT_MAX);
	return (N);
}


void			Span::absolut(int & a)
{
	if (a < 0)
		a = a * (-1);
}