/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:57:55 by ksura             #+#    #+#             */
/*   Updated: 2023/01/25 16:30:11 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CLASS_HPP
 #define ARRAY_CLASS_HPP
 #include<cstddef>
 #include <iostream>
 #include "colors.h"

template<typename T>
 class	Array
{

		
	public:
		Array();
		Array(unsigned int size);
		Array(Array const & obj);
		Array & operator=(Array const & obj);
		T & operator[](unsigned int index);
		~Array(void);

		unsigned int size();
		
	private:
		T	*			_array;
		unsigned int	_size;
};


template<typename T>
Array<T>::Array()
{
	if (DEBUG)
		std::cout << MAGENTA << "[ARRAY] default constructor called" << std::endl;
	_array = NULL;
	_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int size)
{
	if (DEBUG)
		std::cout << MAGENTA << "[ARRAY] size constructor called" << std::endl;
	_array = new T[size];
	_size = size;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = 0;
}

template<typename T>
Array<T>::Array(Array<T> const & obj) : _size(obj._size)
{
	if (DEBUG)
		std::cout << MAGENTA << "[ARRAY] copy constructor called" << std::endl;
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = obj._array[i];
}

template<typename T>
Array<T> & Array<T>::operator=(Array<T> const & obj)
{
	if (DEBUG)
		std::cout << MAGENTA << "[ARRAY] assignment constructor called" << std::endl;
	if (obj != *this)
		delete [] _array;
	_size = obj._size;
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = obj._array[i];
	return (*this);
}

template<typename T>
Array<T>::~Array(void)
{
	if (DEBUG)
		std::cout << MAGENTA << "[ARRAY] deconstructor called" << std::endl;
	if (_size > 0)
		delete [] _array;
}

template<typename T>
T & Array<T>::operator[](unsigned int index)
{
	if (index > _size)
		throw std::out_of_range("Array::Index out of bounds!");
	return (_array[index]);
}

template<typename T>
unsigned int	Array<T>::size()
{
	return _size;
}

#endif
