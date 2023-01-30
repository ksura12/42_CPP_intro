/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:09:08 by ksura             #+#    #+#             */
/*   Updated: 2023/01/30 16:08:16 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/MutantStack.hpp"
#include "../header/colors.h"
#include <iostream>
#include <list>
#include <vector>
// // static void	try_catch_ls(Span const & obj, unsigned int (Span::*f)(void) const);
// // static void	try_catch_ss(Span const & obj, unsigned int (Span::*f)(void) const);
// // static void	try_catch_number(Span & obj, int number);



int main()
{
	{
		std::cout << GREEN << "Mutant stack" << COLOR_DEFAULT << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "first element : " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size of Stack " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;

		std::cout << GREEN << "Printing all elements in order" << COLOR_DEFAULT << std::endl;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}

		MutantStack<int>::reverse_iterator it_r = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite_r = mstack.rend();
		++it_r;
		--it_r;

		std::cout << GREEN << "Printing all elements in reverse order" << COLOR_DEFAULT << std::endl;
		while (it_r != ite_r)
		{
		std::cout << *it_r << std::endl;
		++it_r;
		}

		std::stack<int> s(mstack);

	}
	{
		std::cout << GREEN << "---Comparing with STD::LIST---" << COLOR_DEFAULT << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_front(17);
		std::cout << "first element : " << mstack.front() << std::endl;
		mstack.pop_front();
		std::cout << "size of Stack " << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);


		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;

		std::cout << GREEN << "Printing all elements in order" << COLOR_DEFAULT << std::endl;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}

		std::list<int>::reverse_iterator it_r = mstack.rbegin();
		std::list<int>::reverse_iterator ite_r = mstack.rend();
		++it_r;
		--it_r;

		std::cout << GREEN << "Printing all elements in reverse order" << COLOR_DEFAULT << std::endl;
		while (it_r != ite_r)
		{
		std::cout << *it_r << std::endl;
		++it_r;
		}
		}

		{
		std::cout << GREEN << "---Comparing with STD::VECTOR---" << COLOR_DEFAULT << std::endl;
		std::vector<int> mstack;
		mstack.push_back(5);
		mstack.front() = 17;
		std::cout << "first element : " << mstack.front() << std::endl;
		mstack.front() = 5;
		std::cout << "size of Stack " << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		// mstack.push(0);


		std::vector<int>::iterator it = mstack.begin();
		std::vector<int>::iterator ite = mstack.end();
		++it;
		--it;

		std::cout << GREEN << "Printing all elements in order" << COLOR_DEFAULT << std::endl;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}

		std::vector<int>::reverse_iterator it_r = mstack.rbegin();
		std::vector<int>::reverse_iterator ite_r = mstack.rend();
		++it_r;
		--it_r;

		std::cout << GREEN << "Printing all elements in reverse order" << COLOR_DEFAULT << std::endl;
		while (it_r != ite_r)
		{
		std::cout << *it_r << std::endl;
		++it_r;
		}
	}
	return 0;
}

// int main()
// {
// std::list<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// //[...]
// mstack.push(0);
// std::list<int>::iterator it = mstack.begin();
// std::list<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::stack<int> s(mstack);
// return 0;
// }
